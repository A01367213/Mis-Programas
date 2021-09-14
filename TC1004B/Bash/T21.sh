#!/bin/bash

echo "Introduce el nombre del archivo: ";
read arch;
echo "";
echo "Ordenar en orden ascendente (-a)";
echo "Ordenar en orden descendente (-z)";
echo "Escriba como desea ordenar el archivo: ";
read ord
echo "";

if [[  $ord = "-a" ]]; then
	printf "%s\n" "$(cat $arch | sort)";
	
elif [[ $ord = "-z" ]]; then
	printf "%s\n" "$(cat $arch | sort -r)";
	
fi;

