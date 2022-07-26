# fa21-proj1-starter

This is the cs61 project1 philphix, using hashtable to implement the function of text replacement, by which we can get more familiar with C language.

Despite of some trivial errors, the following bug really bewildered me:

```c++
#include<stdio.h>
int main(){
    char ch;
    while((ch=getchar())!=EOF)
        putchar(ch);
    /* but the following codes don't work
        it will keep reading the last character(e.g.'\n') 
        it's so odd?
    while(1){
        char ch;
        scanf("%c",&ch);
        if(ch==EOF)break;
        printf("%c",ch);
    }
    */
}
```

When I used the first method, I can successfully read characters in the file one by one correctly, but when I used the method in the comments, the program will keep on reading the last character in the file (e.g. it can't read a EOF properly). I've searched much information but in vain. If you know what happened, I wish you're kind enough to tell me in 'issue'.
