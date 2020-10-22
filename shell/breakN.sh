#!/bin/bash

for i in 1 2 3 4 
do
	echo "$i+========="
	for j in 5 6 7 8 9
	do
		if [ $j -eq 7 ]
		then
			continue 2 #不执行下面的语句 继续循环 加2两层的循环都被continue掉
			echo "\$j==$j"
			#break 2 # 跳出两层循环

		fi
	done
done

