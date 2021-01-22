cmake_minimum_required(VERSION 3.0)

project(simde-tests)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include (ExtraWarningFlags)

enable_testing()

option(BUILD_CPP_TESTS "Build C++ tests" ON)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/munit/munit.c")
  find_program(GIT git)
  if(GIT)
    execute_process(COMMAND ${GIT} submodule update --init --recursive)
  else()
    message (FATAL_ERROR "It looks like you don't have submodules checked out.  Please run `git submodule update --init --recursive'")
  endif()
endif()

if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "Debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Coverage")
  set(orig_req_libs "${CMAKE_REQUIRED_LIBRARIES}")
  set(CMAKE_REQUIRED_LIBRARIES "${CMAKE_REQUIRED_LIBRARIES};--coverage")
  check_c_compiler_flag("--coverage" CFLAG___coverage)
  set(CMAKE_REQUIRED_LIBRARIES "${orig_req_libs}")

  if(CFLAG___coverage)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_C_FLAGS} --coverage")
    add_definitions("-DSIMDE_NO_INLINE")
  else()
    set(CMAKE_BUILD_TYPE "Debug")
  endif()
endif()

add_library(munit STATIC munit/munit.c)

include(CheckSymbolExists)
check_symbol_exists(clock_gettime "time.h" CLOCK_GETTIME_RES)
if(CLOCK_GETTIME_RES)
  set(CLOCK_GETTIME_EXISTS yes)
else()
  set(orig_req_libs "${CMAKE_REQUIRED_LIBRARIES}")
  set(CMAKE_REQUIRED_LIBRARIES "${CMAKE_REQUIRED_LIBRARIES};rt")

  check_symbol_exists(clock_gettime "time.h" CLOCK_GETTIME_LIBRT_RES)
  if(CLOCK_GETTIME_LIBRT_RES)
    set(CLOCK_GETTIME_EXISTS yes)
    set(CLOCK_GETTIME_LIBRARY "rt")
  endif()

  set(CMAKE_REQUIRED_LIBRARIES "${orig_req_libs}")
  unset(orig_req_libs)
endif()

check_symbol_exists(fegetround "fenv.h" FEGETROUND_EXISTS)
if(NOT FEGETROUND_EXISTS)
  unset(FEGETROUND_EXISTS CACHE)
  list(APPEND CMAKE_REQUIRED_LIBRARIES m)
  check_symbol_exists(fegetround "fenv.h" FEGETROUND_EXISTS)
  if(FEGETROUND_EXISTS)
    set(NEED_LIBM True)
  else()
    message(FATAL_ERROR "Unable to find fegetround")
  endif()
endif(NOT FEGETROUND_EXISTS)

set_property(TARGET munit PROPERTY C_STANDARD "99")
if("${CLOCK_GETTIME_EXISTS}")
  target_compile_definitions(munit PRIVATE "MUNIT_ALLOW_CLOCK_GETTIME")
  target_link_libraries(munit "${CLOCK_GETTIME_LIBRARY}")
endif()

if("${OPENMP_SIMD_FLAGS}" STREQUAL "")
  foreach(omp_simd_flag "-fopenmp-simd" "-qopenmp-simd")
    string (REGEX REPLACE "[^a-zA-Z0-9]+" "_" omp_simd_flag_name "CFLAG_${omp_simd_flag}")
    check_c_compiler_flag("${omp_simd_flag}" "${omp_simd_flag_name}")

    if(${omp_simd_flag_name})
      set(OPENMP_SIMD_FLAGS "-DSIMDE_ENABLE_OPENMP ${omp_simd_flag}")
      break()
    endif()
  endforeach()
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OPENMP_SIMD_FLAGS}")

if("${CMAKE_C_COMPILER_ID}" STREQUAL "Intel")
  add_definitions(-DSIMDE_FAST_MATH)
endif()

aux_source_directory("arm/neon" ARM_NEON_SOURCES_C)
list(REMOVE_ITEM ARM_NEON_SOURCES_C "arm/neon/run-tests.c")
list(REMOVE_ITEM ARM_NEON_SOURCES_C "arm/neon/skel.c")
list(REMOVE_ITEM ARM_NEON_SOURCES_C "arm/neon/skel-single.c")
list(REMOVE_ITEM ARM_NEON_SOURCES_C "arm/neon/skel-triple.c")

aux_source_directory("x86/avx512" X86_AVX512_SOURCES_C)
list(REMOVE_ITEM X86_AVX512_SOURCES_C "x86/avx512/run-tests.c")
list(REMOVE_ITEM X86_AVX512_SOURCES_C "x86/avx512/skel.c")

aux_source_directory("x86" X86_SOURCES_C)
list(REMOVE_ITEM X86_SOURCES_C "x86/skel.c")
list(REMOVE_ITEM X86_SOURCES_C "x86/run-tests.c")

set(TEST_SOURCES_C
  ${X86_SOURCES_C}
  ${X86_AVX512_SOURCES_C}
  ${ARM_NEON_SOURCES_C})

set(TEST_RUNNER_SOURCES
  run-tests.c
  x86/run-tests.c
  x86/avx512/run-tests.c
  arm/run-tests.c
  arm/neon/run-tests.c)
add_executable(run-tests ${TEST_RUNNER_SOURCES})
set_property(TARGET run-tests PROPERTY C_STANDARD "99")
target_add_compiler_flags(run-tests "-Wno-psabi")

target_link_libraries(run-tests munit)
target_add_compiler_flags (munit "-w")
if(NEED_LIBM)
  target_link_libraries(run-tests m)
endif(NEED_LIBM)

set(TEST_SOURCES_CPP)
if(BUILD_CPP_TESTS)
  foreach(csource ${TEST_SOURCES_C})
    configure_file("${csource}" "${CMAKE_CURRENT_BINARY_DIR}/${csource}pp")
    list(APPEND TEST_SOURCES_CPP "${CMAKE_CURRENT_BINARY_DIR}/${csource}pp")

    get_filename_component(DIR "${csource}" DIRECTORY)
    set_property(SOURCE "${CMAKE_CURRENT_BINARY_DIR}/${csource}pp" APPEND PROPERTY COMPILE_FLAGS " -I${CMAKE_CURRENT_SOURCE_DIR}/${DIR}")
  endforeach()

  add_definitions(-DSIMDE_BUILD_CPP_TESTS)
endif(BUILD_CPP_TESTS)

foreach(native native emul)
  add_library(simde-test-${native} STATIC ${TEST_SOURCES_C} ${TEST_SOURCES_CPP})

  target_include_directories(simde-test-${native} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/..")
  set_property(TARGET simde-test-${native} PROPERTY C_STANDARD "99")

  target_link_libraries(run-tests simde-test-${native})
  target_add_compiler_flags(simde-test-${native} "-Wno-psabi")
endforeach(native native emul)
target_compile_definitions(simde-test-emul PRIVATE SIMDE_NO_NATIVE)

foreach(src ${TEST_SOURCES_C})
  string(REGEX REPLACE "^(.+)\\.c$" "/\\1" TEST_NAME "${src}")
  add_test(NAME "${TEST_NAME}" COMMAND $<TARGET_FILE:run-tests> "${TEST_NAME}")
endforeach(src ${TEST_SOURCES_C})

message(WARNING
        "CMake support is deprecated; please use Meson instead.  CMake is only present "
        "for compilers which Meson doesn't yet support (e.g., xlc) and platforms where "
        "difficult to run an up-to-date copy of Meson (e.g., Ubuntu 12.04).")
