/**
 * Michael Farmer
 * CS 124
 * Section A
 */

#ifndef PROJECT2_QUEUE_H
#define PROJECT2_QUEUE_H

#include "Node.h"
#include <iostream>
using std::cout, std::endl;

/*
 * Queue class
 * All Nodes will point to the Node behind.
 */
template<typename Object>
class Queue {
private:

    //initialize fields for the front and rear of the queue
    Node<Object>* front;
    Node<Object>* rear;

public:
    /**
     * The default constructor takes in no parameters and sets the front and rear
     * pointers to nullptr.
     */
    Queue() {
        // Start with an empty Stack
        front = nullptr;
        rear = nullptr;
    }

    /**
     * The destructor Queue() takes in no parameters and dequeues all
     * elements in the queue when the main function reaches it's return statement.
     */
    ~Queue() {
        // Make sure no heap allocation
        while (front != nullptr) {
            dequeue();
        }
        cout << "No memory leaks!" << endl;
    }

    /**
     * The enqueue method will take in an Object as a parameter and will add it
     * to the rear of the queue.
     *
     * @param item is of the type Object
     */
    void enqueue(Object item) {
        // Store the item in a Node in heap memory
        Node<Object>* newNodePtr = new Node<Object>(item);

        //if rear is nullptr, then newNodePtr has to be the front and the rear.
        if(rear == nullptr){
            rear = newNodePtr;
            front = newNodePtr;
            return;
        }

        // Have the previous rear point to the new node.
        rear->setNext(newNodePtr);

        // The new Node becomes rear
        rear = newNodePtr;
    }

    /**
     * The dequeue method will remove the item at the front of the queue and set the
     * subsequent item to be the new front.  It will return a copy of the original front
     * item to the user.
     *
     * @return frontCopy is a copy of the first item in the queue
     */
    Object dequeue() {
        // Check that there is a Node to pop
        if (front == nullptr) {
            // The Stack is empty
            return Object();
        }
        // Create a copy of the value to be returned
        Object item = front->getItem();
        // Store a copy of front
        Node<Object>* frontCopy = front;
        // Update front
        front = front->getNext();

        //if front is nullptr, then rear is nullptr
        if(front == nullptr){
            rear = nullptr;
        }

        // Delete the Node from heap memory
        delete frontCopy;
        // Return the value being dequeued
        return item;
    }

    /**
     * The search method takes in an Object type called item and searches the queue
     * for that item.  It will return true if it is present and false otherwise.
     *
     * @param item is of the type Object
     * @return a boolean value depending on the presence of the item in the queue
     */
    bool search(Object item) const {
        Node<Object>* frontCopy = front;
        while (frontCopy != nullptr) {
            if (frontCopy->getItem() == item) {
                return true;
            }
            frontCopy = frontCopy->getNext();
        }
        return false;
    }

    /**
     * The print method takes in no parameters and displays the contents of the queue.
     */
    void print() const {
        cout << "Front of queue" << endl;
        Node<Object>* frontCopy = front;
        while (frontCopy != nullptr) {
            cout << frontCopy->getItem() << endl;
            frontCopy = frontCopy->getNext();
        }
        cout << "Rear of queue" << endl;
    }
};

#endif //PROJECT2_QUEUE_H
