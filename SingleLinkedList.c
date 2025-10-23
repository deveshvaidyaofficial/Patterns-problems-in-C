#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node link;
}


int main(){
    
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    return 0;
}
