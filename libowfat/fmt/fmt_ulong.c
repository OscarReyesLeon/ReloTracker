#include "fmt.h"

size_t fmt_ulong(char *dest,unsigned long i) {
  register unsigned long len,tmp,len2;
  /* first count the number of bytes needed */
  for (len=1, tmp=i; tmp>9; ++len) tmp/=10;
  if (dest)
    for (tmp=i, dest+=len, len2=len+1; --len2; tmp/=10)
      *--dest = (char)((tmp%10)+'0');
  return len;
}

#ifdef UNITTEST
#include <assert.h>
#include <string.h>

int main() {
  char buf[100];
  assert(fmt_ulong(buf,12345)==5 && !memcmp(buf,"12345",5));
  return 0;
}
#endif
