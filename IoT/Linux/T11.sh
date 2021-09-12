#!/bin/bash

echo "Escriba el nombre del archivo";
read arch;

if [[ $arch = *.txt ]]; then
	echo "Escriba la palabra a buscar";
	read w;
	echo "";

	mapfile -t a < <(grep -wi $w $arch);
	#echo "${a[3]}"
	if [[ ${#a[@]} -gt 5 ]]; then
		x=0;
		while [ $x -lt 5 ]; do
			echo "${a[$x]}";
			x=$(( $x + 1 ));
		done;
	
	elif [[ ${#a[@]} -eq 0 ]]; then
		echo "Sin coincidencias";

	else
		printf "%s\n" "${a[@]}";
	fi;

else
	echo "El archivo no es .txt";

fi;

