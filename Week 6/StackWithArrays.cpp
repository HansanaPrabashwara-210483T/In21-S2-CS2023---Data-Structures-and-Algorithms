/**
 * @file stackWithArray.cpp
 * @author D.G.Hansana Prabashwara (210483T)
 * @brief This program implement a stack using the Arrays. 
 * @version 0.1
 * @date 2023-04-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * @brief This class create stack objects
 * 
 */
class Stack{

// Static attribute to store the size of the array. For larger stack size please change the value to a large number.
private:
    static int const arraySize = 32;

// A attribute to store the index of the top element of the stack
private:
    int top = -1;

// Attribute to store the array
private:
    int arrayList[arraySize];


// Stack constructor
public:
    Stack(){}


/**
 * @brief push the given value to the top os the stack
 * @param param number: The value to be insert in to the stack 
 */
public:
    void push(int number){
        if(top == arraySize-1){
            throw overflow_error("Stack Overflow");
        }
        else{
            top ++;
            arrayList[top] = number;
        }
    }

/**
 * @brief pop the top element of the stack and return it
 * 
 */
public:
    int pop(){
        if(top == -1){
            throw underflow_error("Stack Underflow");
        }
        else{
            int val = arrayList[top];
            arrayList[top] = 0;
            top --;
            return  val;
        }
    }

/**
 * @brief return the top element of the stack without removing
 * 
 */
public:
    int stackTop(){
        return arrayList[top];
    }

/**
 * @brief Check weather the stack is empty
 * 
 */
public:
    bool isEmpty(){
        if (top == -1){
            return true;
        }else{
            return false;
        }
    }


/**
 * @brief Check weather the stack is full.
 * 
 */
public:
    bool isFull(){
        if(top == arraySize-1){
            return true;
        }else{
            return false;
        }
    }


/**
 * @brief Display the elements in the stack
 * 
 */
public:
    void display(){
        string list = "[";
        for(int i=0; i<=top; i++){
            list += to_string(arrayList[top-i]) + ",";
        }list.pop_back();
        list += "]";
        cout << list << endl;
    }

};


/**
 * @brief Main function to implement stack objects and its methods.
 * 
 * @return int 
 */
int main() {
    srand(time(nullptr));
    Stack myStack;

    auto start = high_resolution_clock::now();

    myStack.push(rand());
    myStack.push(rand());
    myStack.push(rand());
    myStack.push(rand());
    myStack.push(rand());
    myStack.push(rand());
    myStack.push(rand());
    myStack.push(rand());
    myStack.push(rand());
    myStack.push(rand());

    myStack.display();

    for(int i =1; i<=5; i++){
        myStack.pop();
    }

    myStack.display();

    myStack.push(rand());
    myStack.push(rand());
    myStack.push(rand());
    myStack.push(rand());

    myStack.display();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution Time : ";
    cout << duration.count() << " microseconds" << endl;

    return 0;
}
