#!/bin/bash

clear
make noflags &&
clear
./ft_ls $@
echo ""
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo ""
ls $@

