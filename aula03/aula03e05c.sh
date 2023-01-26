#!/bin/bash
# For all the files in a folder, show their properties

[[ $# -eq 1 ]] || { echo "Erro: Indique um ficheiro" >&2; exit 1; }



if [[ -d $1 ]] ; 
then

    for f in $1/*; do
        mv -- "$f" "new_$f"
    done

else
 echo "$1 não é uma diretoria."

fi

#Não funciona corretamente