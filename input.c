
#include <unistd.h>

int main(void) {
  char buf[10];
  int i = 0;
  while(i < 10) {
    if(read(0, buf + i, 1) > 0) {
      write(1, buf + i, 1);
      i++;
    }
  }
  write(1, buf, 10);
  return 0;
}
