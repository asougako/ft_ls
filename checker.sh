#!/bin/zsh

clear
make noflags
time ./ft_ls $@
echo ""
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo ""
time ls $@

