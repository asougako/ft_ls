#!/bin/bash

clear
make noflags
./a.out  $1 $2

echo ""
ls $1 $2
