#include "mymalloc.h"
int main(int argc,char** argv){
  int x;
  free( &x );
  return 0;
}
