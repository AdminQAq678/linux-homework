### 参数替换
#### 两种方式
//当参数未被声明的时候，取-号后面的参数
unset username
username=${username -"zhansan"}
echo $username

//当变量已经被声明但是被声明为null的时候取:-后面的参数
username=
username=${username:-"zhansan"}

echo $username


#### 当变量未被set的时候，设置=后面的参数为变量的值
unset usename 
echo ${username='lisi'}

### 当变量被set为空（null)的时候，设置:=后面的参数为变量的值
username=
echo ${username:='lisi'}

#### 当变量被set的时候，设置+后面的参数为变量的值，否则设置为null
unset usename 
echo ${username+'lisi'}

### 当变量被set为空（null)的时候，设置:+后面的参数为变量的值
username=
echo ${username:+'lisi'}


### 测试参数是否被set 如果没有 打印errormsg
unset username
echo ${username?'error:unset varaible username'}


当参数被set为null的时候 ，打印errormsg
username=
echo ${username:?'error:set  varaible   username to null'}

### 测试变量是否被set
: ${username?} # :后面需要加空格，该命令不会被输出，除非变量没有被设置

### 根据变量查看被声明的变量
echo ${!varprefix*}


### 随机数
$RANDOM
RANGE=20
范围随机数
let "number=$RANDOM%$RANGE"
echo $number

### 输出数组长度
array=(1,2,3)

echo ${#array[*])
echo ${#array[@]}


#### for循环
list="file1.txt
file2.txt
file3.txt"

for file in $list
do
	echo $file
done

##### 没有参数的for循环会自动使用位置参数
for i
do
	echo $i # $0 $1........
done

##### for 循环在二进制文件中查找字符串


for word in $( strings "$2" | grep "$1" )
do 
echo $word
done

#### c语言风格的for 循环
for ((i=0;i<10;i++) 没有$符号
do
echo $i

done


for ((i=0,j=0;i<10;i++,j++) 没有$符号,同时对两个变量加一

do
echo $i

done


### while 的多条件循环，只有最后一个条件可以控制循环
while echo "previous-variable = $previous"

 echo

 previous=$var1

 [ "$var1" != end ] 


do 

	echo "while condition  running"
done
#### 实例
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
