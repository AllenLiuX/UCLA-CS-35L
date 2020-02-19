### CS 35L ClassNote

##### 09.30 Linux and operating system

- Everything in Unix is a file
  - regular file, directory, symbolic file(ln - s), device file(cd/dev)
- Each file has permission:
  - permission groups: owner, group, all users
  - Permission Types: Read, write , execute

###### Basic Commands

- man
- cd (relative vs absolute paths)
  - pwd: see the directory you are in
  - cd ~: home directory
  - cd /: root directory
  - cd search the directory under the current one; if want to go from root: cd /Library
  - start from the root==absolute path; start from cur == relative path
  - cd .: current directory
  - cd ..: parent directory
- mv, cp, mkdir, rm, ls
  - ls: what is under this current directory
    - ls -l: information about files under the current directory
      - -rw-r--r—: from the second letter: owner, group, all users
      - r: read; w: write; e: execute
      - first character: type of the file: d=directory; -=regular file
    - chmod: change permission of a file
      - chmod  662(110 110 010) test3.txt: 1 means grant permission and 0 means no==> 3 binary number represent a number
      - =: the mode specified are to be made the exact modes for the specified classes
      - u: user; g: group; o: others; a: all
    - ls -a: show every thing, include the hidden files, in the directory
    - ls -al: details in every files
  - mv source destination: mv test.txt .. (move it to its parent directory)
    - Mv test2.txt test10.txt (change name)
    - mv ../test3.txt ../test2.txt . (mutiple sources)
  - cp source destination: cp test.txt ..(copy it to its parent directory)
    - cp test.txt ../test11.txt (copy & rename)
    - if copy multiply things, the last one can only be a directory
    - cp test10.txt test3.txt ..
  - mkdir name: make a directory with name under the current directory
    - mkdir ../temp3: make temp3 at the parent directory
  - touch test.txt: create a file called test.txt
  - rm test100.txt: remove the file named test100.txt
  - rmdir tmp3: remove the directory called tmp3
- ln: soft vs hard link
- whereis cd: check where the command cd is
- **echo** $PATH(list of special directories where the built in programs are stored, separated by :); call whereis, the system search the path one by one
- ./program: run the program under the current directory; if type program directly, the system treats it as a command and search through path ==> not found
- Change path: export PATH=/usr/local/cs/bin:$PATH (update the new path with old one)
- file path: the information about the file and path
- Scp
  - Download file: scp classrui@[server]:[remote path] [local path]
  - Upload: scp [local path] classrui@[server]:[remote]
  - Add option -r if it's a directory

##### 10.02 Linux continus

###### Symbolic link vs. hard link

- symbolic link: points to a file （first find soft link, then find the txt, then inode to find the file)

- Hard link: directly points to node
- Create a hard link: ln file name the link name
- Create a symbolic link: ln -s [file name] [the link name]
- ls -i: the id of the node

###### More command

- find
  - find files whose name, type, or other features matches with the criteria
  - find ./temp1 -name "hard_link" ==> find the file with name "hard_link" in ./temp1
  - "*link" =>search anything end with link
  - "?link" ==> any character+link
  - find . -name "?link" -type f (regular file)
- cat: concatination => display everything about the file on the screen
- Head: head -n 100==>shows the first 100 lines // tail -n 100 ==> the last 100 lines
- more: full screen of the file (enter one line down; space one page down)
- less: after quit, disappear ==> no trace
- ps: the process (code) that is running
- kill: delete the process that is running
- sudo: give the root privilege to execute the command
- ">" => the result of the previous output is printed to the next one
- grep ==> catch the line that contains the keyword  searched
  - grep "tan" < tlink (the later one is the input of grep)
-  "|" the output of the previous becomes the input of the next one
- wget/curl url ==> download the file
  - wget url > temp.txt

###### Emacs

moving around:

- emacs filename: open it in emacs
- c-x c-c: exit; c-h t: tutorial
- c-d: delete forward; c-b: backword; c-f:forward; 
- m-l: one word forward
- m-d: delete a word forward; m-delete: delete a word backward
- c-a: begining of the line
- c-k: delete after the cursor

