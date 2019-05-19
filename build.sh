#!/bin/bash

gcc src/advinhacao.c -o tests/advinhacao

if [ $? -ne 0 ]
then
    echo "|>> Erro";
    exit 1;
fi

clear
./tests/advinhacao