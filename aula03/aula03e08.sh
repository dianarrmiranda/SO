#!/bin/bash
# select structure to create menus
PS3="Enter a number: "

i=1;
temp=0;
select arg in $@; do
    if [[ $arg == "" ]]; then
        echo "You picked a none valid choice"
        break
    else
        echo "You picked $arg ($REPLY)."
    fi

done