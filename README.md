# CS 35L Notebook

## Command Tool

### emacs

- git diff mode:

  - [vc-diff](http://www.gnu.org/software/emacs/manual/html_node/emacs/Old-Revisions.html) (C-x v =) and [vc-revert](http://www.gnu.org/software/emacs/manual/html_node/emacs/VC-Undo.html) (C-x v u)
  
- [diff-apply-hunk](http://www.gnu.org/software/emacs/manual/html_node/emacs/Diff-Mode.html) (C-c C-a) and diff-goto-source (C-c C-c)
  
    

### patch

使用 **diff -uN[r] 旧文件 新文件 > 补丁文件** 命令创建补丁文件。

在待补丁文件的目录下使用 **patch -p[数字] <补丁文件** 命令打补丁

**-p [数字]** 表示忽略补丁文件中记录的目录，数字为忽略的层数。

**patch -R 已打补丁文件 补丁文件** 将已打补丁文件恢复到原来的状态



### hunk

​	From the link http://www.gnu.org/software/emacs/manual/html_node/emacs/Diff-Mode.html on the specs: "The changes specified in a patch are grouped into hunks, which are contiguous chunks of text that contain one or more changed lines. Hunks usually also include unchanged lines to provide context for the changes. Each hunk is preceded by a hunk header, which specifies the old and new line numbers where the hunk's changes occur. Diff mode highlights each hunk header, to distinguish it from the actual contents of the hunk."



### echo 字符串

回显。较复杂的字符串，可以使用 **"** 括起来。

| 选项     | -n           | 输出内容不换行 |
| -------- | ------------ | -------------- |
| -E       | 不解析脱字符 |                |
| -e       | 解析脱字符   |                |
| 控制字符 | \\           | 反斜线         |
| \a       | 警告         |                |
| \b       | 退格         |                |
| \n       | 换行         |                |
| \r       | 回车         |                |
| \t       | 水平制表符   |                |

### Sort

Sort a.txt (in default order e.g. ASCII)

sort [-o 输出文件] [-t 分隔字符] [+起始字段 -结束字段] [文件]

| -m   | 合并文件                                         |
| ---- | ------------------------------------------------ |
| -c   | 检查文件是否已按规则排序                         |
| -b   | 忽略行首空格字符                                 |
| -u   | 忽略内容重复行                                   |
| -f   | 忽略大小写                                       |
| -l   | 忽略非打印字符                                   |
| -M   | 作为月份比较                                     |
| -d   | 按字典顺序排序，按照字母、数字、空格、制表符排序 |
| -r   | 逆序输出                                         |



- -i 排序时，除了040至176之间的ASCII字符外，忽略其他的字符。
- -m 将几个排序好的文件进行合并。
- -M 将前面3个字母依照月份的缩写进行排序。
- -n 依照数值的大小排序。
- -o<输出文件> 将排序后的结果存入指定的文件。
- -t<分隔字符> 指定排序时所用的栏位分隔字符。
- +<起始栏位>-<结束栏位> 以指定的栏位来排序，范围由起始栏位到结束栏位的前一栏位。
- --help 显示帮助。
- --version 显示版本信息。

### Comm

输出的第一列只包含在aaa.txt中出现的行，第二列包含在bbb.txt中出现的行，第三列包含在aaa.txt和bbb.txt中相同的行。各列是以制表符（\t）作为定界符。跟顺序有关，类似diff

Comparison depends on locale

- -1 不显示只在第1个文件里出现过的列。
- -2 不显示只在第2个文件里出现过的列。
- -3 不显示只在第1和第2个文件里出现过的列。

### |

it directs the output from the first command into the input for the second command

### >

rewrite to a file

- echo "abcde" | tr "abc" [xyz] > delete.txt

  //[xkde

### >>

Append to a file

### v

- -i: 若指定目录已有同名文件，则先询问是否覆盖旧文件;
- -f: 在mv操作要覆盖某已有的目标文件时不给任何指示;

### file

- -b 　列出辨识结果时，不显示文件名称。
- -c 　详细显示指令执行过程，便于排错或分析程序执行的情形。
- -f<名称文件> 　指定名称文件，其内容有一个或多个文件名称时，让file依序辨识这些文件，格式为每列一个文件名称。
- -L 　直接显示符号连接所指向的文件的类别。

### Echo

- echo $? 检查报错

  ```sh
  a=pwd
  echo $a //pwd
  echo '$a' //$a
  echo "$a" //pwd
  echo `$a` ///u/eng/class/classwli/lab1
  ```

### cat

- Cat <file 2>file2 //把file的error输入file2

- cat <file | sort >file2

  输出文件内容。用空格分隔多个文件名

  | -n   | 在输出中添加行号                   |
  | ---- | ---------------------------------- |
  | -b   | 在输出中添加行号，空行不编号       |
  | -s   | 将两行或以上的空行，合并为一个空行 |

### p

- cp -r 把整个文件夹copy过来（recursively）

### man

在使用 man 浏览器的时候，一些快捷键您可能会用到：



| Ctrl+f(orward)  | 向下翻一页 | Ctrl+d(own) | 向下翻半页 |
| --------------- | ---------- | ----------- | ---------- |
| Ctrl+b(ackward) | 向上翻一页 | Ctrl+u(p)   | 向上翻半页 |
| /               | 查找       | q(uit)      | 退出       |

The table below shows the section numbers of the manual followed by the types of pages they contain.

       1   Executable programs or shell commands
       2   System calls (functions provided by the kernel)
       3   Library calls (functions within program libraries)
       4   Special files (usually found in /dev)
       5   File formats and conventions eg /etc/passwd
       6   Games
       7   Miscellaneous (including macro packages and conventions), e.g. man(7), groff(7)
       8   System administration commands (usually only for root)
       9   Kernel routines [Non standard]
### find [路径] 表达式

查找文件

| -name 表达式     | 根据文件名查找文件                                           |
| ---------------- | ------------------------------------------------------------ |
| -iname 表达式    | 根据文件名查找文件，忽略大小写                               |
| -path 表达式     | 根据路径查找文件                                             |
| -ipath 表达式    | 根据路径查找文件，忽略大小写                                 |
| -amin 分钟       | 过去N分钟内访问过的文件                                      |
| **-atime 天数**  | 过去N天内访问过的文件                                        |
| -cmin 分钟       | 过去N分钟内修改过的文件                                      |
| **-ctime 天数**  | 过去N天内修改过的文件                                        |
| -anewer 参照文件 | 比参照文件更晚被读取过的文件                                 |
| -cnewer 参照文件 | 比参照文件更晚被修改过的文件                                 |
| -size 大小       | 根据文件大小查找文件，单位 b c w k M G。 文件大小 是 n 单位，b 代表 512 位元组的区块，c 表示字元数，k 表示 kilo bytes，w 是二个位元组 |
| -type 文件类型   | 根据文件类型查找文件。b 块设备 c 字符设备 d 目录 p 管道文件 f 普通文件 l symbol链接 s 端口文件 |
| -user 用户名     | 按归属用户查找文件                                           |
| -uid 用户编号    | 按用户编号查找文件                                           |
| -group 群组名    | 按归属群组查找文件                                           |
| -gid 群组编号    | 按群组编号查找文件                                           |
| -empty           | 查找空文件                                                   |

eg

```
find . -name "*.c"
找前目录中文件属主具有读、写权限，并且文件所属组的用户和其他用户具有读权限的文件：
# find . -type f -perm 644 -exec ls -l {} \;
查找/var/log目录中更改时间在7日以前的普通文件，并在删除之前询问它们：
# find /var/log -type f -mtime +7 -ok rm {} \;
为了查找系统中所有文件长度为0的普通文件，并列出它们的完整路径：
# find / -type f -size 0 -exec ls -l {} \;
```

### chmod 权限表达式 文件|目录

更改文件的权限。权限的表达式可以使用 3位8进制数字 表示，或者使用 augo +-= rxw-s 来表示

| -R                         | 递归                     |
| -------------------------- | ------------------------ |
| -v                         | 显示过程                 |
| -c                         | 类似“-v”，仅显示更改部分 |
| --reference=参照文件或目录 | 以指定文件为参照更改权限 |

### chown 归属用户[:归属群组] 文件|目录

更改文件的归属用户。可以使用用户名或者用户编号

| -R                         | 递归                     |
| -------------------------- | ------------------------ |
| -v                         | 显示过程                 |
| -c                         | 类似“-v”，仅显示更改部分 |
| --reference=参照文件或目录 | 以指定文件为参照更改权限 |

### ps

显示进程信息，选项可省略 “**-**”

| aux      | 以 BSD风格 显示进程 ***常用\*** |
| -------- | ------------------------------- |
| -efH     | 以 SystemV风格 显示进程         |
| -e \| -A | 显示所有进程                    |
| a        | 显示终端上所有用户的进程        |
| x        | 显示无终端进程                  |
| u        | 显示详细信息                    |
| f        | 树状显示                        |
| w        | 完整显示信息                    |
| l        | 显示长列表                      |

### kill [信号代码] 进程编号

根据进程编号向进程发送信号，常用来结束进程，默认信号为 -9 

| -l [信号代码] | 显示、翻译信号代码        |
| ------------- | ------------------------- |
| -9 \| -KILL   | 发送 kill 信号,退出       |
| -6 \| -ABRT   | 发送 abort 信号,退出      |
| -15 \| -TERM  | 发送 Termination 信号     |
| -1 \| -HUP    | 挂起                      |
| -2 \| -INT    | 从键盘中断，相当于 Ctrl+c |
| -3 \| -QUIT   | 从键盘退出，相当于 Ctrl+d |
| -4 \| -ILL    | 非法指令                  |
| -11 \| -SEGV  | 内存错误                  |
| -13 \| -PIPE  | 破坏管道                  |
| -14 \| -ALRM  |                           |
| -STOP         | 停止进程，但不结束        |
| -CONT         | 继续运行已停止的进程      |
| -9 \| -1      | 结束当前用户的所有进程    |

### shutdown

关闭计算机，向根进程 init 发送信号，更改 runlevel 为 0 (halt)

| -h            | 关闭电源                         |
| ------------- | -------------------------------- |
| -r            | 重启                             |
| -n            | 强行关机，不向 init进程 发送信号 |
| -k            | 模拟关机，向登录者发送关机警告   |
| -t 秒         | N秒后关机                        |
| time 时间     | 定时关机                         |
| -c [说明信息] | 取消关机                         |
| -f            | 重启时忽略检测文件系统           |
| -F            | 重启时强制检测文件系统           |

## Regular Expressions正则表达式

##### Basic (BRE) and extended (ERE) regular expression

Basic and extended regular expressions are two variations on the syntax of the specified pattern. Basic Regular Expression (BRE) syntax is the default in `sed` (and similarly in `grep`). 

In GNU `sed`, the only difference between basic and extended regular expressions is in the behavior of a few special characters: ‘?’, ‘+’, parentheses, braces (‘{}’), and ‘|’.

With basic (BRE) syntax, these characters(?,+,{},|, ...) do not have special meaning unless prefixed with a backslash (‘\’); While with extended (ERE) syntax it is reversed: these characters are special unless they are prefixed with backslash (‘\’).

特殊字符

BRE: `.`、`\`、`[`、`^`、`$`、`*`  

ERE: `.`、`\`、`[`、`^`、`$`、`*`、`(`、`)`、`{`、`}`、`+`、`?`、`|`

```
\(\)
```



- *
  - [^P]* cannot match Poy and caP, but can match cup and so on.
  - .* matches any characters
  - tol.*toy can matches toltoy and any word with any length of characters bwtween them.
- ^ matches beginning, $ matches ending
  - ^tolstoy$ means a line only containes tolstoy
- { }
  - a{exact times}
  - a{atleast times, atmost times}
  - e.g. a{ , 1} means 'a' appears at most 1 time
- ？
  - favou?rite means there are whether 0 or 1 u, means only favourite or favorite
- +
  - Go+gle means there are 1 or more o, which matches Gogle, Google, Gooogle, but not Ggle
  - G(oo)+gle matches any version of "Google" taht has an even number of o's
  - Go{0,6}gle mathes Google with 0-6 o.
  - .+ means one or more any characters. e.g. ^T.+e$
  - g(oo|ee)gle matches google or geegle
- ()
  - `([abc])\1([bcd]d)\2{2}`
    - cccdcdcd
- lazy mode
  - `abc*?`matches shortest string, <u>ab</u>cd
- lookahead
  - `(?!regex)` negative
    - `abc(?![abc])` matches "abcx", but not "abcc"
  - `(?=regex)` positive
- lookbehind
  - `(?<!regex)` negative
  - `(?<=regex)` positive

#### Sed

打印

- sed -n "2p" filename //print 文件里的第二行
- sed -n "2,5p" filename //print 文件里的第二至五行
- sed -n "2~3p" filename //print文件里的第二行及每三行的一行
- sed "1d" filename //删掉第一行
- sed "1~2d" filename //删掉奇数行

替换

- sed s/cat/tac/g filename //把文件里的每个cat都变成tac
- echo “abcbcdeabcacb” | sed s/abc/123/g //“123bcde123acb”
- echo “abcbcdeabcacb” | tr abc 123 //“12323de123132”
- &表示原来搜到的express
  - sed -E "s/(abc){2,}/&++/g" 	//在abcabc后面加++

删除

- sed -E "/(abc){2,}/d"	//删掉所有abcabc+

### tr

Basically a mapping method.

- echo "12345" | tr "12" "ab” //xy345

- echo "12345" | tr "1231" "xyzs" //syz45

- echo "12345" | tr "12345" "xyz" //xyzzz

- echo "12345" | tr "12" "xyz" //xy345

  

- echo "12345" | tr "123" [xyz] //[xy45

- echo "1234335" | tr [13] [xz] //x2z4zz5

- echo "mississippi" | tr -s "s"



tr -s  "(chars)"， 删去连续重复的，只保留一个

tr -d "(chars)"，删去所有的

- echo "mississsippi" | tr -s "sp" //misisipi
- echo "mississippi" | tr -d "sp" //miiii

#### Grep

- grep regex filename
- grep —color …… 显示颜色
- e.g. grep abc* test //匹配test里面任何含abc的行
- grep regex * //匹配所有文件里的regex



- grep -v regex filename //匹配filename里不含regex的行

- grep -E "regex" filename //extended match, 匹配EBE

- grep -F "…" filename //fixed string 只精准匹配，不是regex

- -i 忽略大小写

- -n 显示行号

- -S 

- -P 使用perl语法，支持lookbehind等

- -o 仅显示匹配上的部分

- 查找出匹配的搜索结果前n行、后n行或前后n行，命令如下：

   grep **-A** 2 "AbC" text.txt

   grep **-B** 2 "AbC" text.txt

   grep **-C** 2 "AbC" text.txt

   

#### awk

- Syntax:	awk options 'selection _criteria {action}' inputfile > outputfile
  - `awk {print $1} ` prints the first word in every single line
  - $0 为whole line



## 文件处理

### Decompress

 tar -xzvf filename.tar.gz

– Option ܆x: --extract
– Option ܆z: --gzip
– Option ܆v: --verbose
– Option ܆f: --file

| 压缩包格式                   | 命令                 |
| :--------------------------- | :------------------- |
| 解压.tar.gz                  | tar zxvf xxx.tar.gz  |
| .tgz                         |                      |
| .tar.bz2                     | tar jxvf xxx.tar.bz2 |
| 压缩to tarball (in Makefile) | Tar -cjvf            |



**tar [-]c|x|u|r|t[z|j][v] -f 归档文件 [待打包文件]**

```shell
tar czf hw9.tgz git-log.txt git-tags.txt \
  quote-patch.txt quote-3.0-patch.txt formatted-patch.txt
```

将多个文件打包为一个归档文件，可以在打包的同时进行压缩。支持的格式为 tar（归档）、gz（压缩）、bz2（压缩率更高，比较耗时）

| 操作选项       | -c                                             | 创建             |
| -------------- | ---------------------------------------------- | ---------------- |
| -x             | 解包                                           |                  |
| -u             | 更新                                           |                  |
| -r             | 添加                                           |                  |
| -t             | 查看                                           |                  |
| -d             | 比较压缩包内文件和文件                         |                  |
| -A             | 将 tar 文件添加到归档文件中                    |                  |
| 格式选项       | -z                                             | 使用 gz 压缩格式 |
| -j             | 使用 bz2 压缩格式                              |                  |
| 其它           | -v                                             | 显示过程         |
| -f 文件名      | 归档文件的文件名，使用 **-** 代表标准输入/输出 |                  |
| -C 解压路径    | 将压缩包中的文件解压到指定目录                 |                  |
| --exclude=文件 | 排除文件                                       |                  |
| -P             | 使用绝对路径压缩时，保留根目录“/”              |                  |
| -W             | 校验                                           |                  |
| -p             | 还原文件权限                                   |                  |
| -w             | 询问用户                                       |                  |
| --totals       | 统计                                           |                  |
| -T 文件列表    | 处理文件列表中的文件                           |                  |
| -X 文件列表    | 排除文件列表中的文件                           |                  |

https://blog.csdn.net/wuhenyan/article/details/53117642

### Compilation

- gcc -Wall hello.c -o hello // -Wall 抓取Error

| 后缀          | 类型                       |
| :------------ | :------------------------- |
| .c            | C语言源代码文件            |
| .a            | 由目标文件构成的档案库文件 |
| .C\|.cc\|.cxx | C++源代码文件              |
| .h            | 程序所包含的头文件         |
| .i            | 预处理过的C源代码文件      |
| .ii           | 预处理过的C++源代码文件    |
| .m            | Objective-C源代码文件      |
| .o            | 编译后的目标文件           |
| .s            | 汇编语言源代码文件         |
| .S            | 预编译的汇编语言源代码文件 |



| -c                | 只编译，*.o，不链接成为可执行文件                            |
| ----------------- | ------------------------------------------------------------ |
| -o 文件名         | 设定输出文件名。默认为`a.out`                                |
| -g                | 加入调试符号(默认)。![1](https://i.linuxtoy.org/docs/guide/images/callouts/1.png) |
| -O                | 编译、链接时进行优化，耗时比较多，但产生的可执行文件执行效率更高 |
| -O2               | 更高的优化级别，耗时更多                                     |
| -ldl              | link executable with a library called libel                  |
| -rPath $path      |                                                              |
| -lctest           |                                                              |
| -L$path dynamic.c |                                                              |
| -fPIC             | *.so *.c. //need -Wl rpath                                   |

第一步：进行预编译，使用 -E 参数
gcc -E test.c -o test.i
查看 test.i 文件中的内容，会发现 stdio.h 的内容确实都插到文件里去了，而其他应当被预处理的宏定义也都做了相应的处理。
第二步：将 test.i 编译为目标代码，使用 -c 参数
gcc -c test.c -o test.o
第三步：生成汇编源文件
gcc -S test.c -o test.s
第四步：将生成的目标文件链接成可执行文件

gcc test.o - o test

(1) -I 
可以向 gcc 的头文件搜索路径中添加新的目录。
(2) -L 
如果使用了不在标准位置的库文件，那么可以通过 -L 选项向 gcc 的库文件搜索路径中添加新的目录。
(3) -l 

Linux下的库文件在命名时有一个约定，就是应该以 lib 这3个字母开头，由于所有的库文件都遵循了同样的规范，因此在用 -l 选项指定链接的库文件名时可以省去 lib 这3个字母。例如，gcc 在对 -lfoo 进行处理时，会自动去链接名为 libfoo.so 的文件。

### 静态链接库

静态链接库是后缀名为.a的文件。它有多个后缀为你.o的目标文件组成。

使用`-c`参数可以使编译在链接前终止，所以生成的是源文件对应的目标文件。

```
gcc -c addvec.c multvec.c
ar rcs libvector.a addvec.o multvec.o
```

`ar`是archive档案的缩写。上面命令生成了.a的静态库文件，在链接时，要如下：

```
gcc -c main2.c
gcc -static -o p2 main2.o ./libvector.a
```

### 动态链接库

后缀名为.so的是动态共享链接库文件，其中的s就是shared共享的意思，如下命令：

```
gcc -shared -fPIC -o libvector.so addvec.c multvec.c
gcc -o p2 main2.c ./libvector.so
```

完成了生成.so以及链接.so的操作。-fPIC指示生成与位置无关的代码。

### -l

```
gcc -o temp temp.c -lm
```

**-lm**选项，在编译时会进入系统库路径搜索，链接“数学库”。常用的库会自动链接，无需指定。
系统缺省的库路径为：/lib、/usr/lib、/usr/local/lib、/usr/lib64。

> 数学库的文件可能为*libm-2.1.2.so*去掉lib和后面的版本号就只剩下m了。

### -L

如果该库不在系统缺省路径下（比如第三方库，自定义的库），还要使用**-L**选项指定路径。

```
-L/home/jelly/mylib
```

### -Wl,-rpath

**-L**选项指定的是在编译期间库的搜索路径，然而如果是动态库的话，在运行时加载库，此时只会搜索默认库路径。
此时需在编译时加上**-Wl,-rpath=**后面指定路径。注意这不是两个选项。

```
g++ -I ../include -Wl,-rpath=../util/ -lwang -L../util/  client.c -o client
```

## 包含非系统的头文件

`-I`选项指定头文件的位置。一般和L选项联用。比如：

```
gcc mysql_test.c -I /usr/local/include/mysql -L/usr/local/lib -lmysqlclient -o test
```

## -M检查所需的头文件

```
gcc -M main.c
```

以makefile风格显示源文件的依赖关系。会列出所有包含的所有头文件。会列出标准库的头文件。 如果不想显示标准库的头文件，请使用**-MM**选项代替**-M**。

### make

| 目标           | 用途                                                      |
| :------------- | :-------------------------------------------------------- |
| make all       | 产生预设的目标，只敲入**make**也可以                      |
| make clean     | 清除编译结果                                              |
| make distclean | 除了清除编译结果，也把configure所产生的 `Makefile` 清除掉 |
| make install   | 将程序安装到系统中                                        |
| make dist      | 将程序和相关的文档打包为一个压缩文档以供发布              |
| make distcheck | 打包并检验                                                |



### 符号

- $* 　　不包含扩展名的目标文件名称。 
- $+ 　　所有的依赖文件，以空格分开，并以出现的先后为序，可能包含重复的依赖文件。 
- $< 　　第一个依赖文件的名称。 
- $? 　　所有的依赖文件，以空格分开，这些依赖文件的修改日期比目标的创建日期晚。 
- $@ 　 目标的完整名称。 
- $^ 　　所有的依赖文件，以空格分开，不包含重复的依赖文件。 
- $% 如果目标是归档成员，则该变量表示目标的归档成员名称。

# 语法

### Sh

- ls *.sh

- cat hello.sh

- Declared using =

  var="Hello" #no space!!!

- Reference using $

  echo $var

  - echo "first arg is $1"

    ./echo hello

    first arg is hello

- echo -e "Hello\nWorld"

  Hello

  World

  - #### if

  ```sh
  #!/bin/bash
  if [ 5 -gt 1 ]
  then
          echo "5 greater than 1"
  else
          echo "error"
  fi
  
  COUNT=6
  while [ $COUNT -gt 0 ]
  do
  	echo "Value of count is $COUNT"
  	((COUNT=COUNT-1))
  
  遍历文件夹下的文件：for file in `ls $dir/*.wav`
	修改后缀：`echo $file| sed 's/mp3/wav/g'`
  删除路径的前面：`echo $file | sed 's/^.*\///g'`
  匹配后缀：if [ ${file##*.} = "mp3" ] # ##*是贪婪匹配字符，匹配到最后一个.
  
  ```
  
  #### 

### Python

- type(print) //str
- print(xxx)
- if(condition):
- for i in range(10):



#### Dictionary

- Basically a hash table
- d = {1: 'adam', 2: 'hi'}
- d[xxx] = yyy

## GDB

- run //r
- Break <function>//b
- continue //c
- stepi
- step
- x <address>
  - x 0x400771
  - x/c for char, x/x for 16, x/d for 10
  - x/i 0x400771
  - x/i $rip
  - x/4i $rip
  - x/10i main
  - x/-4i $rip
  - x/s 0x4008e0 //
- x/20xb 0x4008e0 //bytes
- si//current position?
- ni //necti
- Print $rsi
- p/x $rsi
- p/c 65
- x/20xb 0x4008c8



## Linux Basics

- bin

  可执行文件，程序的可执行文件通常在这个目录下。在环境变量中设定搜索路径，就可以直接执行，而不需要定位其路径。

- etc

  配置文件，大部分系统程序的配置文件保存于 /etc 目录，便于集中修改。

- lib

  库文件，集中在一起，方便共享给不同程序。相较不同的软件单独保存库文件，能够节约一些磁盘空间。

- share

  程序运行所需要的其它资源，例如图标、文本。这部分文件是专有的，不需要共享；而且目录结构相对复杂，混放在一起比较混乱，所以单独存放。

  ### 执行命令的权限

  有一些命令，普通用户也可以执行，但是只有 root用户 才能执行成功，这是为什么呢？

  例如在系统中增加一个新用户 useradd，我们看看这个命令的程序文件

  ```
  ls -l /usr/sbin/useradd     
  
  -rwxr-xr-x 1 root root 56156 2006-04-03 21:37 /usr/sbin/useradd 
  ```

  所有的用户都可以执行？

  这是因为， useradd 命令是修改 `/etc/passwd` 文件的一个工具，来看看这个文件：

  ```
  ls -l /etc/passwd
  
  -rw-r--r-- 1 root root 1835 2006-06-24 17:58 /etc/passwd      
  ```

  原来只有 root用户 才能写入修改结果，非 root用户 执行 useradd 命令当然不会有结果。

您可以使用 su （switch user）这个命令来切换其它用户。

例如 **su root** ，切换到 root用户(如果 su 命令后面没有参数，那么这个命令默认切换到 root用户)。

当您执行 su 这个命令，系统会提示您输入密码，请输入管理员的密码。这个时候，您会发现命令提示符末位变成了 **#** ，您将以 root用户 的身份执行命令。

## GPG

#### 改owner

useradd

Chown 

chmod

#### Download from beaglebone

scp root@192.168.7.2:/root/eeprom eeprom



#### Make detached sig

gpg --output eeprom.sig --detach-sig eeprom



You need a passphrase to unlock the secret key for

user: "Wenxuan Liu (RSA key with 2048 bits) <allenliux@163.com>"

2048-bit RSA key, ID 5072131F, created 2019-05-30



File `eeprom.sig' exists. Overwrite? (y/N) y



#### generate key

ssh-keygen -t rsa

Generating public/private rsa key pair.



#### Verify

$ gpg2 --verify eeprom.sig 

gpg: Signature made Thu May 30 18:13:42 2019 PDT using RSA key ID 5072131F

gpg: Good signature from "Wenxuan Liu (RSA key with 2048 bits) <allenliux@163.com>"



$ gpg --verify eeprom.sig eeprom

gpg: Signature made Thu May 30 18:13:42 2019 PDT using RSA key ID 5072131F

gpg: Good signature from "Wenxuan Liu (RSA key with 2048 bits) <allenliux@163.com>"



```c++
{　open brace; open curly　左花括号

}　close brace; close curly　右花括号

(　open parenthesis; open paren　左圆括号

)　close parenthesis; close paren　右圆括号

() brakets; parentheses　括号

[　open bracket 左方括号

]　close bracket 右方括号

[] square brackets　方括号

.　period; dot　句号；点

|　vertical bar; vertical virgule　竖线

&　ampersand; and; reference; ref　和；引用

*　asterisk; multiply; star; pointer　星号；乘号；星；指针

/　slash; divide; oblique 斜线；斜杠；除号

//　slash-slash; comment 双斜线；注释符

#　pound　井号

\　backslash; sometimes escape　反斜线转义符；有时表示转义符或续行符

~　tilde　波浪符

.　full stop　句号

,　comma　逗号

:　colon　冒号

;　semicolon　分号

?　question mark　问号

!　exclamation mark (英式英语)；exclamation point (美式英语)

'　apostrophe　撇号；省字符

-　hyphen　连字号

-- dash 破折号

...　dots/ellipsis　省略号

"　single quotation marks 单引号

""　double quotation marks 双引号

‖ parallel 双线号
```



## Pthread

#### 一、 创建/终止线程

创建一个文件pthreadTest1

```python
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

 void* xc(void* arg){
           char* c=(char*)arg;
           printf("参数%s \n",c);
           int i=0;
        for (;i<10;i++){
                 printf("循环%d\n",i);
                   if(i==5){
                       pthread_exit(1090000000);
               }
      }
             return 100000222;
 }

 void main(){
         
        pthread_t tid;
        pthread_create(&tid,NULL,xc,"线程！！！！");

        void *status;
        pthread_join(tid,&status);
        printf("返回%d\n",(int)status);
}
```

编译

```
gcc  pthreadTest1.c  -o  pthreadTest1  -lpthread
```

运行

```
./pthreadTest1
```

结果:

```
参数线程！！！！ 
循环0
循环1
循环2
循环3
循环4
循环5
返回1090000000
```



#### 二、线程同步

创建一个文件pthreadTest2

```python
#include <stdlib.h>                                                         
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int i = 0;
//互斥锁
pthread_mutex_t mutex;

void* thr_fun(void* arg){
    //加锁
    pthread_mutex_lock(&mutex);
    char* no = (char*)arg;
    for(;i < 5; i++){
        printf("%s thread, i:%d\n",no,i);
        sleep(1);
    }
    i=0;
    //解锁
    pthread_mutex_unlock(&mutex);
}

void main(){
    pthread_t tid1, tid2;
    //初始化互斥锁
    pthread_mutex_init(&mutex,NULL);

    pthread_create(&tid1,NULL,thr_fun,"No1");
    pthread_create(&tid2,NULL,thr_fun,"No2");

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    //销毁互斥锁
    pthread_mutex_destroy(&mutex);
}
```

运行结果

```
No2 thread, i:0
No2 thread, i:1
No2 thread, i:2
No2 thread, i:3
No2 thread, i:4
No1 thread, i:0
No1 thread, i:1
No1 thread, i:2
No1 thread, i:3
No1 thread, i:4
```

#### 三、生产消费者线程

```python
#include <stdlib.h>                                                      
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//消费者数量
#define CONSUMER_NUM 2
//生产者数量
#define PRODUCER_NUM 1

pthread_t pids[CONSUMER_NUM+PRODUCER_NUM];

//产品队列
int ready = 0;

//互斥锁
pthread_mutex_t mutex;
//条件变量
pthread_cond_t has_product;

//生产
void* producer(void* arg){
    int no = (int)arg;
    //条件变量
    for(;;){
        pthread_mutex_lock(&mutex);
        //往队列中添加产品
        ready++;
        printf("producer %d, produce product\n",no);
        //fflush(NULL);
        //通知消费者，有新的产品可以消费了
        //会阻塞输出
        pthread_cond_signal(&has_product);
        printf("producer %d, singal\n",no);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

//消费者
void* consumer(void* arg){
    int num = (int)arg;
    for(;;){
        pthread_mutex_lock(&mutex);
        //while?
        //superious wake ‘惊群效应’
        while(ready==0){
            //没有产品，继续等待
            //1.阻塞等待has_product被唤醒
            //2.释放互斥锁，pthread_mutex_unlock
            //3.被唤醒时，解除阻塞，重新申请获得互斥锁pthread_mutex_lock
            printf("%d consumer wait\n",num);
            pthread_cond_wait(&has_product,&mutex);
        }
        //有产品，消费产品
        ready--;
        printf("%d consume product\n",num);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}


void main(){
    //初始化互斥锁和条件变量                                                
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&has_product,NULL);
    printf("init\n");

    int i;
    for(i=0; i<PRODUCER_NUM;i++){
        //生产者线程
        printf("%d\n",i);
        pthread_create(&pids[i],NULL,producer,(void*)i);
    }
    
    for(i=0; i<CONSUMER_NUM;i++){
        //消费者线程
        pthread_create(&pids[PRODUCER_NUM+i],NULL,consumer,(void*)i);
    }
    
    //等待
    sleep(10);
    for(i=0; i<PRODUCER_NUM+CONSUMER_NUM;i++){
        pthread_join(pids[i],NULL);
    }
    
    //销毁互斥锁和条件变量
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&has_product);
    
}
```
