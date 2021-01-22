# -*- Python -*-
# Drone CI Starlark configuration file.
# https://docs.drone.io/pipeline/scripting/starlark/
# Run `drone starlark convert --stdout` to verify `.drone.star`.

def main(ctx):
  jobs = []

  for arch in ['aarch64', 'armv8', 'armv7']:
    drone_arch = 'arm'
    if arch == 'aarch64':
      drone_arch = 'arm64'

    for compiler in ['gcc', 'clang']:
      cc = compiler
      cxx = compiler + '++'
      compiler_flags = []
      packages = ['ninja-build', 'git-core', 'python3-pip', 'gcovr']

      if arch == 'armv7':
        compiler_flags.extend(['-march=armv7-a', '-mfpu=neon'])
      elif arch == 'armv8':
        compiler_flags.extend(['-march=armv8-a', '-mfpu=neon'])
      elif arch == 'aarch64':
        compiler_flags.extend(['-march=armv8-a+simd+crypto+crc'])

      if compiler == 'gcc':
        cxx = 'g++'
        compiler_flags.extend(['-Wextra', '-Werror'])
        packages.extend(['gcc', 'g++'])
      elif compiler == 'clang':
        compiler_flags.extend(['-Weverything', '-Werror'])
        packages.extend(['clang'])

      cflags = ' '.join(compiler_flags)
      cxxflags = ' '.join(compiler_flags)

      environment = {
        "CC": cc,
        "CXX": cxx,
        "CFLAGS": cflags,
        "CXXFLAGS": cxxflags,
        "DEBIAN_FRONTEND": "noninteractive",
      }

      exclude_branches = ['master']
      for provider in ['gha', 'cirrus', 'semaphore', 'circleci', 'appveyor', 'azure', 'travis']:
        exclude_branches.append('ci/' + provider)
        exclude_branches.append('ci/' + provider + '/**')

      jobs.append({
        "kind": "pipeline",
        "type": "docker",
        "name": compiler + ' ' + arch,
        "platform": {
          "os": "linux",
          "arch": drone_arch
        },
        "steps": [
          {
            "name": "test",
            "image": "ubuntu:bionic",
            "environment": environment,
            "commands": [
              "cat /proc/cpuinfo",
              "apt-get update -y",
              "apt-get install -y " + " ".join(packages),
              "pip3 install meson",
              "meson build -Db_coverage=true || (cat build/meson-logs/meson-log.txt; false)",
              "ninja -C build -v test",
            ],
          }
        ],
        "trigger": {
          "branch": {
            "exclude": exclude_branches
          }
        },
      })

  # jobs.append({
  #   "kind": "pipeline",
  #   "type": "docker",
  #   "name": "native aliases",
  #   "platform": {
  #     "os": "linux",
  #     "arch": "arm64"
  #   },
  #   "steps": [
  #     {
  #       "name": "test",
  #       "image": "ubuntu:bionic",
  #       "environment": {
  #         "CC": "clang",
  #         "CXX": "clang++",
  #         "CFLAGS": "-march=armv8a+simd+crypto+crc -Weverything -Wextra -DSIMDE_ENABLE_NATIVE_ALIASES -DSIMDE_NATIVE_ALIASES_TESTING",
  #         "CXXFLAGS": "-march=armv8a+simd+crypto+crc -Weverything -Wextra -DSIMDE_ENABLE_NATIVE_ALIASES -DSIMDE_NATIVE_ALIASES_TESTING",
  #       "DEBIAN_FRONTEND": "noninteractive",
  #       },
  #       "commands": [
  #         "cat /proc/cpuinfo",
  #         "apt-get update -y",
  #         "apt-get install -y " + " ".join(['ninja-build', 'git-core', 'python3-pip', 'gcovr', 'clang', 'curl']),
  #         "pip3 install meson",
  #         "(cd test && sh -x ./native-aliases.sh)",
  #         "meson build -Db_coverage=true",
  #         "ninja -C build -v test",
  #       ],
  #     },
  #   ],
  #   "trigger": {
  #     "branch": {
  #       "exclude": exclude_branches
  #     }
  #   }
  # })

  return jobs
