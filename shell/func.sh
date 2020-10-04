#!/bin/bash
hello(){
echo 'hello dear user'
select pro in "c" "c++" "python" "java"
do
	echo "your selection is $pro"
	break;
done

array=( 1 2 3 4 5 6 7 8 9 )
for t in ${array[@]}
do 
	echo "$t"
done
}

hello



