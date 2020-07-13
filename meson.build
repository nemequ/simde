project('SIMDe', 'c', 'cpp',
        default_options: ['c_std=c99'],
        license: 'MIT',
        version: '0.5.0')

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')

if not meson.is_subproject() and get_option('tests')
  subdir('test')
endif

if not meson.is_subproject()
  install_headers(
    files([
      'simde/check.h',
      'simde/debug-trap.h',
      'simde/hedley.h',
      'simde/simde-arch.h',
      'simde/simde-common.h',
      'simde/simde-constify.h',
      'simde/simde-detect-clang.h',
      'simde/simde-diagnostic.h',
      'simde/simde-features.h',
      'simde/simde-math.h',
      ]),
    subdir: 'simde')

  install_headers(
    files([
      'simde/x86/avx2.h',
      'simde/x86/avx512bw.h',
      'simde/x86/avx512cd.h',
      'simde/x86/avx512dq.h',
      'simde/x86/avx512f.h',
      'simde/x86/avx512vl.h',
      'simde/x86/avx.h',
      'simde/x86/fma.h',
      'simde/x86/gfni.h',
      'simde/x86/mmx.h',
      'simde/x86/sse2.h',
      'simde/x86/sse3.h',
      'simde/x86/sse4.1.h',
      'simde/x86/sse4.2.h',
      'simde/x86/sse.h',
      'simde/x86/ssse3.h',
      'simde/x86/svml.h',
      ]),
    subdir: 'simde/x86')

  install_headers(
    files([
      'simde/arm/neon.h',
      ]),
    subdir: 'simde/arm')

  install_headers(
    files([
      'simde/arm/neon/abs.h',
      'simde/arm/neon/add.h',
      'simde/arm/neon/addl.h',
      'simde/arm/neon/addw.h',
      'simde/arm/neon/and.h',
      'simde/arm/neon/bsl.h',
      'simde/arm/neon/cagt.h',
      'simde/arm/neon/ceq.h',
      'simde/arm/neon/ceqz.h',
      'simde/arm/neon/cge.h',
      'simde/arm/neon/cgez.h',
      'simde/arm/neon/cgt.h',
      'simde/arm/neon/cgtz.h',
      'simde/arm/neon/cle.h',
      'simde/arm/neon/clez.h',
      'simde/arm/neon/clt.h',
      'simde/arm/neon/cltz.h',
      'simde/arm/neon/combine.h',
      'simde/arm/neon/dup_n.h',
      'simde/arm/neon/eor.h',
      'simde/arm/neon/get_high.h',
      'simde/arm/neon/get_lane.h',
      'simde/arm/neon/get_low.h',
      'simde/arm/neon/ld1.h',
      'simde/arm/neon/max.h',
      'simde/arm/neon/min.h',
      'simde/arm/neon/mla.h',
      'simde/arm/neon/mlal.h',
      'simde/arm/neon/mlal_high.h',
      'simde/arm/neon/movl.h',
      'simde/arm/neon/movl_high.h',
      'simde/arm/neon/movn.h',
      'simde/arm/neon/mul.h',
      'simde/arm/neon/mull.h',
      'simde/arm/neon/mvn.h',
      'simde/arm/neon/neg.h',
      'simde/arm/neon/orr.h',
      'simde/arm/neon/padal.h',
      'simde/arm/neon/padd.h',
      'simde/arm/neon/paddl.h',
      'simde/arm/neon/pmax.h',
      'simde/arm/neon/pmin.h',
      'simde/arm/neon/qadd.h',
      'simde/arm/neon/qmovn.h',
      'simde/arm/neon/qmovn_high.h',
      'simde/arm/neon/qshl.h',
      'simde/arm/neon/reinterpret.h',
      'simde/arm/neon/rshr_n.h',
      'simde/arm/neon/rsra_n.h',
      'simde/arm/neon/shl.h',
      'simde/arm/neon/shl_n.h',
      'simde/arm/neon/shr_n.h',
      'simde/arm/neon/sra_n.h',
      'simde/arm/neon/st1.h',
      'simde/arm/neon/st1_lane.h',
      'simde/arm/neon/sub.h',
      'simde/arm/neon/trn1.h',
      'simde/arm/neon/trn2.h',
      'simde/arm/neon/trn.h',
      'simde/arm/neon/tst.h',
      'simde/arm/neon/types.h',
      'simde/arm/neon/uzp1.h',
      'simde/arm/neon/uzp2.h',
      'simde/arm/neon/uzp.h',
      'simde/arm/neon/zip1.h',
      'simde/arm/neon/zip2.h',
      'simde/arm/neon/zip.h',
      ]),
    subdir: 'simde/arm/neon')

  import('pkgconfig').generate(
    version : meson.project_version(),
    name : 'SIMDe',
    filebase : 'simde',
    description : 'Portable SIMD wrapper library')
endif

simde_dep = declare_dependency(
  include_directories : include_directories('.'),
  version : meson.project_version())
