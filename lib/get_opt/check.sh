#!/bin/bash

clear
make proper
gcc main.c -o main ../libft/libft.a ft_getopt.a -I ../
echo
echo
./main $@
echo
./test $@
