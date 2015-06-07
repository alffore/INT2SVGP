#!/bin/bash
for i in {1..32}
do
echo "Estado: "$i

./int2svgp.exe /home/alfonso/devel/INTS_MEXICO/Municipios_2013.int 3 4 $i 1000 1000

done
