#ifndef MYMALLOC_H_
#define MYMALLOC_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>


#define malloc(x) mymalloc((x), __FILE__, __LINE__)
#define free(x) myfree((x), __FILE__, __LINE__)
#define specialcode (24982122)


typedef struct memstruct{
  int special;
  int free;
  int size;
  struct  memstruct* next;
  char *data;
}memstruct;

void* mymalloc(unsigned int size, char * filename, unsigned int linenum);
void myfree(void*ptr,char*filename,unsigned int linenum);

#endif
