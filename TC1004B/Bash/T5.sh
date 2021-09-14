#!/bin/bash
echo "Para ejecutar todos los programas, introduzca 'T'";
echo "Programa 1: T11";
echo "Programa 2: T21";
echo "Programa 3: T31";
echo "Programa 4: T41";

shopt -s expand_aliases
alias  T11='bash T11.sh'
alias  T21='bash T21.sh'
alias  T31='bash T31.sh'
alias  T41='bash T41.sh'
alias  T='bash T11.sh && bash T21.sh && bash T31.sh && bash T41.sh'

read op;
if [[ $op = 'T11' ]]; then
	T11
elif [[ $op = 'T21' ]]; then
	T21
elif [[ $op = 'T31' ]]; then
	T31
elif [[ $op = 'T41' ]]; then
	T41
elif [[ $op = 'T' ]]; then
	T

fi;
