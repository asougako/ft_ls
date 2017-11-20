#!/bin/zsh

clear
make noflags
clear
time ./ft_ls $@
echo ""
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo ""
time ls $@

