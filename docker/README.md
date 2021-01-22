# SIMDe Development Container

The basic idea is to set up a Debian system with lots of different
compilers and emulators for different architectures and configure
multiple builds in different directories.

Note that there are also several docker files in the test/
subdirectory.  These can be used to test other operating systems,
especially older compilers which aren't supported on Debian testing
anymore.

To use this, just run the `simde-dev.sh` script and go grab ~a cup of
coffee~ lunch (it will take a while, and download a *lot* of packages).
Once the container is ready it will drop you into a bash shell in
`/opt/simde`; this is the build directory.

This will bind the parent directory (the root of the SIMDe checkout)
to `/usr/local/src/simde`; any changes to either will propogate to the
other, meaning you can continue using your normal development
environment and just re-run ninja in the container to (re)build SIMDe.

If you would like build directories to persist across multiple
invocations of `simde-dev.sh`, you can set the `PERSISTENT_BUILD_DIR`
to a directory on the host filesystem and it will be mapped to
`/opt/simde` in the container.

Once your container is finished building, just `simde-reset-build.sh`
and it should be populated with a bunch of subdirectories which you can
build with ninja.  For example, `ninja -C gcc-10` will build SIMDe
using GCC 10.  If you want to run the tests, `ninja -C gcc-10 test`
(or `cd gcc-10 && ninja test`).

You can also run `simde-reset-build.sh build-name` to (re)generate a
single build.

# Debian Version

By default, we use Debian testing.  If you would like to use Debian
unstable instead, just run `simde-dev.sh unstable`.

## Altering or Adding Builds

Each build has an associated Meson cross file (see the `cross-files/`
subdirectory).  We kind of abuse these by adding flags like `-Wextra`,
`-Werror`, `-march=...`, *etc.*, which aren't really about
cross-compilation.  However, you can add or remove C/C++ flags in the
cross files, or if you want to *add* flags you can just put them in
the `CFLAGS`/`CXXFLAGS` environment variables and reconfigure the
build.  You can also create a new cross file with your preferred
configuration.
