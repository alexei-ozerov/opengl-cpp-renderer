#!/bin/bash 

set -e

cmake -S . -B build -G Ninja
ninja -C build clean
ninja -C build all

exit 0
