#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
void print(struct node *head){
    struct node *ptr = head;
    while(ptr->next != head){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<ptr->data;
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;

    head = new struct node;
    second = new struct node;
    third = new struct node;

    head->data = 32;
    second->data = 432;
    third->data = 21;

    head->next = second;
    second->next = third;
    third->next = head;
    print(head);

    return 0;
}