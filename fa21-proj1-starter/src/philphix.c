/*
 * Include the provided hash table library.
 */
#include "hashtable.h"

/*
 * Include the header file.
 */
#include "philphix.h"

/*
 * Standard IO and file routines.
 */
#include <stdio.h>

/*
 * General utility routines (including malloc()).
 */
#include <stdlib.h>

/*
 * Character utility routines.
 */
#include <ctype.h>

/*
 * String utility routines.
 */
#include <string.h>

/*
 * This hash table stores the dictionary.
 */
HashTable *dictionary;

/*
 * The MAIN routine.  You can safely print debugging information
 * to standard error (stderr) as shown and it will be ignored in 
 * the grading process.
 */
#ifndef _PHILPHIX_UNITTEST
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Specify a dictionary\n");
    return 1;
  }
  /*
   * Allocate a hash table to store the dictionary.
   */
  fprintf(stderr, "Creating hashtable\n");
  dictionary = createHashTable(0x61C, &stringHash, &stringEquals);

  fprintf(stderr, "Loading dictionary %s\n", argv[1]);
  readDictionary(argv[1]);
  fprintf(stderr, "Dictionary loaded\n");

  fprintf(stderr, "Processing stdin\n");
  processInput();

  /*
   * The MAIN function in C should always return 0 as a way of telling
   * whatever program invoked this that everything went OK.
   */
  return 0;
}
#endif /* _PHILPHIX_UNITTEST */

char* readWord(FILE* pfile){
  size_t m_size=60;
  char ch;
  while(isspace(ch=fgetc(pfile)));
  if(ch==EOF)return NULL;
  char* str=malloc(m_size);
  int pos=1;
  str[0]=ch;
  while(1){
    for(pos;pos<m_size;++pos){
      ch=fgetc(pfile);
      if(isspace(ch)||ch==EOF){
        str[pos]='\0';
        return str;
      }
      else str[pos]=ch;
    }
    if(pos==m_size&&str[m_size-1]!='\0'){
      m_size*=2;
      str=realloc(str,m_size);
    }
  }
}

/* Task 3 */
void readDictionary(char *dictName) {
  // -- TODO --
  FILE* pfile =  fopen(dictName,"r+");
  if(pfile==NULL){
    fprintf(stderr,"Can't open the file");
    exit(61);
  }
  while(1){
    char* key=readWord(pfile);
    char* value=readWord(pfile);
    if(key==NULL||value==NULL)
      break;
    insertData(dictionary,(void*)key,(void*)value);
  }
}

int replace(){
  int max_size=60;
  char* str=malloc(max_size);
  char buffer='\0';
  int i=0,isEnd=0;
  char ch;
  while(1){
    for(i;i<max_size;++i){
      char ch=getchar();
      if(ch==EOF)
        isEnd=1;
      if(isalnum(ch))
        str[i]=ch;
      else{
        str[i]='\0';
        buffer=ch;
        break;
      }
    }
    if(i==max_size&&str[max_size-1]!='\0'){
      max_size*=2;
      str=realloc(str,max_size*2);
    }
    else
      break;
  }
  char* value=findData(dictionary,str);
  char* origin=malloc(strlen(str));
  strcpy(origin,str);
  if(value!=NULL)
    printf("%s",value);
  else{
    for(int i=1;i<strlen(str);++i){
      if(str[i]>='A'&&str[i]<='Z')
        str[i]+='a'-'A';
    }
    value=findData(dictionary,str);
    if(value!=NULL)
      printf("%s",value);
    else if (str[0]>='A'&&str[0]<='Z')
    {
      str[0]+='a'-'A';
      value=findData(dictionary,str);
      if(value!=NULL)
        printf("%s",value);
      else printf("%s",origin);
    }
    else printf("%s",origin);
  }

  if(buffer!='\0'&&buffer!=EOF)
    printf("%c",buffer);
  return isEnd;
}

/* Task 4 */
void processInput() {
  // -- TODO --
  //fprintf(stderr, "You need to implement processInput\n");
  while(1)
    if(replace()==1)
      return;
}
