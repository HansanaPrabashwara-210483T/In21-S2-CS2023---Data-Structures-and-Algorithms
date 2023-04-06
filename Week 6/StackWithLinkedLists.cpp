/**
 * @file main.cpp
 * @author D.G.Hansana Prabashwara (210483T)
 * @brief 
 * @version 0.1
 * @date 2023-04-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


/**
 * @brief Create node objects to implement singly linked list
 * 
 */
class Node { ;
public:
    int data;
public:
    Node* next;

/**
 * @brief the constructor to initialize the node instances with given value 
 * @param value value to be in node
 */
public:
    Node(int value){
        data = value;
    }
};





/**
 * @brief Create stack instances using linkedlists
 * 
 */
class Stack{

private:
    Node* top;
private:
    int size;

/**
 * @brief Constructor to the stack instances. Upon initializing the top node is set to null.
 * 
 */
public:
    Stack(){
        top = NULL;

    }

/**
 * @brief Push given value to the top of the stack
 * @param value the value to be pushed into the list
 */
public:
    void push(int value) {
        Node* latestNode = new Node(value);
        if (top == NULL) {
            top = latestNode;
        } else {
            latestNode->next = top;
            top = latestNode;
        }
        size++;
    }

/**
 * @brief remove the top value of the stack and return the top value
 * 
 */
public:
    int pop(){
        if(top == NULL){
            throw underflow_error( "Stack Underflow");
        }
        int temp = top->data;
        top = top->next;
        size--;
        return temp;
    }

/**
 * @brief Return wheather the satack is empty
 * 
 */
public:
    bool isEmpty(){
        if(size == 0){
            return true;
        }else{
            return false;
        }
    }


/**
 * @brief Return the top element of the stack
 * 
 */
public:
    int stackTop() {
        if (size == 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

/**
 * @brief Display every elements in the stack.
 * 
 */
public:
    void display(){
        Node* temp = top;
        string list = "[";
        for(int i=0; i< size; i++){
            list += to_string(temp->data)+ ",";
            temp = temp->next;
        }
        if(size > 0){
            list.pop_back();
        }

        list += "]";
        cout << list << endl;
    }
};


/**
 * @brief Main function to implement the Stack instances and its methods.
 * 
 * @return int 
 */
int main(){
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

