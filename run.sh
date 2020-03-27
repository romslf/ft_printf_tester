#!/bin/bash

path=../ft_printf
libname=libftprintf.a
timer=0.1

function log () {
    if [ "$2" = 'success' ]; then
        printf "\033[0;32m"
    elif [ "$2" = 'error' ]; then
        printf "\033[0;31m"
    else
        printf "\033[1;36m"
    fi
    printf "$1"
    printf "\033[0m\n"
    sleep $timer
}

function part1 () {
    log "Copying library to tester."
    if cp $path/$libname printf.a ; then
        log "Copy, done." "success"
        part2
    else
        log "Copy, failed !" "error"
    fi
}

function part2 () {
    log "Compiling tester..."
    if gcc tester.c printf.a -o tester ; then
        log "Compiling, done." "success"
        rm printf.a
        part3
    else
        log "Compiling, failed !" "error"
    fi
}

function part3 () {
    log "Starting tester ..."
    if ./tester ; then
        log "Done." "success"
        rm tester
    else
        log "END, tester failed, try again !" "error"
    fi
}

clear
log "Setup starting..."
log "Compiling your project..."
if make -C $path ; then
    log "Compiling, done." "success"
    part1
else
    log "Compiling, failed !" "error"
fi
