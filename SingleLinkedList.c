#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};


void print_list(struct node *head){
   struct node *ptr = head;
   
   if (ptr == NULL){
       printf("List is empty.\n");
       return;
   }   
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


void delete_from_end(struct node *head){
    struct node *ptr = head;
    struct node *prev = NULL;
    

    if (ptr->link == NULL){
        printf("List only has one element: %d. Deleting...\n", head->data);
        free(ptr);
        return;
    } 

    while(ptr->link != NULL){
        prev = ptr;
        ptr = ptr->link;
    }
    
    prev->link = NULL;

    printf("Deleting node from the end of the list with the value: %d\n", ptr->data);
    free(ptr);
}

void add_at_beggining(struct node **head, int data){
    struct node *ptr = *head;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;

    new_node->link = *head;
    *head = new_node;
    printf("Value added to the beggining of the list: %d\n", (*head)->data);
}

int main(){
    
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;
    print_list(head);
    add_at_beggining(&head, 232);
    print_list(head);
    return 0;
}
