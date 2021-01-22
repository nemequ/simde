cc = meson.get_compiler('c')
libm = cc.find_library('m', required : false)

simde_c_defs = []
simde_cxx_defs = []
simde_c_args = []
simde_cxx_args = []
simde_deps = [libm]

if get_option('sleef').enabled() or meson.get_external_property('sleef', false)
  sleef = cc.find_library('sleef', required: true)
  simde_deps += sleef
  simde_c_defs = ['-DSIMDE_MATH_SLEEF_ENABLE']
  simde_cxx_defs = ['-DSIMDE_MATH_SLEEF_ENABLE']
endif

c_openmp_simd = false
cxx_openmp_simd = false
foreach omp_arg : ['-fopenmp-simd', '-qopenmp-simd']
  if (not c_openmp_simd) and cc.has_argument(omp_arg)
    simde_c_args += omp_arg
    simde_c_defs += '-DSIMDE_ENABLE_OPENMP'
    c_openmp_simd = true
  endif

  if (not cxx_openmp_simd) and cxx.has_argument(omp_arg)
    simde_cxx_args += omp_arg
    simde_cxx_defs += '-DSIMDE_ENABLE_OPENMP'
    cxx_openmp_simd = true
  endif
endforeach

simde_native_c_flags = []
if cc.has_argument('-Wpsabi')
  simde_native_c_flags += '-Wno-psabi'
endif
# if cc.has_argument('-march=native+simd')
#   simde_native_c_flags += '-march=native+simd'
# elif cc.has_argument('-march=native')
#   simde_native_c_flags += '-march=native'
# endif

if cc.get_id() == 'intel'
  simde_native_c_flags += '-DSIMDE_FAST_MATH'
endif

simde_native_cxx_flags = []
if cxx.has_argument('-Wpsabi')
  simde_native_cxx_flags += '-Wno-psabi'
endif
# if cxx.has_argument('-march=native+simd')
#   simde_native_cxx_flags += '-march=native+simd'
# elif cxx.has_argument('-march=native')
#   simde_native_cxx_flags += '-march=native'
# endif

if cxx.get_id() == 'intel'
  simde_native_cxx_flags += '-DSIMDE_FAST_MATH'
endif

if not c_openmp_simd
  simde_deps += dependency('openmp', required: false)
endif

simde_deps += cc.find_library('m', required: false)

simde_include_dir = include_directories('..')

subdir('common')
subdir('x86')
subdir('arm')
