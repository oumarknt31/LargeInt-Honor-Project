//
//  DoublyLinkedList.hpp
//  Large Integer
//
//  Created by Mariia Romaniuk
//



#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;



template <class Type>
struct Node {
    Type info;
    Node<Type> *next;
    Node<Type> *prev;
};

template <class Type>
class DoublyLinkedList {

    // Overloaded input and output operators
    friend ostream& operator << (ostream& out, const DoublyLinkedList<Type> &);
    friend istream& operator >> (istream& in, DoublyLinkedList<Type> &);

protected:
    int length, max;
    // Pointer to the first node
    Node<Type> *first;
    // Pointer to the last node
    Node<Type> *last;
    // Pointer to the current node
    Node<Type> *iterator;

public:
    // Constructor
    DoublyLinkedList();

    // Destructor
    ~DoublyLinkedList();

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList<Type> &);

    // Overloaded assignment operator
    DoublyLinkedList operator = (const DoublyLinkedList<Type> &);

    // List initialization function
    void initializeList();

    // Function to check doubly linked list is empty
    bool isEmpty() ;

    // Get the lengh of doubly linked list
    int getLength();

    // Set the size of doubly linked list
    void setLength(int n);

    // Returns true if parameter item is in the list, false otherwise
    bool searchItem(Type item);

    void deleteItem(Type item);

    // Insert item to the front of the list
    void insertItemFront(const Type &);

    // Insert item to the back of the list
    void insertItemBack(const Type &);

    // Function to print list
    void printList();

    // Deletes first item in the list
    void deleteFirst();

    // Deletes last item in the list
    void deleteLast();

    // Function that returns number of itemes in the list
    int getNumOfItem(Type);

    // Check if current next is a null pointer
    bool isNextNull();

    // Set iterator to the first item of the list
    void setIteratorFirst();

    // Set iterator to the last item of the list
    void setIteratorLast();

    // Set iterator to the next node
    void setIteratorNext();

    // Set iterator to the previous node
    void setIteratorPrev();

    // Check if iterator finished traversing the list
    bool didIteratorFinish();

    // Get the data from the current node
    Type getIteratorInfo();

    void destroy();

    void copy(const DoublyLinkedList<Type> &other);

};

#endif /* DoublyLinkedList_hpp */