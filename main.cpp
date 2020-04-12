/* 
 * File:   main.cpp
 * Author: yash
 *
 * Created on 11 April, 2020, 6:48 PM
 */

#include <cstdlib>
#include<iostream>
#include "stack_header.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout<<"Hi i am main() in main.cpp"<<endl;
//    simple_stack_array_driverFunction();
//    simple_stack_linklist_driverFunction();
    simple_stack_infixtopostfix_driverFunction();
    
    
    
    return 0;
}