Run command:

- m-shift-1: shell command
- m-x shell: run the command

Buffer:

- c-x c-b show all the buffers
- c-x b: switch to buffer

##### 10.07 Shell scripting

###### Compiled vs. Interpreted Languages

Compiled Languages: (C, C++...)

- First **compiled** (into binary code) before run: Source code to object code; then executed
- Run faster (precompiled, everything already in binary, no other things needed; compilation optimizes lots of things; debugging easier before running)

Interpreted Languages: (Python, javascript...)

- No compilation required: **Interpreter** (translator, do it at run time) reads program, translates into internal form and executes
- Run easier (doing translation while running , slower; during the run-time, lots of extra errors; no need to compile ==> easier)

###### Shells

Shell is a program that takes commands from the keybroad and gives them to the operaitng system to perform:

- Outermost cover of the kernel
- User's interface to the OS
- Use the shell to run other programs

Bourne shell, C shell, Bash, kernel shell...

###### Shell Scripts

- Shell scripts: Interpreted language; can be executed inside a script

Why use a shell script? 

- Compatible with command line
- simplicity: quicker development

nano test.sh

/bin/sh: default interpreter; other standard: **bash**, dash, ...

井号!/bin/sh: identify the interpreter

Variable

- var=123(no white space); echo $var (print it out)
- varstring="456$var" (a string) ==>print 456123
- varstrings='456$var' ==>print 456dollarvar
- varstrings="1 3 4"
- while using it, use the $

Calculation

- print out the calculation result

- ```shell
  echo $(($var+$var))
  ```

Commands

- just type in the command: ls, mv, ...

- If need to store the command in variable:

- ```shell
  ret=`ls -l .` or ret=$(ls -al)
  ```

If-statements

```shell
if [ $var == 123 ] //space is important!!!
then
 echo equal
elif [ $var == 456 ]
then
 echo 456
else
 echo "not equal"
fi //end of the if statement

if [ -e "/var/log" ] 
#see if a file/directory exist in the operating system
then
 echo exist
elif [-f "/var/log/syslog"]
#test a regular file
then
 echo exist file
else
 echo "not exist"
fi
```

Loops

- while loop

```shell
while [ $i -lt 3 ]
#-lt is the option for less
#-le less and equal to
#-gt greater
#-ge greater and equal to
#-eq equal to (comparing numbers)
#== compare strings
do
 i=$(($i+1))
 echo $i
 output="$output $i"
done
```

- for loop

- ```shell
  l="a b c"
  l=`ls /`
  for i in $l
  #iterate through elements separated by space,
  #in this case, every file under the root
  #i is an assignment, no need $
  do
   echo $i
  done
  
  l=`ls /`
  for i in $l
  do
   if [ ! -d "/$i"]
   # ! means no
   then
    break
    echo "directory"
   else
    echo "regular file"
   fi
  done
  ```

Functions

```shell
function function_name{
  a="test"
  echo $1 $2
  #$1 and $2 specify argument passed in
  echo $a
  echo $0
  #$0 is the name of this program
  b="return"
  #b is global
}
function_name arg1 arg2
echo $b

command line: ./test.sh arg1 arg2
Then
echo $1 $2
#print arg1 and arg2, which are the arguments passed to the command line
#do not conflict with what is inside the function

$0 or ./test.sh
#recursion

spcial variables:
echo $* all the argument
echo $# #of arguments
echo $$ ????
```

Arrays

```shell
#a number array from 1 to 10
for i in {1..10}
do
 echo $i
done

teststr=12345
echo ${#teststr} //size of the string
```

##### 10.09 Regular Expression

regextester.com ==>website for regular expression

###### Basic Use

- Greedy: Always try to find the longest match
- Lazy: Always to try to match the shortest one
- Enable lazy by adding a ? after quantifier ==> abc*? (shortest string)

Character class

- .: any character (exactly one)
- \d: a signal digit
- \D: not a digit
- [abc]: anything either a or b or c (short cut: a-c to represent abc)
- [ ^abc]: anything that not belong to a or b or c

Anchors

- ^d$: start with d and end with d
- \: define it as the original meaning

