#!/bin/bash
# This script checks the existence of a file
[[ $# -eq 1 ]] || { echo "Erro: Indique um ficheiro" >&2; exit 1; }

echo "Checking..."

if [[ -a $1 ]] ; 
then
    echo "$1 existe."
    if [[ -f $1 ]] ; 
    then
        echo "$1 é um ficheiro normal."
    elif [[ -d $1 ]] ; 
    then
        echo "$1 é um diretório"
    fi

    echo "Permissões: "
    if [[ -r $1 ]] ||[[ -w $1 ]] || [[ -x $1 ]]; 
    then
        [[ -r $1 ]] && echo "Leitura";
        [[ -w $1 ]] && echo "Escrita";
        [[ -x $1 ]] && echo "Execução";
    else
        echo "Nenhuma"
    fi

else
 echo "$1 não existe."

fi
echo "...done." 