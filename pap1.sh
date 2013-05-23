#!/bin/csh

if -f $argv[1] then
	if -d $argv[2] then
		echo aplankas jau yra
	else
		mkdir $argv[2]
		cp $argv[1] $argv[2]
	endif
else
	echo failas nera failas
endif