Groups

- (ty){1,4}e: ty could occur 1 to 4 times (group ty together)
- group has the highest precedence
- Mississippi: (i|s|p)\1
- (?: [abc]): will not be matched by \1, the one following it the \1

Quantifiers

- tya+: start with ty and followed with a, a occurs one or more time
- tya*: 0 or more a
- tya{2}: a occurs exactly 2 times
- tya{2,4}: a occurs 2 to 4 times

Alternation

- ab|cd: match ab or cd; lowest precedence, need to group it
- [abc] [abc]: ab ac ca cb cc (anything within abc)
- ([abc])\1: the second character to be the same with the first group: aa, bb, cc
- ([abc])([bcd])\1\2: ccdd ==> \2 refers to the second group

###### Lookaround

- Lookahead: Match something (not) **followed** by something else regex在后面
  - (?!regex) negative lookahead
  - (?=regex) positive lookahead
- Lookbehind: backwards regex在前面
  - (?<!regex) negative lookbehind
  - (?<=regex) positive lookbehind 
  - .* regex .* means anywhere

###### BRE vs. ERE

In BRE, a few characters lose special meaning:

- ?, +, {}...
- need to escape them by \

###### Command

- Grep: search for a pattern file and display all matched lines
  - -E: extended grep
    - grep -E "(abc){2}" text.txt
  - -R: go recursively all the files in this directory
  - -S: all symbolic links are not followed
- tr "reg" "replacement": translate one into another one
- sed
  - Stream editor
  - Can perform lot's of function on file like searching, find and replace, insertion or deletion
  - sed -E 's/regex/replacement/flags' (s for substitute) (flags: g gives all the occurances within a signle line) //regular one for default
  - sed '/regex/d' remove the search result
  - sed -E 's/(abc){2,}/(&)/g': replace the search result with (search_result)
  - sed 's_ (abc) _ d': _ can replace /
- awk:
  - Scans a file line by line
  - Splits each input line into fields (by space)
  - Compares input lin to pattern
  - Performs actions on matched lines
  - Syntax: awk options 'selection_criteria {action}' input-file>output-file
  - Commands:
    - awk '{print $1}' lab2_awk.txt //print the first token in every single line;
    - $0 or not specify anything prints out the entire line
    - awk '/student/ {print $1}' lab2_awk.txt //wrap the criteria with a /
- locale: specify the settings of the system

##### 10.14 Python

```python
type(a) #class

print(a,b,"new string", sep="|",end="|") #the default for end is '\n'

s.split(',') #==>create a list from s, each component is separated by ','

Test_tuple = (1,3.0,"test") #==> not mutable, mixer of types

Test_dict = {key:val} #the key entry can be a tuple
Test_dict.keys() /values() /items()

for i in range (a,b,2)
#start from a end with b, increment by 2

class className:
  __private=2 #__makes it private
  var1 = 3
  var2 = 5
  def __init__(self, v):
    var1 = v
  def func(self, argu1, argu2): #must have an argument called self
    temp = argu1 + argu2 + self.var1
    ...
 
t = className(10)
ret = t.function_name(1,2)
print(t._className__private)

try:
  func_name(1,2,3)
 except TypeError:
  print("error")
  #not exit with file status, can continue the program even facing the error
  
  s = input("Please input:")
  print(s)
  
  f = open('p.txt', 'w') #open the file with over-writing permission
  f = open('p.txt', 'a') #open the file with appending permission
  #if open the file with write permission, cannot read it
  #check r+, w+, r+
  for line in f:
    print(line)
  f.write("anything")
  
  import os
  os.system("ls") #call a command from python
  os.mkdir("test2")
  
```

##### 10.16

How to install software?

- linux: rpm(redhat package management), apt-get(advanced package tool), yum(yellow dog updater, modified)

Decompress Tarball

- tar -xzvf

Compile:

- g++ xx -c xx (for each source file, compile it but not linking)
- g++ xx -o shop (if changed some file, just recompile the changed file but not the entire thing)
- But, whenever the header file is changed, every project linked to it will need recompile

Makefile example:

