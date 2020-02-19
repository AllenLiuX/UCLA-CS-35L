//
//  main.c
//  35L Assignment5
//
//  Created by VincentL on 5/7/19.
//  Copyright © 2019 VincentL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, const char * argv[]) {
    
    //Check valid number of arguments
    if(argc!=3)
    {
        fprintf(stderr, "error! number of arguments must equal 2");
        exit(1);
    }
    
    //create from and to
    const char* from=argv[1];
    const char* to=argv[2];
    long len1=strlen(argv[1]);
    long len2=strlen(argv[2]);
    
    //Check the length of the strings
    if(len1 == 0 || len2 == 0)
    {
        fprintf(stderr, "error! length of operands must not be 0\n");
        exit(1);
    }
    
    //Check whether the lengths are the same
    if(len1 != len2)
    {
        fprintf(stderr, "error! length of arguments must be the same\n");
        exit(1);
    }

    //Check duplicate bytes in from
    int i=0,j=0;
    for(i=0;i<len1;i++)
    {
        for(j=i+1;j<len1;j++)
        {
            if(from[i]==from[j])
            {
                fprintf(stderr, "error! duplicate bytes\n");
                exit(1);
            }
        }
    }
    
    char c=getchar();
    
    //check IO
    if(ferror(stdin))
    {
        fprintf(stderr, "error! invalid stdin\n");
        exit(1);
    }
    
    //while not reaching the end of file
    while(!feof(stdin))
    {
        for(i=0;i<len1;i++)
        {
            if(c==from[i])
            {
                c=to[i];
                break;
            }
        }
        putchar(c);
        
        //Get next char
        c=getchar();
        
        if(ferror(stdin))
        {
            fprintf(stderr, "error! invalid stdin\n");
            exit(1);
        }
    }
    return 0;
    
}
