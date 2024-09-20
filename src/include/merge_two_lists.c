#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


struct ListNode;
typedef struct ListNode ListNode;
typedef struct linkedList linkedList;

typedef struct linkedList {
    uint16_t size;
    ListNode* head;
    ListNode* tail;
} linkedlist;

struct ListNode {
    int val;
    ListNode *next;
}; 


ListNode* initNode(int val);
linkedlist* initLL(int val);
linkedlist* insertHead(linkedlist* ll, int val);
linkedlist* insertTail(linkedlist* ll, int val);
linkedlist* removeHead(linkedlist* ll);
linkedlist* removeTail(linkedlist* ll);

void deleteLinkedList(linkedlist* ll);
void printLinkedList(linkedlist* ll);


ListNode* initNode(int val) {
    ListNode* ll_node = malloc(sizeof(ListNode));
    ll_node->val = val;
    ll_node->next = NULL;
    return ll_node;
}

linkedlist* initLL(int val) {
    linkedlist* ll = malloc(sizeof(linkedlist));
    ll->head = initNode(val);
    ll->tail = ll->head;
    ll->size =  1;
    return ll;
}

linkedlist* insertHead(linkedlist* ll, int val) {
    ListNode* new_head = initNode(val);
    new_head->next = ll->head;
    ll->head = new_head;
    ll->size++;
    return ll;
}

linkedlist* insertTail(linkedlist* ll, int val) {
    ListNode* new_tail = initNode(val);
    (void) printf("%s %d- Current tail value %d\n", __func__, __LINE__, ll->tail->val);
    ll->tail->next = new_tail;
    ll->tail = new_tail;
    ll->size++;
    (void) printf("%s %d- Current tail value %d\n", __func__, __LINE__, ll->tail->val);
    return ll;
}

linkedlist* removeHead(linkedlist* ll) {
    ListNode* current_head = ll->head;
    if(NULL == current_head) {
/*         (void) printf("%s %d- head address %p \t ll size %d \n", __func__, __LINE__, current_head, ll->size);
 */        return ll;
    } else {
/*         (void) printf("%s %d- head address %p \t ll size %d \n", __func__, __LINE__, current_head, ll->size); */
        ListNode* new_head = current_head->next;
        ll->head = new_head;
        ll->size--;
        (void) free(current_head);
    }
    return ll;
}

linkedlist* removeTail(linkedlist* ll) {
    // roll through the linked list to find the previous node
    ListNode* temp_node = ll->head;
    
    while(ll->tail != temp_node->next) {
/*         (void) printf("%s %d- %d\n", __func__, __LINE__, temp_node->val); */
        temp_node = temp_node->next;
    }/* 
    (void) printf("%s %d- current temp node value: %d\n", __func__, __LINE__, temp_node->val);
    (void) printf("%s %d- current tail node value: %d\n", __func__, __LINE__, ll->tail->val);
    (void) printf("%s %d- current temp node next value: %d\n", __func__, __LINE__, temp_node->next->val); */
    ll->tail = temp_node;
    (void) free(temp_node->next);
    ll->size--;
    return ll;
}

void deleteLinkedList(linkedlist* ll) {
    while(0 != ll->size) {
        ll = removeHead(ll);
/*         (void) printf("remaining ll size: %d\n", ll->size); */
    }
    (void) free(ll);
    return;
}

void printLinkedList(linkedList* ll) {
    ListNode* current_node = ll->head;
    for(uint16_t index = 0; index < ll->size; index++) {
        (void) printf("%s %d- %d\n", __func__, __LINE__, current_node->val);
        current_node = current_node->next;
    }
    return;
}


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    uint switch_value = ((NULL == list1) && (NULL == list2)) +
      2 * ((NULL == list1) && (NULL != list2)) + 
      3 * ((NULL != list1) && (NULL == list2)) +
      4 * ((NULL != list1) && (NULL != list2));
    (void) printf("switch_value: %d", switch_value);
    switch(switch_value) {
        case 1 : {
            return NULL;
            break;
        };
        case 2 : {
            return list2;
            break;
        };
        case 3 : {
            return list1;
            break;
        };
        case 4 : {
            int head_value = 0;
            if(list1->val > list2->val) { 
                head_value = list2->val;
                list2 = list2->next;
            } else {
                head_value = list1->val;
                list1 = list1->next;
            }
            linkedList* list3 = initLL(head_value);
            while((NULL != list1) && (NULL != list2)) {
                if(list1->val <= list2->val) { 
                    list3 = insertTail(list3,list1->val);
                    list1 = list1->next;
                } else {
                    list3 = insertTail(list3,list1->val);
                    list2 = list2->next;
                }
            }
            if((NULL == list2) && (NULL != list1)) {
                while(NULL != list1) {
                    list3 = insertTail(list3, list1->val);
                    list1 = list1->next;
                } 
            }
            if(NULL == list1 && (NULL != list2)) {
                while(NULL != list2) {
                    list3 = insertTail(list3, list2->val);
                    list2 = list2->next;
                } 
            }
            return list3;
            break;
        };
        default : {
            break;
        };
    };
    return NULL;
} */