- make ==> automatically check which part need to be recompiled which not; efficient compilation & keep them up-to-date
  - A rule: target + prerequisites (depends on these files to run)
  - Commands: compile & run
  - clean: clean up all the installed binaries
  - make clean ==> find a target to clean and execute the command

Build Process:

- Configure: script that checks details about the machien before installation (dependency between packages)
  - creates 'Makefile' based on (will not automatically have a Makefile in the project that fits all the system; but created by configure)
- make
  - requires Makefile to run
  - Compiles the file and creates executables in current directory
- make install
  - make utility searches for target named install within the Makefile
  - Conventionally, executables are copied into the **final** directories (system directories)

Patching:

- A patch is a piece of software designed to fix problems with or update a computer program
- It's a diff file that contains the difference been made to the original file
- A person has the original file can use patch + diff to add changes to the original file
- diff -u original modified

Optparse Library: (powerful library for parsing command-line options)

- Argument: 
  - string entered on the commadn line and passed in to the script
  - Elements of sys.argv[1:] (sys.argu[0] is the name of the program)
- Option:
  - An argument that supplies extra information to customize the execution of a program
- from optparse import OptionParser



##### 10.21 C programming

Variable type: int/long — 4 bytes; float/double; char

print statement: printf("%c\n", ch) //%c stands for character; %p stands for pointer

preferred for loop: initialize i outside of loop

###### Functions:

- Not an object-oriented language; do not have functions for structures
- No function overloading
- include <test.h> // include "test.h" 
  - standard library uses <>
  - own header file uses "" //within the same directory

###### Passing a Parameter:

- Pssing by value (在程序里面change不会change外面的参数)
- Passing by reference: receives a pointer

###### Pointer to function:

```c
double(*) (double, double) fn_ptr;
fn_ptr = pow;
result = (*fn_ptr)(1.5, 2.0)
```

###### Array:

```c
int arr1[10];
int arr[]={10,20,30,40}; //the variable points to the starting point in the array
int size = sizeof(arr1);
```

- Assigning any address to an array variable is not allowed
- Size of pointer returns pointer size; size of array returns the total bytes in the array

###### Struct

```C
struct Student{
  char name[64];
  ...
};
struct Student s;

typedef struct{
  char name[64];
  ...
}Student;
Student s;
```

###### Memory management

```C
#include <stdlib.h>
void *malloc(size_t size)
//allocates size bytes and returns a pointer to the allocated memory

void realloc(void *ptr, size_t size);
//changes the size of memory block pointer to by ptr to size bytes

void free(void *ptr);
//free the block of memory
```

###### I/O

argc: count user input

argv: array of user input

```C
fopen(); //open a file
int fprintf(FILE *fp, const char* format, ..);
int fscanf(FILE *fp, const char* format, ..)
```

###### Macros

```C
#define BUFFER_ZIE 1024 //a constant
#define min(X,Y)((X)<(Y)?(X):(Y))
//not compiled, but replace its occurance with actual value in preprocessing
//function-like Macro: replaced in preprocessing, not calling other functions in run-time, faster b/c inline
```



##### 10.25

###### GDP Basics

Breakpoint:

- s ==> step into function

- n ==> step over function

- f ==> leave the breakpoint

Variables:

- print [var_name] //*pointer can prints out the content inside the pointer
- set var[var_name] = [ value]
- backtrace bt: trace stack returns

Watchpoints:

- watch <var_name>

Information

- list; info breakpoints; info args; info locals (print out all the local variables)

Running:

- gcc -g -o temp temp.c: allows gdb to debug for the compiled source code
- r 1 2 ==> input arguments 1 and 2
- b <function_name>
- list: show the content for this line
- set listsize n ==> print n lines

```c
#include <stdlib.h>
#include <stdio.h>
int main(){
  int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
  }
  int var[]={1, 20. 5, 10};
  int i;
  for(i=0; i<4; i+=1){
    printf("%d\n", var[i]);
  }
  qsort(var, 4, sizeof(int), compare);
}
```

##### 10.30 System call

Process

- A process is a program during execution
- OS enforces restricted rights on process

###### Dual mode operation:

