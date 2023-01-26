#!/bin/bash

function compare(){
    if [[ $1 -ne $2 ]]; then
        if [[ $1 -gt $2 ]]; then
            return $1
        
        else 
            return $2
        fi
        
    else 
        return 0
    fi
}

echo "Introduza um número: "
read; 
NUM1="${REPLY}"

while [[ $NUM1 -ge 256 ]]; do
    echo -e "\nNúmero inválido!" 
    echo "Introduza outro número (< 256): "
    read; 
    NUM1="${REPLY}"
done

echo -e "\nIntroduza um número: "
read; 
NUM2="${REPLY}"

while [[ $NUM2 -ge 256 ]]; do
    echo -e "\nNúmero inválido!" 
    echo "Introduza outro número (< 256): "
    read; 
    NUM2="${REPLY}"
done

compare $NUM1 $NUM2

NUM="$?"

if [[ $NUM -ne 0 ]]; then
   echo -e "\nO número maior é $NUM"
else 
    echo -e "\nOs números são iguais"
fi

#case "$?" in
#    1)
#        echo "O número maior é $1"
#    ;;
#    2)
#        echo "O número maior é $2"
#    ;;
#    *)
#        echo "Os números são iguais"
#esac
