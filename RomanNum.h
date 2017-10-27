//
// Created by Javier Zarate on 10/26/17.
//

#ifndef ROMANTEST_ROMANNUM_H
#define ROMANTEST_ROMANNUM_H
#include <iostream>
using namespace std;

//function prototype
void testConstructor();

//class definition
class Roman
{
private:
    unsigned int value;  //The roman numeral itself isn't stored.
public:
    Roman();    // Default constructor

    friend bool checkTest(string, int, const Roman&); //A testing function.  It is friended so it can access the class.
    friend void testOutput(); //Another test function that needs to access private class members.

};


#endif //ROMANTEST_ROMANNUM_H
