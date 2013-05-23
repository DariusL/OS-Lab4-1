#!/bin/csh

if -f $argv[1] then
	if -d $argv[2] then
		echo aplankas jau yra
	else
		mkdir $argv[2]
	endif
	cp $argv[1] $argv[2]
else
	echo failas nera failas
endif
