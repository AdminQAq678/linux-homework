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
