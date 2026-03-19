#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void traverse(struct Node* start){
    struct Node* ptr = start;
    int count = 0;

    printf("Start -> ");
    while(ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("NULL");
    printf("\nTotal number of Node are: %d\n", count);
}

int main(){
    struct Node *start = NULL, *n1, *n2, *n3, *n4;

    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));
    n4 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    start = n1;
    traverse(start);

    int key;
    struct Node *val, *ptr;

    val = (struct Node*)malloc(sizeof(struct Node));

    printf("\nEnter value to insert: ");
    scanf("%d", &val->data);

    printf("Insert after value: ");
    scanf("%d", &key);

    ptr = start;

    while(ptr != NULL && ptr->data != key){
        ptr = ptr->next;
    }

    if(ptr == NULL){
        printf("Value not found!\n");
        return 0;
    }

    // link new node after ptr
    val->next = ptr->next;
    ptr->next = val;

    traverse(start);
    return 0;
}

