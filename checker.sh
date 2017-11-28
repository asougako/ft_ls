#!/bin/bash

clear
make noflags &&
./ft_ls $@
echo ""
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo ""
ls $@

