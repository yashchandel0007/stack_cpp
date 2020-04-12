#include "stack_header.h"
#include<iostream>

using namespace std;


class Stack{
    int top;
public:
    int capacity;
    int *array;
    Stack(unsigned int capacity_ = 100){
        capacity = capacity_;
        array = new int[capacity];
        top = -1;
    }
    
//    bool push(int x);
//    int pop();
//    int peek();
//    bool isEmpty();
bool Stack::push(int x){
    //check overflow
//    cout<<capacity<<"-"<<top<<endl;
    
    if(top >= (capacity-1)){
        cout<<"Stack Overflow"<<endl;
        return false;
    }    
    else{
        array[++top] = x;
        cout<<x<<" pushed into stack\n";
        return true;
    }
}

int Stack::pop(){
    //check underflow
    if(top<0){
        cout<<"Stack Underflow\n";
        return 0;
    }
    else{
        int temp = array[top--];
        cout<<temp<<" poped out of stack\n";
        return temp;
    }
}

int Stack::peek(){
    if(top <0){
        cout<<"Empty stack\n";
        return 0;
    }
    else{
        cout<<array[top]<<endl;
        return array[top];
        
    }
}

bool Stack::isEmpty(){
    if(top<0){
        cout<<"true\n";
        return true;
    }
    else{
        cout<<"false\n";
        return false;
    }
        
}


};



void simple_stack_array_driverFunction(){
    cout<<"Heyyaaaa this is simple_stack_driverFunction(). OLA!!!\n";
    
    Stack stack(20); 
    stack.isEmpty();
    for(int i = 0; i<10; i++)
        stack.push(i);
    stack.isEmpty();
    stack.isEmpty();
    for(int i = 0;i<10 ;i++){
        stack.peek();
        stack.pop();
    }
        
    stack.isEmpty();
    
    
}

