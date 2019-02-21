#!/bin/bash
# arguments
if test -f $1
then
sudo rm -r $1
else
echo "El fichero no existe"
fi