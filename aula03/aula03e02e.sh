#!/bin/bash
# Conditional block if

echo "Checking..."

if [[ $1 =~ ^[0-9]+$ ]]; then
    if [[ $1 -gt 5 && $1 -lt 10 ]]; then
        echo  "número maior do que 5 e menor do que 10"
    else
        echo "número menor do que 5 ou maior do que 10"
    fi 
else
 echo "O argumento não é um inteiro"
fi
echo "...done." 

