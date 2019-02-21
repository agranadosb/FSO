#!/bin/bash
# arguments
aux=$(awk '/Pid:/' /proc/$1/status)
for i in $aux
do
echo $i
done