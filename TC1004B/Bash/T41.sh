#!/bin/bash

echo "Ingresa el numero: ";
read n;
echo "";

i=1;
while [ $i -le 10 ]; do
	r=$(( $n * i ));
	echo "$r";
	i=$(( $i + 1 ));
done;
