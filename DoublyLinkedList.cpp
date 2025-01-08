
#include "DoublyLinkedList.h"

// Overloaded operator <<
template <class Type>
ostream& operator << (ostream& out, const DoublyLinkedList<Type> &other){
    Node<Type> *current = other.first;
    while (current != NULL){
        out << current->info << ' ';
        current = current->next;
    }
    return out;
}

/***************************************************************************************************/

// Overloaded operator >>
template <class Type>
istream& operator >> (istream& in, DoublyLinkedList<Type> &other){
    string str;
    in >> str[0];
    return in;
}

/***************************************************************************************************/

// Constructor
template <class Type>
DoublyLinkedList<Type>::DoublyLinkedList()
{
    first = NULL;
    last = NULL;
    iterator = NULL;
    length = 0;
}

/***************************************************************************************************/

// Destructor
template <class Type>
DoublyLinkedList <Type>::~DoublyLinkedList(){
    destroy();
}

/***************************************************************************************************/

template <class Type>
void DoublyLinkedList <Type>::destroy()
{
    Node<Type> *current;
    while (first != NULL){
        current = first;
        first = first->next;
        delete current;
    }

    first = NULL;
    last = NULL;
    length = 0;
}

/***************************************************************************************************/

// Copy constructor
template <class Type>
DoublyLinkedList<Type>::DoublyLinkedList(const DoublyLinkedList<Type> &other){
    copy(other);
}

/***************************************************************************************************/

template <class Type>
void DoublyLinkedList<Type>::copy(const DoublyLinkedList<Type> &other)
{
    max = other.max;
    length = other.length;

    if (other.first == NULL)
        {
            first = NULL;
            last = NULL;
        }
        else
        {
            Node<Type> *current = other.first;
            Node<Type> *newNode;

            first = new Node<Type>;
            first->info = current->info;
            first->prev = NULL;

            Node<Type> *prevNode = first;

            while (current->next != NULL)
            {
                current = current->next;
                newNode = new Node<Type>;
                newNode->info = current->info;
                newNode->prev = prevNode;
                prevNode->next = newNode;
                prevNode = newNode;
            }

            last = prevNode;
            last->next = NULL;
        }
}

/***************************************************************************************************/

// Overloaded assignment operator
template <class Type>
DoublyLinkedList<Type> DoublyLinkedList<Type>::operator = (const DoublyLinkedList<Type> &other){
    // Check for self-assignment
    if (this != &other)
    {
        // Clear the current list
        destroy();
        // Perform deep copy of the list
        copy(other);
    }
    return *this;
}

/***************************************************************************************************/

// List initialization function
template <class Type>
void DoublyLinkedList<Type>::initializeList(){
    first = NULL;
    last = NULL;
    iterator = NULL;
    length = 0;
}

/***************************************************************************************************/

// Function to check if list is empty
template <class Type>
bool DoublyLinkedList<Type>::isEmpty(){
    return (first == NULL);
}

/***************************************************************************************************/

// Get length of the list
template <class Type>
int DoublyLinkedList<Type>::getLength(){
    return length;
}

/***************************************************************************************************/

// Set length of the list
template <class Type>
void DoublyLinkedList<Type>::setLength(int n){
    length = n;
}

/***************************************************************************************************/

// Insert item to the front of the list
template <class Type>
void DoublyLinkedList<Type>::insertItemFront(const Type &item){
    Node<Type> *newNode;
    newNode = new Node<Type>;
    newNode->info = item;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (first == NULL){
        first = last = newNode;
        first->prev = NULL;
        first->next = NULL;
    }
    else {
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }
    length++;
}

/***************************************************************************************************/

// Insert item to the back of the list
template <class Type>
void DoublyLinkedList<Type>::insertItemBack(const Type &item){
    Node<Type> *newNode;
    newNode = new Node<Type>;
    newNode->info = item;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (first == NULL)
        first = last = newNode;
    else {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
    length++;
}

/***************************************************************************************************/

template <class Type>
bool DoublyLinkedList<Type>::searchItem(Type item)
{
    Node<Type> *current = first;

    while (current != NULL)
    {
        if (current->info == item)
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

/***************************************************************************************************/

template <class Type>
void DoublyLinkedList<Type>::printList()
{
    if (isEmpty())
    {
        cout << "\nLIST IS EMPTY\n";
        return;
    }

    cout << "\nLIST : \n";
    Node<Type> *current = first;

    while (current != NULL)
    {
        cout << current->info << "\n";
        current = current->next;
    }
}

/***************************************************************************************************/

template <class Type>
void DoublyLinkedList<Type>::deleteItem(Type item)
{
    if (isEmpty())
    {  cout << "\nLIST IS EMPTY\n";  }

    else {
      Node<Type> *current = first;

      while (current != NULL && current->info != item)
      { current = current->next; }

      if (current == NULL)
      {
          cout << "\nITEM NOT IN THE LIST\n";
          return;
      }

      if (current->prev == NULL) // Deleting the first node
        { first = current->next; }
      else
        { current->prev->next = current->next; }

      if (current->next == NULL) // Deleting the last node
        { last = current->prev; }
      else
        { current->next->prev = current->prev; }

      delete current;
      length--;
    }
}

/***************************************************************************************************/

// Deletes first item in the list
template <class Type>
void DoublyLinkedList<Type>::deleteFirst(){
    if (!isEmpty()){
        Node<Type> *current = first;
        first = first->next;
        delete current;
    }
}

/***************************************************************************************************/

// Deletes last item in the list
template <class Type>
void DoublyLinkedList<Type>::deleteLast(){
    if (!isEmpty()){
        if (first == last){
            delete first;
            first = last = NULL;
        }
        else {
            Node<Type> *temp = last;
            last = last->prev;
            last->next = NULL;
            delete temp;
        }
        length--;
    }
}

/***************************************************************************************************/

// Function that returns number of itemes in the list
template <class Type>
int DoublyLinkedList<Type>::getNumOfItem(Type item){
    if (!isEmpty()){
        Node<Type> *current = first;
        int count = 0;

        while (current != NULL){
            if (current->info == item)
                count++;

            current = current->next;
        }
        return count;
    }
    return 0;
}

/***************************************************************************************************/

// Function to check if current next is a null pointer
template <class Type>
bool DoublyLinkedList<Type>::isNextNull(){
    if (iterator->next == NULL)
        return true;
    else
        return false;
}

/***************************************************************************************************/

// Set iterator to the first item of the list
template <class Type>
void DoublyLinkedList<Type>::setIteratorFirst(){
    iterator = first;
}

/***************************************************************************************************/

// Set iterator to the last item of the list
template <class Type>
void DoublyLinkedList<Type>::setIteratorLast(){
    iterator = last;
}

/***************************************************************************************************/

// Set iterator to the next node
template <class Type>
void DoublyLinkedList<Type>::setIteratorNext(){
    iterator = iterator->next;
}

/***************************************************************************************************/

// Set iterator to the previous node
template <class Type>
void DoublyLinkedList<Type>::setIteratorPrev(){
    iterator = iterator->prev;
}

/***************************************************************************************************/

// Check if iterator finished traversing the list
template <class Type>
bool DoublyLinkedList<Type>::didIteratorFinish(){
    return (iterator == NULL);
}

/***************************************************************************************************/

// Get the data from the current node
template <class Type>
Type DoublyLinkedList<Type>::getIteratorInfo(){
    return iterator->info;
}