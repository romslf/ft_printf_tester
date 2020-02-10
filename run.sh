#!/bin/bash

path=../ft_printf
libname=printf.a
timer=0.1

echo "\e[96mSetup starting..."
sleep $timer
echo "Compiling your project..."
sleep $timer
make -C $path
echo "Compiling, done."
sleep $timer
echo "Copying library to tester."
sleep $timer
cp $path/$libname printf.a
echo "Compiling tester..."
sleep $timer
gcc tester.c printf.a -o tester
echo "Compiling, done."
sleep $timer
rm printf.a
echo "Setup done."
sleep $timer
echo "Running tester..."
sleep $timer
./tester
rm tester