- User mode: processor checks instructions, call the API and kernel do the job safely (the kernel is safe; does not do something harmful)
- Kernel mode: unrestricted rights

Transition from User to Kernel

- Exceptions: User program acts silly

- Interrupts: hardware requires OS

- System call

###### System calls

- Defined as a request ot the operating system to do something on behalf of the program
- Provide the interface between a running program and the operating system (process is time-consuming)
- Usage: managing file I/O, handling user input. acess control, time management

Overhead: system calls are expensive and can hurt performance (avoid it as much as possible)

Making a system call

- directly available to the programming languages
- the same as calling a procedure or function
- Programmer invokes the API, which invokes the actual system call

Library calls vs System calls

- When you call printf(), it eventually ends up with a system call (wrappers of system call)
- Why still have printf()? more features, abstraction among different OS, more efficient (merge two calls into system call into only one, buffered)

###### Unbuffered vs. Buffered I/O

Unbuffered: Every byte is read/written by the kernel through a system call

Buffered: collect as many bytes as possible and read more than single byte at a time; decreases the number of read and write system calls (overhead)

###### File descriptor

- And integer that uniquely identifies an open file of the process
- File descriptor table is the collection of integer array indices that are file descriptors in which elements are **pointers** to file table entries
- For regular file: get descriptor using "open"
- Some special
  - Read from stdin ==> read from fd 0
  - Write to stdout == written to stdout in screen through fd 1
  - Write to stderr ==> fd 2

###### System call example

```C
int fd = int open(const cahr *path, int oflags, mode_t mode)
Flags: O_RDONLY,...
Use Flag1 | Flag2 for mutiple instructions
return the file descriptor

int close(int fd)
return 0 on sucess and -1 on error

size_t read(int fd, void* buf, size_t n);
buf: buffer to store the read data
n: length of buffer
returns: number of bytes read on success, 0 on reaching end of file, -1 on error

size_t write(int fd, void* buf, size_t n);
buf: buffer to read from
n: length of buffer
returns: number of bytes written on success, 0 on reaching end of file, -1 on error

int fstat(int fildes, struct stat *buf);
save the statistics of the file(indicated by descriptor) into buf

off_t lseek(int fildes, off_t offset, int whence);
move the pointer around when read/write
offset: move by n bytes forward
whence:
SEEK_SET: The file offset is set to offset bytes
SEEK_CUR: The file offset is set to its current location plus offset bytes
```

###### Time command

- Purpose: check the execution time of a command
- time [command]; eg. time ls | grep "test"
- Real: actual time run in total
- User: amount of CPU time spent in user mode
- Sys: amount of CPU time spent in kernel mode

###### Strace command

- Purpose: trace system calls and signals
- strace ./test ==> list all the system calls

```C
#include <studio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	int fd = open("file.txt", O_RONLY);
	if(fd<0){
  	exit(1);
  	perror("read error!");
	}
	char buf[40];
	int res = read(fd, buf, 8);
	if(res<0){
  perror("read error!");
	}
  //printf("%s\n", buf);
  write(1, buf, 8);
  
  struct stat st;
  fstat(fd, &st);
  print("%d\n", st.st_size);
  lseek(fd, 0, SEEK_SET);
  lseek(fd, -2, SEEK_CUR);
  
	close(fd);
	return 0;
}
```

##### 11.4

###### Dynamic linking:

- Loaded and used at any time while a program is running
- Loaded at program start-up
- Shared linking: only the program; when calls to library, load into the memory (.so)
- Static linking: attach the library files to every single file (.a)

###### Pros and Cons

- The executable is typically smaller
- More flexible for changes
- Concurrency
- Performance 
- Missing libraries (not reliable; library is not there)
- Wrong library version (link to incorrect library)

###### Dynamic Loading

- A mechanism to load shared library to memory at runtime
- Aloow start up in the absense of some library
- Avoid linking unnecessary libraries

###### Create static/dynamic library

1. create a static/shared library (compile)
   - use ar (for static) or gcc (for dynamic)
   - Compile: gcc (-fPIC) -c [file.c] -o [file.o] //add fPIC for dynamic libs
   - Static: ar rcs [libxxx.a] file.o
   - Shared: gcc - shared [file.o] -o [libxxx.so]
