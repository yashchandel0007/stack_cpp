#include "stack_header.h"
#include <iostream>
#include <stack>

using namespace std;

void next_greater_element(int array[],int last){
    stack <int> s;
    s.push(array[last]);
    int nge[last+1];
    nge[last] = -1;
    for(int i = last-1;i>=0;i--){
        while(!s.empty() && s.top()< array[i]){
            s.pop();
        }
        nge[i] = s.empty()?-1:s.top();
        s.push(array[i]);
    }
    for(int i = 0; i<=last; i++){
        cout<<array[i]<<"--"<<nge[i]<<endl;
    }
}

void next_greater_element_driverFunction(){
    
    int array[] = {11,13,21,3};
    int size = sizeof(array)/sizeof(array[0]);
    
    next_greater_element(array,size-1);
    
    
}