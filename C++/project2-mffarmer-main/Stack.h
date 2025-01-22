/**
 * Michael Farmer
 * CS 124
 * Section A
 */

#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <iostream>
using std::cout, std::endl;

/*
 * Stack class
 * All Nodes will point to the Node below
 */
template<typename Object>
class Stack {
private:
    //initialize top field
    Node<Object>* top;

public:
    /**
     * The Stack default constructor takes in no parameters and sets the top pointer to
     * nullptr.
     */
    Stack() {
        // Start with an empty Stack
        top = nullptr;
    }

    /**
     * The destructor ~Stack() takes in no parameters and clears the stack at the end of the
     * object's lifetime, ensuring no memory leaks.
     */
    ~Stack() {
        // Make sure no heap allocation
        while (top != nullptr) {
            pop();
        }
        cout << "No memory leaks!" << endl;
    }

    /**
     * The push method takes in one parameter, of type Object, and adds that item to the top
     * of the stack.  It sets the top pointer to the newest item and links the new item to the
     * item below it in the stack.
     *
     * @param item is an Object type.
     */
    void push(Object item) {
        // Store the item in a Node in heap memory
        Node<Object>* newNodePtr = new Node<Object>(item);
        // Have the new Node point to top
        newNodePtr->setNext(top);
        // The new Node becomes top
        top = newNodePtr;
    }

    /**
     * The pop method removes the top item of the stack and returns a copy of that
     * item to the user.  It reassigns the top pointer to point to the subsequent item in
     * the stack.
     *
     * @return a copy of the top item that was removed from the stack
     */
    Object pop() {
        // Check that there is a Node to pop
        if (top == nullptr) {
            // The Stack is empty
            return Object();
        }
        // Create a copy of the value to be returned
        Object item = top->getItem();
        // Store a copy of top
        Node<Object>* topCopy = top;
        // Update top
        top = top->getNext();
        // Delete the Node from heap memory
        delete topCopy;
        // Return the value being popped
        return item;
    }

    /**
     * The search method takes in one parameter, of type Object, and searches the
     * stack for that item.  If the item is found in the stack, the method will return true,
     * otherwise will return false.
     *
     * @param item is an Object type
     * @return boolean value depending on the presence of the item in the stack
     */
    bool search(Object item) const {
        Node<Object>* topCopy = top;
        while (topCopy != nullptr) {
            if (topCopy->getItem() == item) {
                return true;
            }
            topCopy = topCopy->getNext();
        }
        return false;
    }

    /**
     * The print method takes in no parameters and displays the contents of the stack to the user.
     */
    void print() const {
        cout << "Top of Stack" << endl;
        Node<Object>* topCopy = top;
        while (topCopy != nullptr) {
            cout << topCopy->getItem() << endl;
            topCopy = topCopy->getNext();
        }
        cout << "Bottom of Stack" << endl;
    }
};

#endif
