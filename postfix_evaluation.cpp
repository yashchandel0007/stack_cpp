#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Stack_postfix_evaluation{
private:
    int top;
public:
    int size;
    int* array;
    Stack_postfix_evaluation(int size){
        this->size = size;
        this->array = new int[size];
        top = -1;
    }
    
    int push(int data){
        if(top>=size-1)
            return INT_MIN;
        else
            array[++top] = data;
        return data;
    }
    int pop(){
        if(top==-1)
            return INT_MIN;
        else
            return array[top--];
    }
    int peek(){
        if(top!=-1)
            return array[top];
        else
            return INT_MIN;
    }
    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }
};

bool isDigit(char operand){
    if((operand>='0' && operand<='9')){
        return true;
    }
    else 
        return false;
}

int evaluate(int opr1, int opr2, char opt){
    switch(opt){
        case '+': return(opr1 + opr2);
        case '-': return(opr1 - opr2);
        case '*': return(opr1 * opr2);
        case '/': return(opr1 / opr2);
        case '^': return(pow(double(opr1),double(opr2)));
    }
    return INT_MIN;
    
}

void postfix_evaluation_driverFunction(){
    string postfixExpression;
    cout<<"Enter any postfix expression: ";
    getline(cin,postfixExpression);
    cout<<postfixExpression<<" = ";
    
    int size = postfixExpression.size();
    Stack_postfix_evaluation operand(size);
    char tempCharacter;
    for(int i = 0; i< size; i++){
        tempCharacter = postfixExpression.at(i);
        
        if(isDigit(tempCharacter)){
            operand.push(tempCharacter - '0');         //way to convert char to integer
        }
        else{
            int temp2= operand.pop();
            int temp1= operand.pop();
            int push_value = evaluate(temp1, temp2, tempCharacter);
            operand.push(push_value);   
        }
    }
    
    cout<<operand.pop()<<endl;
    cout<<operand.isEmpty()<<endl;
}
