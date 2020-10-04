#!/bin/bash
comparison=integer
#比较规则 ，这里是数值比较 使用(()) 可以不带$ (())用于算术比较
#字符串比较使用 [[]] 需要带$
#两种方式的比较都会返回一个退出码
a=1
b=2

echo $?
if  echo "word if in the file"
	if [[ $comparison = "integer" ]]
	then (( a<b ))
	else
		[[ $a<$b ]]
	fi
then	#如果then这里接收到的上面的退出码为0就执行then后面的语句
	echo " $a is less than $b"
else
	echo " $a is larger than $b"
fi
