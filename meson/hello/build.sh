#! /bin/bash

set -ex

meson setup builddir
cd builddir
ninja
