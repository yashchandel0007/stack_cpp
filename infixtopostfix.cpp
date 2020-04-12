#include<iostream>
#include<string>

#include "stack_header.h"

using namespace std;

class Stack{
    int top;
public:
    int capacity;
    char *array;
    Stack(unsigned int capacity_ = 100){
        capacity = capacity_;
        array = new char[capacity];
        top = -1;
    }
    bool Stack::push(char x){
    //check overflow
    //    cout<<capacity<<"-"<<top<<endl;
        if(top >= (capacity-1)){
//            cout<<"Stack Overflow"<<endl;
            return false;
        }    
        else{
            array[++top] = x;
//            cout<<x<<" pushed into stack\n";
            return true;
        }
    }
    char Stack::pop(){
        //check underflow
        if(top<0){
//            cout<<"Stack Underflow\n";
            return '0';
        }
        else{
            char temp = array[top--];
//            cout<<temp<<" poped out of stack\n";
            return temp;
        }
    }
    char Stack::peek(){
        if(top <0){
            cout<<"Empty stack\n";
            return '0';
        }
        else{
//            cout<<array[top]<<endl;
            return array[top];
        }
    }   
    bool Stack::isEmpty(){
        if(top<0){
//            cout<<"true\n";
            return true;
        }
        else{
//            cout<<"false\n";
            return false;
        }    
    }
}; //end of stack class

bool isOperator(char ch){
    if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
        return false;
    else 
        return true;
}

int optPrecedence(char ch){
    switch(ch){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}



void simple_stack_infixtopostfix_driverFunction(){
    string infixExpression;
    cout<<"Enter any string: ";
    getline(cin, infixExpression);
    cout<<infixExpression<<endl;
    int stacksize = infixExpression.size();
    Stack opt(stacksize); 
    char temp;
    for(int i= 0; i<stacksize; i++){
        temp = infixExpression.at(i);
        if(!isOperator(temp)){
            cout<<temp;
        }
        else if(temp=='('){
            opt.push(temp);
        }
        else if(temp==')'){
            while(!opt.isEmpty() && opt.peek() != '('){
                cout<<opt.pop();
            }
            if(!opt.isEmpty() && opt.peek() !='('){
                cout<<"\nInvalid Expression"<<endl; 
                return ;
            }
            else
                opt.pop();
        }
        else{
            while( !opt.isEmpty() && optPrecedence(temp)<= optPrecedence(opt.peek())){
                cout<<opt.pop();
            }
            opt.push(temp);            
        }  
    }
    
    while(!opt.isEmpty()){
        cout<<opt.pop();
    }
    cout<<endl;
    
    return;
}
