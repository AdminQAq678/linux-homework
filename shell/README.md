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



