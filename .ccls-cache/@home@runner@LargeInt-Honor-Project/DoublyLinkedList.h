
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
    Node<Type> *first;
    Node<Type> *last;
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

    // Chack if list is empty
    bool isEmpty() ;

    // Get the length of the list
    int getLength();

    // Returns true if parameter item is in the list, false otherwise
    bool searchItem(Type item);

    // Delete parameter item in the list
    void deleteItem(Type item);

    // Insert item to the front of the list
    void insertItemFront(const Type &);

    // Insert item to the back of the list
    void insertItemBack(const Type &);

    // Function to print list
    void printList();

    // Function that returns number of itemes in the list
    int getNumOfItem(Type);

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

/***************************************************************************************************/
    /* Helper Functions */

    // Initialize the list to an empty state.
    void initializeList();
    
    // Set the length of the list
    void setLength(int n);

    // Deletes first item in the list
    void deleteFirst();
    
    // Deletes last item in the list
    void deleteLast();

    // Check if current next is a null pointer
    bool isNextNull();
};

#endif 