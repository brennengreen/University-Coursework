/*
* Linked List Data Structure
*/
#define NULL 0
#include <stdlib.h>
#include <stdio.h>


typedef struct ListNode {
    int data;
    struct ListNode * next;
} Node;

Node * make_node(int data, Node * next) {
    Node * answer = (Node * ) malloc(sizeof(Node));
    answer->data = data;
    answer->next = next;
    return answer;
} // make_node

void insert_node_at_front(Node * list_head, int data) {
    Node * answer = make_node(data, list_head->next);
    list_head->next = answer;
} // insert_node_at_front

void print_list(Node * list_head) {
    Node * current = list_head->next; // dont care about list head
    while (current->next != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
} // print_list

main () {
    Node  * head = make_node(0, NULL);

    insert_node_at_front(head, 10);

    print_list(head);


}