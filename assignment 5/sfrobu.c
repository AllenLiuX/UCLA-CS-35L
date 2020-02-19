//
//  sfrobu.c
//  35L_lab4
//
//  Created by VincentL on 5/7/19.
//  Copyright © 2019 VincentL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>


int ignoreCase = 0;

//Print error message
void printErr(const char* msg)
{
    fprintf(stderr,"Error! %s\n", msg);
    exit(1);
}

//frob
int frob(const char c)
{
    char ch=c^42;
    if(ignoreCase==1 && islower(ch)){
        ch=toupper(ch);
    }
    return ch;
}
//Compare two strings
int frobcmp(const void* p1, const void* p2)
{
    const char* a = *(const char**)p1;
    const char* b = *(const char**)p2;
    while(*a!=' ' && *b!=' ')
    {
        if(*b==' ' || frob(*a) > frob(*b))
            return 1;
        else if(*a==' ' || frob(*b) > frob(*a))
            return -1;
        a++;
        b++;
        
    }
    return 0;
}


int main(int argc, char** argv)
{
    if (argc > 2)
    {
        fprintf(stderr, "error! incorrect number of arguments.\n");
        exit(1);
    }
    if (argc == 2 && strcmp(argv[1], "-f") == 0)
    {
        // if -f is given, set ignoreCase to true
        ignoreCase = 1;
    }
    else if (argc == 2 && strcmp(argv[1], "-f") != 0) {
        // Checking if additional option is NOT '-f'
        fprintf(stderr, "error! incorrect option provided. Only -f allowed.\n");
        exit(1);
    }
    
    char *word = (char*)malloc(sizeof(char));
    char **words = (char**)malloc(sizeof(char*));
    char curr;
    int cNum=0,wNum=0,ccNum=0;
    ssize_t get = 1;
    
    if(word == NULL || words == NULL)
    {
        fprintf(stderr,"error! invalid memory allocation\n");
        exit(1);
    }
    
    while(get)
    {
        //Store one char in curr
        get = read(STDIN_FILENO,&curr,1);
        //check IO
        if(get==-1)
            printErr("error! invalid input\n");
        
        if(cNum>0 && (curr==' ' || get == 0))
        {
            word=(char*)realloc(word, (cNum+1)*sizeof(char));
            char *temp = (char*)malloc(sizeof(char));
            word[cNum] = ' ';
            words = (char**)realloc(words,(wNum+1)*sizeof(char*));
            
            //insert the new word into words
            if(temp && words)
            {
                words[wNum]=word;
                wNum++;
                word=temp;
                cNum=0;
                
            }
            else
            {
                fprintf(stderr,"error: invalid memory allocation");
                free(word);
                exit(1);
            }
        }
        else
        {
            word=(char*)realloc(word, (cNum+1)*sizeof(char));
            if(word)
            {
                word[cNum++]=curr;
                ccNum++;
            }
            else{
                fprintf(stderr, "error: invalid memory allocation");
                exit(1);
            }
        }
    }
    //Sort the array and print
    qsort(words,wNum,sizeof(char*),frobcmp);
    
    int i=0,j=0;
    for(i=0;i<wNum;i++)
    {
        for(j=0;words[i][j]!='\0';j++)
        {
            get = write(STDOUT_FILENO,&words[i][j],1);
            //check IO
            if(get==-1)
                printErr("invalid input!");
            if(words[i][j]==' ')
                break;
        }
    }
    
    //free memory
    for(i=0;i<wNum;i++)
        free(words[i]);
    free(words);
    free(word);
    exit(0);
}
