#!/bin/bash
# Calculate the sum of a series of numbers.
SCORE="0"
SUM="0"
i=0;
while true; do
    echo -n "Enter your score [0-10] ('q' to quit): "
    read SCORE;
    i=$(($i+1));
if (("$SCORE" < "0")) || (("$SCORE" > "10")); then
    echo "Try again: "
elif [[ "$SCORE" == "q" ]]; then
    echo "Sum: $SUM."
    i=$(($i-1));
    media=$(($SUM/$i))
    echo "Media: $media"
    break
elif [[ "$SCORE" == "r" ]]; then
    SUM=0;
    i=0;
else
    SUM=$((SUM + SCORE))
fi
done

echo "Exiting."