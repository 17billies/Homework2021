#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
}Node;
Node *createList(int n);
void freeList(Node* head);
int solveJosephus(Node **head, int step);


Node *createList(int n){
    Node *last;
    last=(Node*)malloc(sizeof(Node));
    last->number=n;
    last->next=last;
    for(int i=n-1;i>=1;i--){
        Node *q=(Node*)malloc(sizeof(Node));
        q->number=i;
        q->next=last->next;
        last->next=q;
    }
    return last;
}
int solveJosephus(Node **head, int step){
    Node *q=*head;
    int n=(*head)->number;
    Node *dem;
    int flag=0;
    while(q->next!=q){
        for(int i=0;i<(step-1)%n;++i){
            q=q->next;
        }
        Node *a;
        a=q->next;
        q->next=a->next;
        free(a);
        --n;
    }

    return q->number;
}
void freeList(Node* head){

    return;
}


#endif
