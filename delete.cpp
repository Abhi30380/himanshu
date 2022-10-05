#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};

void printLinkedList(struct node *head){
    struct node *p = head;
    while(p != NULL){
        cout<<"this is element: "<<p->data<<endl;
        p = p->next;
    }
}

struct node * deleteAtStart(struct node *head){
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node * deleteAtIndex(struct node *head,int index){
    struct node *p = head;
    if(0 == index){
        cout<<"ho";
        return p->next;
    }
    struct node *q = p->next;
    int count = 0;
    for(int i = 0 ; i < index-1 ; i++){
        p = p->next;
        q = q->next;
        count++;
    }
    cout<<count<<endl;
    p->next = q->next;
    free(q);
    return head;
}

struct node * deleteAtValue(struct node *head,int val){
    struct node * p = head;
    if(p->data == val){
        return p->next;
    }
    struct node * q =p->next;
    while(q->data != val && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == val){
        p->next = q->next;
        free(q);
    }
    return head;
}
int main(){
    struct node *head;
    struct node *second;
    struct node *third;

    head = new struct node;
    second = new struct node;
    third = new struct node;

    head->data = 32;
    second->data = 23;
    third->data = 24;

    head->next = second;
    second->next = third;
    third->next = NULL;
    // head = deleteAtStart(head);
    head = deleteAtIndex(head,2);
    // head = deleteAtEnd(head);
    // head = deleteAtValue(head,32);
    printLinkedList(head);
    return 0;
}