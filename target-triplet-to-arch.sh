#!/bin/bash

triplet="$1"

case "$triplet" in
    i686-*)   echo "i386" ;;
    x86_64-*) echo "x86_64" ;;
    arm-*)    echo "arm" ;;
    aarch64-*) echo "aarch64" ;;
    *)        echo "unknown" ;;
esac