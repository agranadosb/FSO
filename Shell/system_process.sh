#!/bin/bash
# arguments
aux=$(eval ls /proc/)

for i in $aux
do
    case ${i:0:1} in
        1)
            ./inf_process.sh $i || echo none
            ;;
        2)
            ./inf_process.sh $i || echo none
            ;;
        3)
            ./inf_process.sh $i || echo none
            ;;
        4)
            ./inf_process.sh $i || echo none
            ;;
        5)
            ./inf_process.sh $i || echo none
            ;;
        6)
            ./inf_process.sh $i || echo none
            ;;
        7)
            ./inf_process.sh $i || echo none
            ;;
        8)
            ./inf_process.sh $i || echo none
            ;;
        9)
            ./inf_process.sh $i || echo none
            ;;
        *)
            ;;
    esac
done