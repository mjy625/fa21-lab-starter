#include "hashtable.h"

/*
 * General utility routines (including malloc()).
 */
#include <stdlib.h>

/*
 * Standard IO and file routines.
 */
#include <stdio.h>

/*
 * String utility routines.
 */
#include <string.h>

/*
 * This creates a new hash table of the specified size and with
 * the given hash function and comparison function.
 */
HashTable *createHashTable(int size, unsigned int (*hashFunction)(void *),
                           int (*equalFunction)(void *, void *)) {
  int i = 0;
  HashTable *newTable = malloc(sizeof(HashTable));
  if (NULL == newTable) {
    fprintf(stderr, "malloc failed \n");
    exit(1);
  }
  newTable->size = size;
  newTable->buckets = malloc(sizeof(struct HashBucketEntry *) * size);
  if (NULL == newTable->buckets) {
    fprintf(stderr, "malloc failed \n");
    exit(1);
  }
  for (i = 0; i < size; i++) {
    newTable->buckets[i] = NULL;
  }
  newTable->hashFunction = hashFunction;
  newTable->equalFunction = equalFunction;
  return newTable;
}

/* Task 1.2 */
void insertData(HashTable *table, void *key, void *data) {
  // -- TODO --
  // HINT:
  // 1. Find the right hash bucket location with table->hashFunction.
  // 2. Allocate a new hash bucket entry struct.
  // 3. Append to the linked list or create it if it does not yet exist. 
  unsigned index=table->hashFunction(key),size=table->size;
  HashBucketEntry* newEntry=malloc(sizeof (HashBucketEntry));
  newEntry->key=key;
  newEntry->data=data;
  newEntry->next=NULL;
  HashBucketEntry* p=table->buckets[index%size];
  if(p==NULL)
    table->buckets[index%size]=newEntry;
  else{
    HashBucketEntry* prev;
    while(p!=NULL){
      prev=p;
      p=p->next;
    }
    prev->next=newEntry;
  }
}

/* Task 1.3 */
void *findData(HashTable *table, void *key) {
  // -- TODO --
  // HINT:
  // 1. Find the right hash bucket with table->hashFunction.
  // 2. Walk the linked list and check for equality with table->equalFunction.
  unsigned index=table->hashFunction(key),size=table->size;
  if(table->buckets[index%size]==NULL)return NULL;
  HashBucketEntry* p=table->buckets[index%size];
  while(p!=NULL&&!table->equalFunction(p->key,key))p=p->next;
  if(p!=NULL)return p->data;
  else return NULL;
}

/* Task 2.1 */
unsigned int stringHash(void *s) {
  // -- TODO --
  //fprintf(stderr, "need to implement stringHash\n");
  /* To suppress compiler warning until you implement this function, */
  char* p_str=(char*)s;
  unsigned int hash_value=0;
  for(int i=0;i<strlen(p_str);++i){
    hash_value+=(int)p_str[i]*(i+1);
  }
  return hash_value;
}

/* Task 2.2 */
int stringEquals(void *s1, void *s2) {
  // -- TODO --
  //fprintf(stderr, "You need to implement stringEquals");
  /* To suppress compiler warning until you implement this function */
  char* p1=(char*)s1;
  char* p2=(char*)s2;
  if(strlen(p1)!=strlen(p2))
    return 0;
  while(*p1){
    if(*p1!=*p2)
      return 0;
    p1++,p2++;
  }
  return 1;
}