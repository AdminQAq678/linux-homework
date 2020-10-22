#!/bin/bash
a=1
until [ $a -gt 10 ] #条件为真才退出循环
do
	echo -e '\E[32;44mhello guys'
	let "a++"
done


