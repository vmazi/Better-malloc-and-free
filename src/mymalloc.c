#include "mymalloc.h"

int rootsize = 1;

char*  root;

char* bottom;
int lastval =0;

void* mymalloc(unsigned int size, char * filename, unsigned int linenum){
  if(size == 0){
    return NULL;
    }
  memstruct* check;
  void* retptr;
  char* top = bottom;
  
  if(root == NULL){
    root = sbrk(0);
    bottom = root;
    top = bottom;
    goto mem_init;
  }
  check = (memstruct*) (root+1);
  while(check->special==specialcode){
  
      if(check->free==1){
	if(check->size>=size){
	  retptr = (void*)check->data;
	  check->free = 0;
	  printf("mem reuse\n");
	  return retptr;
	}
	else{
	  if(check->next==NULL){
	    break;
	  }
	  check = check->next;
	}
      }
      else{
	if(check->next==NULL){
	  break;
	}
	check = check->next;
      }
   
  }  
 mem_init:
  brk(bottom);
  if(errno != 0){
    printf("error, this only happens if you're out of memory!\n");
    return NULL;
  }
  top = (char*)sbrk(sizeof(memstruct)+size);
  bottom = top+sizeof(memstruct)+size;
  rootsize = rootsize+(sizeof(memstruct)+size);
  if(errno != 0){
    printf("error, this only happens if you're out of memory!\n");
    return NULL;
  }
  
  
  char* use = top+1;
  
  memstruct* ptr = (memstruct*) use;
  
  
  
  ptr->size = size;
  
  ptr->free = 0;
  ptr->special = specialcode;
  ptr->data = (char*)(ptr+1);
  ptr->next = NULL;
  retptr = (void*) ptr->data;
  if(lastval!=0){
    char *tmp = 1+top - (sizeof(memstruct)+lastval);
    memstruct* ptr2 = (memstruct*) tmp;
    ptr2->next = ptr;
  } 

  printf("malloc sucess\n");
  lastval = size;
  return retptr;
  
}
void myfree(void*ptr,char*filename,unsigned int linenum){
  int i;
  
  if(ptr == NULL){
    printf("null pointer at file: %s, line: %d\n",filename,linenum);
    return;
  }
  void** point = &ptr;

  char* here = (char*)ptr;

  char*del  = ((char*)(here - (sizeof(memstruct))));
  if(del == NULL){
    printf("trying to free invalid pointer at file: %s, line: %d\n",filename,linenum);
    return;
  }
  memstruct* this = (memstruct*) del;
  if (this->special != specialcode){
    printf("trying to free invalid pointer at file: %s, line: %d\n",filename,linenum);

    return;
  }
  if(this->free == 1){
    printf("already freed pointer at file: %s, line: %d\n",filename,linenum);
    return;
  }
  for( i = 0;i<this->size;i++){
    *here= '\0';
    here++;
  }
  this->free = 1;
  *point = NULL;
  printf("free success!\n");
  return;

}
