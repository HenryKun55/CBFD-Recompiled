#!/bin/sh
# Applies the Vita port's and the decomp's changes to the submodules (they point at
# upstream repositories): run from the repository root after `git submodule update --init`.
set -e
cd "$(dirname "$0")/../.."
for p in vita/submodule-patches/*.patch; do
    sub=$(basename "$p" .patch | tr _ /)
    [ -s "$p" ] || continue
    echo "applying $p to $sub"
    git -C "$sub" apply "$(pwd)/$p"
done
