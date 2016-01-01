#!/bin/bash

PATH_BASE="/home/alfonso/devel/INTS_MEXICO/"
PATH_SAL=$PATH_BASE"jsvg/"
DIMX=1000
DIMY=800

for i in {1..32}
do
echo "Estado: "$i

./int2svgp.exe $PATH_BASE/mgm2013v6_2.int 3 4 $i $DIMX $DIMY $PATH_SAL

php ./genera_mapael.php $PATH_SAL $i $DIMX $DIMY



done


cd $PATH_SAL
find ./ -size 0b -delete