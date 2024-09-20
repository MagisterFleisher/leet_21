#include <stdint.h>
#include <stdio.h>
#include "include/merge_two_lists.h"

struct ListNode {
    int val;
    struct ListNode *next;
}; 

struct ListNode* createNode(int value) {
    struct ListNode* list3 = malloc(sizeof(struct ListNode));
    list3->val = value;
    list3->next = NULL;
    return list3;
}

struct ListNode* addTail(struct ListNode* ll, int value) {
    struct ListNode* new_tail = createNode(value);
    struct ListNode* current_node = ll;
    while(NULL != current_node->next) {
        current_node = current_node->next;
    }
    current_node->next = new_tail;
    return ll;
}

void deleteLinkedList(struct ListNode* ll) {
    struct ListNode* current_node = ll;
    struct ListNode* next_node = ll->next;
    while(NULL != current_node) {
        (void) free(current_node);
        current_node = next_node;
        if(NULL != next_node) {
            next_node = next_node->next;
        }
    }
    return;
}

uint16_t sizeofLinkedList(struct ListNode* ll) {
  uint16_t ll_size = 0;
  struct ListNode* tmp_ll = ll;
  while(NULL != tmp_ll) {
    tmp_ll = tmp_ll->next;
    ll_size++;
  }
  return ll_size;
}

void printLinkedList(struct ListNode* ll) {
  struct ListNode* tmp_ll = ll;
  while(NULL != tmp_ll) {
    (void) printf("%s %d- list value: %d\n", __func__, __LINE__, tmp_ll->val);
    tmp_ll = tmp_ll->next;
  }
  return;
}

int main(int argument_count, char** argument_vector) {
  int error = 0;
//  (void) printf("%s] %s) %d- argument_count: %d\n", __FILE__, __FUNCTION__, __LINE__, argument_count);
  struct ListNode* list1 = createNode(-9);
  list1 = addTail(list1,3);
  
  struct ListNode* list2 = createNode(5);
  list2 = addTail(list2,7);

  struct ListNode* list1_tmp = list1;
  struct ListNode* list2_tmp = list2;
  
  int current_val = 0;
  if(list1_tmp->val <= list2_tmp->val) {
    current_val = list1_tmp->val;
    list1_tmp = list1_tmp->next;
  } else {
    current_val = list2_tmp->val;
    list2_tmp = list2_tmp->next;
  }
  struct ListNode* list3 = createNode(current_val);
  
  while(NULL != list1_tmp && NULL != list2_tmp) {
    if(list1_tmp->val <= list2_tmp->val) {
      current_val = list1_tmp->val;
      list1_tmp = list1_tmp->next; 
    } else {// (list1_tmp->val > list2_tmp->val) {
      current_val = list2_tmp->val;
      list2_tmp = list2_tmp->next; 
    }
    list3 = addTail(list3,current_val);
  }
   if(NULL != list1_tmp) {
      while(NULL != list1_tmp ) {
      list3 =  addTail(list3, list1_tmp->val);
      list1_tmp = list1_tmp->next; } 
  }
  if(NULL != list2_tmp) {
      while(NULL != list2_tmp ) {
      list3 =  addTail(list3, list2_tmp->val);
      list2_tmp = list2_tmp->next; }
  }
  (void) printLinkedList(list3);
  
  deleteLinkedList(list1);
  deleteLinkedList(list2);
  deleteLinkedList(list3);
  
  return error;
}
