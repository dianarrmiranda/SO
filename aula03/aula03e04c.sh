#!/bin/bash
case $1 in
    [0-9]*)
    case $2 in
        "sec"*)
        echo "Argumentos Válidos"
        ;;
        *)
        echo "Segundo argumento inválido"
    esac
    ;;
    *)
    echo "Argumentos Inválidos"
    ;;
    esac
