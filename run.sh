#!/bin/bash

path=../ft_printf # Your printf project dir
libname=libftprintf.a # Your printf lib name
timer=0 # Wait after each log 

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

function compile_lib () {
    log "Compiling your project..."
    if make -C $path ; then
        log "Compiling, done." "success"
        copy_lib
    else
        log "Compiling, failed !" "error"
    fi
}

function copy_lib () {
    log "Copying library to tester."
    if cp $path/$libname printf.a ; then
        log "Copy, done." "success"
        compile_tester
    else
        log "Copy, failed !" "error"
    fi
}

function compile_tester () {
    log "Compiling tester..."
    if gcc -w tester.c printf.a -o tester ; then
        log "Compiling, done." "success"
        rm printf.a
        start_tester
    else
        log "Compiling, failed !" "error"
    fi
}

function start_tester () {
    log "Starting tester ..."
    if ./tester ; then
        log "Done. ✅" "success"
    else
        log "💥💥 END, tester failed, try again ! 💥💥" "error"
    fi
    rm tester
}

function header () {
    currentDate=`date`
    echo " "
    echo " "
    echo " "
    echo "#################################"
    echo " " $currentDate
    echo "#################################"
    echo " "
    log "Setup starting..."
}

clear
header
compile_lib