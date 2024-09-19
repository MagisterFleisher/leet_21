#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
}; 

typedef struct ListNode ListNode;

ListNode* initNode(int val);

ListNode* addNode(ListNode* main_list, ListNode* add_node);

ListNode* insertNode(ListNode* main_list, ListNode* insert_node);

ListNode* initNode(int val) {
    ListNode* init_node = (ListNode*) malloc(sizeof(ListNode));
    init_node->val = val;
    init_node->next = NULL;
    return init_node;
}

ListNode* addNode(ListNode* main_list, ListNode* add_node) {
    main_list->next = add_node;
    ListNode* next_node = main_list->next;
    return next_node;
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
            ListNode* list3 = initNode(0);
            if(list1->val > list2->val) { 
                list3->val = list2->val;
                list2 = list2->next;
            } else {
                list1 = list1->next;
            }
            while((NULL != list1) && (NULL != list2)) {
                if(list1->val <= list2->val) { 
                    list3 = addNode(list3,list1);
                    list1 = list1->next;
                } else {
                    list3 = addNode(list3, list2);
                    list2 = list2->next;
                }
            }
            if(NULL == list2) { list3 = addNode(list3,list1); }
            if(NULL == list1) { list3 = addNode(list3,list2); }
            return list3;
            return list3;
            break;
        };
        default : {
            break;
        };
    };
    return NULL;
}