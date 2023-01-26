#!/bin/bash
# Agrupamento de comandos na Bash
IFS="" # IFS = Internal Field Separator para aparecer os espaço atrás da frase  
{
    i=0
    while read line; do
        echo $i: $line
        i=$(($i+1))
    done
} < $1 