#!/bin/bash

echo "Nombre del archivo: ";
read arch;

if [[ $arch = *.tar ]]; then
	$(rm $arch)

else
	$(tar cf ACC.tar $arch)

fi;
