#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL ;
    return newNode;
}

void insert_Linkedlist(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }
}

void Display(struct Node* head){
    if(head == NULL){
        printf("Linked list is Empty!");
    }
    else{
        struct Node* temp = head;
        do{
            printf("%d -> ", temp->data);
            temp = temp->next;
        }while(temp != head);
        printf("Back to head.");
    }
}

int main() {
    struct Node* head = NULL;


    insert_Linkedlist(&head, 10);
    insert_Linkedlist(&head, 20);
    insert_Linkedlist(&head, 30);
    insert_Linkedlist(&head, 40);

    printf("Circular Linked List:\n");
    Display(head);



    return 0;
}