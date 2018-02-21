#!/bin/bash
# ECLiPSe-clp program running script
# example usage: ./run_queens.sh > output.csv


MODELS="lists arrays"
DATAA="half lucky normal sixfourth"
VARORDERS="input_order first_fail"

for model in $MODELS; do
    for data in $DATAA; do
        for varorder in $VARORDERS; do
            eclipse -b queens_aplai.ecl -e "queens($model, $data, $varorder, _)."
        done
    done
done
