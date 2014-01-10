#!/usr/bin/env python
#
# Copyright (c) 2012, Daniel Bolgheroni. All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 
#   1. Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#
#   2. Redistributions in binary form must reproduce the above
#      copyright notice, this list of conditions and the following
#      disclaimer in the documentation and/or other materials provided
#      with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY DANIEL BOLGHERONI ''AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL DANIEL BOLGHERONI OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
# OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# DESCRIPTION
# bmv stands for 'bulk move', an utility to rename more than one file
# based on patterns and rules.

import argparse
import re
import os

opts = argparse.ArgumentParser()

opts.add_argument("pattern",
        help="pattern to apply to files to be renamed",
        type=str)
opts.add_argument("file", 
        help="glob to select files",
        nargs='+')
opts.add_argument("-d",
        help="dummy mode (doesn't apply changes)",
        action="store_true")
opts.add_argument("-p",
        help="padding used for the index (defaults to 2)",
        type=int)
opts.add_argument("-o",
        help="define the start offset",
        type=int)
# TODO: implement this
#opts.add_argument("-j",
#        help="define a jump point",
#        action="store_true")

args = opts.parse_args()

# -o argument
if args.o == None:
    o = 1
elif args.o == 0:
    o = args.o
else:
    o = args.o

# -p argument
if args.p:
    padding = "%0" + str(args.p) + "d"
else:
    padding = "%02d"

# main
for f in args.file:
    old = f

    # -p argument (extract extension)
    pattern = re.compile(r'.*\.(?P<ext>(\w)+)')
    match = pattern.search(old)
    if match:
        extension = match.group('ext').lower()

    # -p argument
    new = args.pattern + (padding % o) + "." + extension

    # -d argument
    if args.d == False:
        print(old, "->", new)
        # TODO: add a try-except here
        os.rename(old, new)
    else:
        print(old, "->", new, "(dummy)")

    o += 1
