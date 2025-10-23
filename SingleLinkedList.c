#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};


void print_list(struct node *head){
   struct node *ptr = head;
    
   printf("Current List: "); 
   while (ptr != NULL){
       printf("%d->", ptr->data);
       ptr = ptr->link;
   } 
   printf("NULL\n");
}


void add_at_end(struct node *head, int data){
    struct node *ptr = head;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;

    while (ptr->link != NULL){
        ptr = ptr->link;
    }

    ptr->link = new_node;
    printf("New node added to the end of the list with value: %d\n", data);
}

int main(){
    
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;
    add_at_end(head, 55);
    print_list(head);
    add_at_end(head, 100);
    print_list(head);
    return 0;
}
