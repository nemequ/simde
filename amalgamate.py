#!/usr/bin/python3

# amalgamate.py
# Written by Evan Nemerson <evan@nemerson.com>
#
# To the extent possible under law, the author(s) have dedicated all
# copyright and related and neighboring rights to this software to
# the public domain worldwide. This software is distributed without
# any warranty.
#
# For details, see <http://creativecommons.org/publicdomain/zero/1.0/>.
# SPDX-License-Identifier: CC0-1.0

# Quick and dirty script to amalgamate C into a single file.  Includes
# using angle brackets (#include <foo.h>) will be preserved, but for
# includes using double quotes (#include "foo.h") the file will be
# included by this script.
#
# If you make any improvements please report them in the SIMDe issue
# tracker at <https://github.com/simd-everywhere/simde/issues> or
# directly to the author so they can be merged back into the original
# version.

import sys, re, os, subprocess

amalgamate_include = re.compile('^\\s*#\\s*include\\s+\\"([^)]+)\\"\\s$')
already_included = []

def amalgamate(filename, stream):
  full_path = os.path.realpath(os.path.realpath(filename))
  srcdir = os.path.dirname(full_path)

  print('/* AUTOMATICALLY GENERATED FILE, DO NOT MODIFY */')

  git_id = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=srcdir).decode().strip()
  print("/* {:s} */".format(git_id))

  if full_path not in already_included:
    already_included.insert(-1, full_path)
    with open(filename) as input_file:
      stream.write('/* :: Begin ' + os.path.relpath(full_path) + ' :: */\n')

      for source_line in input_file:
        a9e_inc_m = amalgamate_include.match(source_line)
        if a9e_inc_m:
          amalgamate(os.path.join(srcdir, a9e_inc_m.group(1)), stream)
        else:
          stream.write(source_line)

      stream.write('/* :: End ' + os.path.relpath(full_path) + ' :: */\n')

if len(sys.argv) != 2:
  sys.stderr.write("USAGE: " + sys.argv[0] + ' SOURCE_FILE\n\n')
  sys.stderr.write("This will print a copy of $SOURCE_FILE to stdout, while replacing\n")
  sys.stderr.write("all '#include AMALGAMATE(file)' lines with copies of file.\n")

  sys.exit(1)

amalgamate(sys.argv[1], sys.stdout)
