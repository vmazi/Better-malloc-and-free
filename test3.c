#include "mymalloc.h"
int main(int argc,char** argv){
  int i;
  char* p;
  for(i=0;;i++){
    p = (char*)malloc(i);
    if(errno !=0){
      return 0;
    }
  }
  return 0;
}
