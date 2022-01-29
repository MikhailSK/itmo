#!/usr/bin/env sh
cat quine-readable.i | sed 's/[[:space:]]*//g' | tr -d '\n' > quine-test.i