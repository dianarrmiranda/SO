#!/bin/bash
#This script opens 4 terminal windows.

for (( i=0; $i < 4; i++ )); do
    xterm &
done