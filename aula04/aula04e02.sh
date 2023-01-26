#!/bin/bash
function numeric_to_string()
{
    case "$1" in
    1)
        echo "Um"
    ;;
    2)
        echo "Dois"
    ;;
    3)
        echo "Três"
    ;;
    4)
        echo "Quatro"
    ;;
    5)
        echo "Cinco"
    ;;
    *)
        echo "Outro numero"
    esac

    return $1
}

numeric_to_string $1 

echo $? #Valor de retorno