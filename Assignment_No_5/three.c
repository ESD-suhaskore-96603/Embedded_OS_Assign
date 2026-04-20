#!/bin/bash

read -p "Enter a file or directory name: "name

if[! -e "$name" ]; then
	echo "Error: '$name' does not exist."
	exit 1
fi