2. Link that library when you compile your program
   - Compile you own program
   - gcc - L[path] -l[xxx] [your_main.o] -o [your_main]
   - path: location of library; xxx: name of the library; your main.o: object file
   - -ldl -Wl,-rpath=[path]
   - -ldl: use the dl library (rely on the dynamic linking)
   - -Wl,rpath adds path for runtime libraries
3. If necessary, use dynamic load

Reminder: gcc -L. -lmylib-d main.o -ldl -Wl,rpath=. -o main //ignore the lib before mylib

###### Trace library

- ldd main 
- dlopen()[open the object file], dlsym()[get this function], dlclose()[close the object file], dlerror()

##### 11.6

###### Dynamic loading function calls

- Dlopen: makes an object file accessible to a program
- Dlsym: address of symbol within the object file //load the function into program from library; it is a function pointer
- Dlerror: return error
- Dlclose: closes an object file

Main-load.c

```c
#include <dlfcn.h>
#include <mylib.h>
#include <stdio.h>

int main(){
  void* handle;
  void (*g)(); //a function pointer
  //then load f into g
  handle = dlopen("./libmylib-d.so", RTLD_LAZY); //load when necessary
  if(dlerror()!=NULL){
    printf("error! %s \n", dlerror());
  }
  g = dlsym(handle, "f");
  (*g)();
  dlclose(handle);
  //check the error
  return 0;
}
gcc -o main-load main-load.c -ldl -Wl, -rpath=.
```

###### Makefile

- A target is usually the name of a file that is generated by a program
- A prerequisite is a file that is used as input to create the target (prerequite newer, recompile)
- A recipe is the action that make carriers out
- The recipe will carried out: prerequisite more recent, or target does not exist
- a tab before gcc -g xxx

###### Executing makefile

- When you run make command, goes to first target by default (all: shop...)
- If want to run a specific target, use $ make [target name]
- .PHONY target (all, clean..)
  - by default, make thinks that the target name is a file
  - Use phony target to enforce 'make clean'
- Make file

```C
CC=gcc
//./configure replace gcc with the actual compiler

all: main-load
main-load: main-load.c libmylib-d.so //dependency
	($CC) main-load.c -o main-load -ldl -Wl,-rpath=. //recipe
libmylib-d.so: mylib.h mylib.c
	gcc -fPIC -c mylib.c -o mylib.o
	gcc -shared mylib.o -o libmylib-d.so
clean:
	rm *.o libmylib-d.so main-load
.PHONY: clean
```

- Replace target with $@
- Replace prerequisite with $< (first one)
- $? all prerequisite newer than the target
- $^ all prerequisites



##### 11.13

###### What is git?

- A version control system; free and open source; centralized
- Git was created by Linus in 2005
  - Used for development of the Linux kernel

###### Getting started

- Download Git from offical website
- To config the user
  - git config --global user.name "Your Name"
  - git config --global user.email "email@xxx"
- git init

###### What git does?

- creating snapshots for each version (if something is changed, the entire is saved)
- For each snapshot, files are saved unless it has not been changed

###### Three States

- Working directory: where you change your files; staging area; repository

###### Modifying files

- To add changes to repository
  - git add (add to stage area)
    - git add -A //add mutiple files
    - git add . //all the files under the current directory
  - git commit (put staging area to repo)
  - git commit -m "Initial Commit" //name of this commit; label
- Check status
  - git status // what is in the staging area, what are files that is modified but not added to staging area yet
  - git diff (only text file)
  - git log //history of commits
- .gitignore: stop tracking certain files
- rm -rf .git //do not let git keep track of this repo
- git tag <tag_name>  <hash_>

###### Going back

- git show [commit num] //see what's been changed; a diff file 
- git reset --hard [hash value] (go back to this version)
- git reflog //keep track of all changes/deletions
- Discard changes
  - git checkout -- file (if not staged file; go to the prior version)
  - git reset HEAD file (if staged file) //move back to the working directory; unstaged; then delete it

###### Branches

