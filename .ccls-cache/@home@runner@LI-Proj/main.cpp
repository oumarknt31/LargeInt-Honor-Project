 /*
 main.cpp
 Large Integer

 Created by Mariia Romaniuk

 Large number arithmetic using doubly linked list - the implementation of the class
 LargeInt which uses a dynamic physical structure to store the individual digits of a
 very large integers, and provide arithmetic operations that can be performed on them.
 Implementation of the huge integer type encapsulated as a C++ class, aggregating a
 list object for the internal representation of the huge integer value. Huge integers
 may be positive or negative (or zero).

 In particular, the class include:
 - A default constructor
 - Operator functions to overload the operators +, -, *, /, %
 - Operator functions to overload the operators ==, <, <=, >, >=
 - An operator function to overload the operator <<
 - An operator function to overload the operator >>
 */


#include "LargeInt.h"
#include <string>
#include <iostream>
using namespace std;


/*
int main(){

    LargeInt a, b, c;
    char op;

    cout << "Enter first number: " << endl;
    cin >> a;

    cout << "Enter second number: " << endl;
    cin >> b;

    cout << "Choose an operator (+,-,*,/,%)" << endl;
    cin >> op;

    if(op == '+')
        c = a + b;
    else if(op == '-')
        c = a - b;
    else if(op == '*')
        c = a * b;
    else if(op == '/')
        c = a / b;
    else if(op == '%')
        c = a % b;
    else
        exit(0);

    cout << "\nResult: ";
    cout << c << endl;

    return 0;

}
*/
int main() 
{
  LargeInt num1;
  LargeInt num2;


  cout<<"\nEnter the first large integer : ";
  cin >> num1;

  cout<<"\nEnter the second large integer : ";
  cin >> num2;
  
  if ( num1 > num2 )
  { cout <<"\n\nThe first large integer is greater"; }
  else if ( num1 == num2 )
  { cout <<"\n\nThe two large integers are the same"; }
  else if ( num1 < num2 )
  { cout <<"\n\nThe first large integer is smaller"; }

    LargeInt sum = num1 + num2;
    LargeInt difference = num1 - num2;
    LargeInt product = num1 * num2;
    LargeInt division = num1 / num2;
    LargeInt modulo = num1 % num2;

  cout<<"\n\nSum (+): " << sum;

  cout<<"\n\nDifference (-): " << difference;

  cout<<"\n\nProduct (*): " << product;

  cout<<"\n\nDivision (/): " << division;

  cout<<"\n\nModulo (%): " << modulo;
 
  return 0;
}