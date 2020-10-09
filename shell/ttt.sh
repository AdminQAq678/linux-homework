
#MINLEN=45

#while read line
#do
#	echo "$line"
#	len=${#len}
#	if [ "$len" -lt "$MINLEN" ]
#	then echo
#	fi
#done

range=$1

number=$RANDOM

let "number=$number%$range"

echo "range:$number"

floor=$2

let "number=$number+$floor"

echo "number:$number"



echo 

echo "--------------------"

for i 
do
	echo $i
done

echo "--------------------"
a=1
b=3

while [ $a -lt 10 ]
	[ $b -lt 10 ]
	[ $a -lt $b ]
do
	let "a++"
	echo "running: \$a=$a ; \$b=$b"
done


echo "--------------------"



clear

R=$1
C=$2
H=$3
W=$4
col=$5
draw_box $R $C $H $W $col

