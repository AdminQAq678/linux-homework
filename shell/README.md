## 一、参数替换
#### 两种方式
//当参数未被声明的时候，取-号后面的参数
```bash
unset username
username=${username -"zhansan"}
echo $username
```
//当变量已经被声明但是被声明为null的时候取:-后面的参数
```bash
username=
username=${username:-"zhansan"}

echo $username
```

#### 当变量未被set的时候，设置=后面的参数为变量的值
```bash
unset usename 
echo ${username='lisi'}
```
### 当变量被set为空（null)的时候，设置:=后面的参数为变量的值
```bash
username=
echo ${username:='lisi'}
```

#### 当变量被set的时候，设置+后面的参数为变量的值，否则设置为null
```bash
unset usename 
echo ${username+'lisi'}
```

### 当变量被set为空（null)的时候，设置:+后面的参数为变量的值
```bash
username=
echo ${username:+'lisi'}
```

### 测试参数是否被set 如果没有 打印errormsg
```bash
unset username
echo ${username?'error:unset varaible username'}
```

当参数被set为null的时候 ，打印errormsg

```bash
username=
echo ${username:?'error:set  varaible   username to null'}
```



### 测试变量是否被set
```bash
: ${username?} # :后面需要加空格，该命令不会被输出，除非变量没有被设置
```

### 根据变量查看被声明的变量


```bash
echo ${!varprefix*}
```

## 二、随机数



```bash
#$RANDOM

RANGE=20
#范围随机数
let "number=$RANDOM % $RANGE"
echo $number
```

### 三、输出数组长度



```bash
array=(1,2,3)

echo ${#array[*])
echo ${#array[@]}
```

## 四、for循环



```bash
list="file1.txt
file2.txt
file3.txt"

for file in $list
do
	echo $file
done
```

##### 没有参数的for循环会自动使用位置参数


```bash
for i
do
	echo $i # $1 $2........
done
```

##### for 循环在二进制文件中查找字符串

```bash
for word in $( strings "$2" | grep "$1" )
do 
echo $word
done
```



#### c语言风格的for 循环

```bash
for ((i=0;i<10;i++) 没有$符号
do
echo $i

done


for ((i=0,j=0;i<10;i++,j++) 没有$符号,同时对两个变量加一

do
echo $i

done
```

### while 的多条件循环，只有最后一个条件可以控制循环


```bash
while echo "previous-variable = $previous"

 echo

 previous=$var1

 [ "$var1" != end ] 


do 

	echo "while condition  running"
done
```

#### 实例


```bash
a=1
b=3

while [ $a -lt 10 ]
	[ $b -lt 10 ]
	[ $a -lt $b ]
do
	let "a++"
	echo "running: \$a=$a ; \$b=$b"
done
```


echo "--------------------"



## 五控制台输出不同颜色的字体

格式
echo -e "\E[30;41]myourword" # -e 用于输出转义字符，这里的作用是输出颜色 '\E[' 开始转义，']m' 转义结束 ，30为前景色黑色，41为背景色红色，两者的先后书写顺序不会影响输出结果，因为前景色和背景色使用不同的编号来标识。
![颜色编号](https://img-blog.csdnimg.cn/20201009102737384.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NDU5NjczNQ==,size_16,color_FFFFFF,t_70#pic_center)

```shell 
#!/bin/bash
#测试脚本 cecho.sh
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
```


### read

```bash
read -s -n1 -p "Hit a key " keypress
# 将字符读取到keypress变量中
# -n 表示接受n个字符的输入
# -p 表示在读取输入前打印后面的提示符 "Hit a key"
#-s不显示输入
#  

```


### 目录栈
1. pushd dirname 压入dirname到目录栈同时进入该目录
2. popd 弹出目录栈并进入目录栈顶端的目录
3. dirs 显示目录栈所有目录


### $() 、 $(()) 、$[[]] 、${}、 ``
1. $()和``用于命令的替换，其中$()只能用于bash中，``可用于其他类型的shell中
2. $(()) 用于数值计算 
3. [[]] 用于逻辑条件的判断 ,对 [] 的加强 ，是一个关键字
4. ${} 变量的替换
4. $() 和$(())中的$是用于提取返回值 $()为命令的执行结果,$(())为数值计算的结果

