simde_test_x86_tests = [
  'mmx',
  'sse',
  'sse2',
  'sse3',
  'ssse3',
  'sse4.1',
  'sse4.2',
  'avx',
  'avx2',
  'fma',
  'gfni',
  'clmul',
  'svml',
  'xop'
]

subdir('avx512')

simde_test_x86_sources = []
simde_test_x86_libs = []
foreach name : simde_test_x86_tests
  foreach lang : ['c', 'cpp']
    source_file = name + '.c'
    if lang == 'cpp'
      source_file = configure_file(input: name + '.c', output: name + '.cpp', copy: true)
    endif
    simde_test_x86_sources += source_file

    foreach emul : ['emul', 'native']
      extra_flags = ['-DSIMDE_TEST_BARE']
      if emul == 'emul'
        extra_flags += '-DSIMDE_NO_NATIVE'
      endif

      x = executable(name + '-' + emul +  '-' + lang, source_file,
          c_args: simde_c_args + simde_c_defs + simde_native_c_flags + extra_flags,
          cpp_args: simde_c_args + simde_c_defs + simde_native_c_flags + extra_flags,
          include_directories: simde_include_dir,
          dependencies: simde_deps)

      test('x86/' + name + '/' + emul + '/' + lang, x,
          protocol: 'tap',
          # Emscripten tests must be run from builddir
          workdir: meson.current_build_dir())
    endforeach
  endforeach
endforeach
