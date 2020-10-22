#从position开始提取字符串
stringz=helloboy

echo ${stringz:1}

echo ${stringz:2}

#反向提取字符串
#-4前面需要加空格
#或者使用()包裹
echo ${stringz: -4}
echo ${stringz: (-4)}

#echo 出第二个后面的位置参数
echo ${@:2}

#echo 从第二个位置参数开始，echo3个位置参数
echo ${*:2:3}

#echo 从第二个位置参数开始，echo3个位置参数
echo ${@:2:3}

#字符串的截取
#从$stringz的1位置开始 截取长度为2的子串
echo `expr substr $stringz 1 2`

#从$stringz 的开始位置提取正则匹配的内容
echo `expr match "$stringz" '\(.[a-z].\)'`
#同上
echo `expr "$stringz" : '\(.[b-c]*[A-Z]..[0-9]\)'`



#从左边截取第一个匹配的substring的字符串
#${string#substring}

#从左边截取最后一个匹配的substring的字符串
#${string##substring}

stringZ=abcABC123ABCabc


echo ${stringZ#a*C} # 123ABCabc

echo ${stringZ##a*C} # abc

#从右边截取最后一个匹配的substring的字符串

${string%substring}

#从右边截取最后一个匹配的substring的字符串

#${string%%substring}

echo ${stringZ%b*c} # abcABC123ABCa

echo ${stringZ%%b*c} # a

#子串替换
#替换第一个匹配的$subString
#${string/substring/replacement}

stringz=abc123abc
echo ${stringz/abc/xyz}
echo "stringz:${stringz}"

#替换所有匹配到的$subString
${string//substring/replacement}


echo ${stringz//abc/xyz}
#!/bin/bash

black='\E[30;47m'
red='\E[31;47m'
green='\E[32;47m'

yello='\E[33;47m'
blue='\E[34;47m'



magenta='\E[35;47m'
cyan='\E[36;47m'
white='\E[37;47m'



alias Reset="tput sgr0"
cecho(){

	local default_msg="no message"
	message=${1:-$default_msg}
	color=${2:-$black}
	echo -e "$color"
	echo "$message"
	Reset
	return
}

cecho "feeling blue" $blue

cecho "feeling yellow" $yellow
cecho "feeling cyan" $cyan
cecho "feeling red" $red
cecho "feeling black" $black
cecho "feeling green" $green

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

#!/bin/bash
select var in "c" "c++"  "java" "python"
do 
       echo $var
done
echo "your selection is $var"
#!/bin/bash

until [ -z "$1" ]
do
	echo -n "$1"
	shift
done

echo

#/bin/bash
: ${1?" Usage : $0 ARGUMENT"}

echo " there is an argument here: $1"

#exit 0

#!/bin/bash
for i in 1 2 3 4 5
do
	echo $i
	sleep 1
done&

for d in 6 7 8 9 10
do
	echo $d
	sleep 1
	
done
#!/bin/bash

if [ -z "$1" ];then
	echo $1

fi

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

systemctl get-default

systemctl set-default graphic.target



#终端操作
ctrl + k #删除光标到行尾的字符
ctrl + u #删除光标到行首的字符 
#vim 操作
//复制
yy
#粘贴
p
#列出光标所在的行号
ctrl + g
#撤销上一次的操作
u
#取消所有操作
U


nononono
nononono