- git branch //show branches
- git checkout (-b) <branch_name> //switch branches; -b creates a new branch and switch to it
- git merge <branch_name> //merge branch to current branch(dev); manually change conflicts (remove differences indicated by symbols)
- git branch -d <branch_name> //delete a branch
- git log --graph
- master: default branch (the final version are stored); dev: the core branch

###### Make patch

- git format-patch <branch_> -1 <commit_hash>

- git am < patch_name

###### Remote repo

- git clone //clone a remote git repo to local
- git pull
- git push



##### 11.18

Cryptography Terminologies:

- Plaintext: actual message
- CiphertextL encrypted message(unreadable to unintended recipients)
- Encryption: converting from plaintext to ciphertext
- Decryption: ciphertext->plaintext
- Secret key: function to encrypt/decrypt
- Good key makes it secure

###### Symmetric-key Encryption

- Same secret key used for encryption and decryption
- Example: Data Encryption Standard (DSE)
- Caesar's cipher
  - Map the alphabet to a shifted version
  - key = shifted places

###### Public-key Encryption

- Use a pair of keys for encryption
  - Public key-published and well known to everyone
  - Private-secret key known only to the owner
- Encryption
  - Use public key to encrypt messages (everyone)
- Decryption
  - Use private key to decrypt messages
  - send the message using client's public key, and the public key is matched to private key
- Example: RSA

Secure Shell (SSH)

- Telnet
  - Remote access
  - Not encrypted
  - Packet sniffers can intercept sensitive information (username/password)
- SSH
  - run process remotely
  - Encrypted session
  - Session key(secret key) used for encryption during the session
- SSH Initialization
  - version of protocol
  - cryptographic algorithms
  - one-time session key for encrypting the rest of the session
  - Authenticating the server host using its host key
  - Authenticating the client using a password, public key authenticationm, or other means

###### Client Authentication

- Private/public keys authentication: A list of public keys, send the keys to client, if client has the corresponding private key, then it is authorizied
- How to generate pairs of private & public keys? How to push to the server? How to make sure it uses public/private keys to verify me?
- ssh-keygen
- cat id_rsa.pub
- ssh-copy-id: upload client public key to the server

Passphrase-less authentication

- ssh-agent
- Manages private key identities for SSH
- ssh-add



##### 11.20

###### Digital signiture

Data integrity: message consistency

- Signing: hash for data, then encrypt hash using signer's **private** key=> signature + certificate ==> digitally signed data
- Verification: Data -> hash function, decrypt using signer's **public** key; compare whether the same
- If hashes are equal, the signature is valid



##### 11.27

###### Git blob object

- You can save a file as git blob object
- Use command (create a blob object with some content)
  - git hash-object
  - $ echo "test content" | git hash-object -w --stdin
  - Receive an identifier for this file (hash value)
- A SHA-1 value is generated for this object
- .git/objects, see a directory with **first two** characters of the hash and blob is in it
- However, this is encrypted. Use $ git cat-file -p hash to check the original content
- git cat-file -t (check the type for this hash value)
- If overwrite with another version, the original version is still stored in the object
- If want to switch back, just pull out the original hash value

###### Tree Objects

- The blob objects do not have name/structure
- Think of tree as linux directories
- Open the tree using cat-file
  - $ git cat-file -p master*(tree)
- How to create a tree?
  - git update-index --add --cacheinfo 100644 hash file_name
  - Update the index for this staging area
  - Add a new file
  - Cacheinfo: not in current file, but within the cache (previous commits)
  - 100644: a normal file
  - Then can keep track of this file
  - After index every file that we want to track, type the command:
  - $ git write-tree
- If this file already exists in current directory:
  - $ git update-index --add new.txt
- Add a directory: (a tree node)
  - $ git read-tree -prefix=bak(name for that subdirectory) hash

###### Commit Objects

- Specify a tree and your commit message:
  - $ echo 'first commit' | git commit-tree hash

###### Relate back to porcelain command

- cd refs ==> remote head tag
- cat head: shows the branch and latest commit for each branch; the parent is the previous commit

###### Assignment 9

- git commit, git branch, git log
- merge from neighboring commit

