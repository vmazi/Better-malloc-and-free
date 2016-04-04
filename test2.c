
#include "mymalloc.h"
int main(int argc,char** argv){
  char* p;
  p = (char *)malloc( 200 );
  free( p);
  p = (char *)malloc( 200 );
  free(p);
  return 0;
}
