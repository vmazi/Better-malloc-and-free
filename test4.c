#include "mymalloc.h"


int main(int argc,char** argv){

  char* testa = (char*)malloc(50);
  printf("enter data: \n");
  scanf("%s",testa);
  printf("This is what you entered: %s\n",testa);
  free(testa);
  printf("print of data after its freed: %s\n",testa);
  free(testa);
  char* testb = (char*)malloc(50);
  printf("enter data: \n");
  scanf("%s",testb);
  printf("This is what you entered: %s\n",testb);
  free(testb);
  return 0;

}
