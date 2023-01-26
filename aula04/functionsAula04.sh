#!/bin/bash
function imprime_msg()
{
    echo "A minha primeira funcao"
    return 0
}

function alineab()
{
    echo $(date)
    echo $HOSTNAME
    echo $USER
    return 0
}

