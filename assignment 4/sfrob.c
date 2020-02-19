//
//  main.c
//  35L_lab4
//
//  Created by VincentL on 4/30/19.
//  Copyright © 2019 VincentL. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int frobcmp(const void* p1, const void* p2)
{
    const char* a = *(const char**)p1;
    const char* b = *(const char**)p2;
    while(*a!=' ' && *b!=' ')
    {
        if(*b==' ' || (*a^42) > (*b^42))
            return 1;
        else if(*a==' ' || (*b^42) > (*a^42))
            return -1;
        a++;
        b++;
        
    }
    return 0;
    
}

int main()
{
    char *word=(char*)malloc(sizeof(char));
    char **words=(char**)malloc(sizeof(char*));
    char curr;
    int cNum=0,wNum=0;
    
    if(word == NULL || words == NULL)
    {
        fprintf(stderr,"error: invalid memory allocation");
        exit(1);
    }
    
    //getchar and process one by one
    while(!feof(stdin))
    {
        curr=getchar();
        if(ferror(stdin))
        {
            fprintf(stderr,"error: invalid stdin");
            exit(1);
        }
        
        if(cNum>0 && (curr==' ' || feof(stdin) || curr==EOF))
        {
            char *temp=(char*)malloc(sizeof(char));
            word=(char*)realloc(word, (cNum+1)*sizeof(char));
            word[cNum]=' ';
            words=(char**)realloc(words,(wNum+1)*sizeof(char*));
            
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
                word[cNum]=curr;
                cNum++;
            }
            else{
                fprintf(stderr, "error: invalid memory allocation");
                exit(1);
            }
        }
    }
    
    //sort the array
    qsort(words,wNum,sizeof(char*),frobcmp);
    
    //print the chars in the sorted order
    for(int i=0;i<wNum;i++)
    {
        for(int j=0;j<wNum;j++)
        {
            if(words[i][j]==' ')
            {
                putchar(words[i][j]);
                break;
            }
            else if(words[i][j]=='\0')
                break;
            else
                putchar(words[i][j]);
        }
    }
    
    //free memory
    for(int i=0; i<wNum; i++)
        free(words[i]);
    free(words);
    exit(0);
}

