#include <stdio.h>
#include "include/merge_two_lists.h"

int main(int argument_count, char** argument_vector) {
  int error = 0;
  (void) printf("%s] %s) %d- argument_count: %d\n", __FILE__, __FUNCTION__, __LINE__, argument_count);
  linkedList* ll = initLL(1);
  ll = insertHead(ll, 5);
  ll = insertTail(ll, 7);
  (void) printLinkedList(ll);
  ll = removeTail(ll);
  (void) printLinkedList(ll);
  (void) deleteLinkedList(ll);

  return error;
}
