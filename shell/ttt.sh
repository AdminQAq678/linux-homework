

MINLEN=45

while read line
do
	echo "$line"
	len=${#len}
	if [ "$len" -lt "$MINLEN" ]
	then echo
	fi
done


