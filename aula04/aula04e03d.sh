#!/bin/bash

declare numsArray

arquivo="$1"

i=0

while read linha; do
    numsArray[i]=$linha
    i=$((i+1))
done < "$arquivo"

i=0
j=0
temp=0

while (( $i < ${#numsArray[@]} )); do
    while (( $j < ${#numsArray[@]}-1 )); do
        if ((${numsArray[$j+1]} < ${numsArray[$j]} )); then
                temp=${numsArray[$j]}
                numsArray[$j]=${numsArray[$j+1]}
                numsArray[$j+1]=$temp
        fi
        j=$j+1
    done
    i=$i+1
    j=0
done

echo -e "Valores:\n${numsArray[@]}"