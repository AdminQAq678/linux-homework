#!/bin/bash

RANDOM=22

echo $RANDOM
i=10
while [ $i -gt 0 ]
do
	RANDOM=date
	echo $RANDOM
	let "i--"
done

