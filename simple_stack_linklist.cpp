
#include<iostream>
#include "stack_header.h"


using namespace std;

class Stack{
public:
    int data;
    Stack* next;
};

bool isEmpty(Stack* head){
    if(head==NULL)
        return true;
    else
        return false;
    
}
Stack* createNode(int data){
    Stack* node = new Stack();
    node->data = data;
    node->next = NULL;
    return node;
}

void push(Stack** head, int data){
    Stack* temp = createNode(data);
    temp->next = *head;
    *head = temp;
    cout<<data<<" pushed into stack"<<endl;
}

int pop(Stack** head){
    if(isEmpty(*head)){
        cout<<"Underflow"<<endl;
        return INT_MIN;
    }
    Stack* temp = *head;
    *head = (*head)->next;
    int poped = temp->data;
    cout<<temp->data<<" poped"<<endl;
    free(temp);
    return poped;
}

int peek(Stack* head){
    if(isEmpty(head)){
        cout<<"Empty Stack";
        cout<<"List";
        return INT_MIN;
    }
    cout<<head->data<<endl;
    return head->data;
    
}

void simple_stack_linklist_driverFunction(){
    Stack* top = NULL;
    
    cout<<isEmpty(top)<<endl;
    
    for(int i = 0; i<10;i++){
        push(&top, i);
    }
    cout<<isEmpty(top)<<endl;
    for(int i =0; i<10; i++){
        pop(&top);
        peek(top);
    }
    cout<<isEmpty(top)<<endl;
    
}
