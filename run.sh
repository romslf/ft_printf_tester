#!/bin/bash

path=../ft_printf
libname=printf.a

echo "Setup starting..."
echo "Compiling your project..."
make -C $path
echo "Compiling, done."
echo "Copying library to tester."
cp $path/$libname printf.a
echo "Compiling tester..."
gcc tester.c printf.a -o tester
echo "Compiling, done."
rm printf.a
echo "Setup done."
echo "Running tester..."
./tester
rm tester
echo "Tester done."
