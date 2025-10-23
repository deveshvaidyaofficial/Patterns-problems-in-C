#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};


void print_list(struct node *head){
   struct node *ptr = head; 
   if (head == NULL){
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


void delete_from_end(struct node **head){
    struct node *ptr = *head;
    struct node *prev = NULL;
    

    if ((*head)->link == NULL){
        printf("List only has one element: %d. Deleting...\n", (*head)->data);
        free(*head);
        *head = NULL;
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

void add_at_beginning(struct node **head, int data){
    struct node *ptr = *head;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;

    new_node->link = *head;
    *head = new_node;
    printf("Value added to the beginning of the list: %d\n", (*head)->data);
}

void delete_from_beginning(struct node **head){
    struct node *ptr = *head;
    struct node *next = (*head)->link;
    
    if((*head)->link == NULL){
        printf("List only has one value: %d. Deleting...\n", ptr->data);
        free(*head);
        head = NULL;
        return;
    }

    printf("Deleting value from the beginning of the list: %d\n", ptr->data);
    free(ptr);
    *head = next;
}


void insert_at_specific_position(struct node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct node *new_node = malloc(sizeof(struct node));
    
    new_node->data = data;
    new_node->link = NULL;

    if (position == 1) {
        new_node->link = *head;
        *head = new_node;
        printf("Inserted %d at position 1.\n", data);
        return;
    }

    struct node *ptr = *head;
    int count = 1;

    while (ptr != NULL && count < position - 1) {
        ptr = ptr->link;
        count++;
    }

    if (ptr == NULL) {
        printf("Position out of range.\n");
        free(new_node);
        return;
    }

    new_node->link = ptr->link;
    ptr->link = new_node;

    printf("Inserted %d at position %d.\n", data, position);
}

void delete_from_specific_position(struct node **head, int position){
    if (*head == NULL || position < 1) return;

    struct node *ptr = *head;
    struct node *prev = NULL;
    int count = 1;

    if (position == 1){
        *head = ptr->link;
        free(ptr);
        return;
    }

    while (ptr != NULL && count < position){
        prev = ptr;
        ptr = ptr->link;
        count++;
    }

    if (ptr == NULL) return;

    prev->link = ptr->link;
    free(ptr);
}


int main(){
    
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;
    print_list(head);
   return 0;
}
