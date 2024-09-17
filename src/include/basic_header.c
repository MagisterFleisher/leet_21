#include <stdio.h>

void temp(void) {
  (void) printf("%s] %s) %d- Hello, Header!\n", __FILE__, __func__, __LINE__);
  return;
}
