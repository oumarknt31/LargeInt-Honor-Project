
#ifndef LargeInteger_hpp
#define LargeInteger_hpp


#include "DoublyLinkedList.cpp"


class LargeInt {

    // Overloaded input and output operators
    friend ostream& operator << (ostream& out, LargeInt&);
    friend istream& operator >> (istream& in, LargeInt&);

private:
    DoublyLinkedList<int> list;

public:
    // Constructor
    LargeInt();
    // Destructor
    ~LargeInt();

    // Overloaded arithmetic operators
    LargeInt operator + (LargeInt);
    LargeInt operator - (LargeInt);
    LargeInt operator * (LargeInt);
    LargeInt operator / (LargeInt);
    LargeInt operator % (LargeInt);
    LargeInt operator = (LargeInt);


    // Overloaded comparison operators
    bool operator == (LargeInt);
    bool operator >= (LargeInt);
    bool operator <= (LargeInt);
    bool operator < (LargeInt);
    bool operator > (LargeInt);

/***************************************************************************************************/
/* Helper Functions */

    // Check if number has a negative sign
    bool isNegative();
    // Helper function for overloaded * operator
    LargeInt multiply(LargeInt, const int);
};

#endif /* LargeInteger_hpp */