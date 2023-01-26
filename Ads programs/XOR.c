#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* npx;
};

struct node* head = NULL;

struct node* Xor(struct node *x, struct node *y){
    return (struct node *)((uintptr_t)(x) ^ (uintptr_t)(y)); 
}

void insert(int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> npx = Xor(NULL, head);

    if(head != NULL){
        head -> npx = Xor(new_node, Xor(head -> npx, NULL));
    }

    head = new_node;
}

void delete(){
    struct node* ptr = head;
    head = Xor(NULL, head -> npx);
    head -> npx = Xor(NULL, Xor(ptr, head -> npx));
    free(ptr);
}

void print(){
    struct node* curr = head;
    struct node* prev = NULL;
    struct node* next;

    printf("The values are: \n");

    while(curr != NULL){
        printf("%d \t", curr -> data);
        next = Xor(prev, curr -> npx);

        prev = curr;
        curr = next;
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    print();
    delete();
    print();
    delete();
    print();
    return 0;
}