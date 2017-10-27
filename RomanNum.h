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
    //string convertToRoman() const;  //The method that helps us take an integer and turn it into a roman numeral
    void convertFromRoman(const string&);  //The method that helps us take an roman numeral in a string and convert it into the integer.

public:
    Roman();    // Default constructor
    Roman(const string&);  //The constructor which accepts a string and converts it internally to an integer.// It actually just forwards it onto convertFromRoman()

    friend bool checkTest(string, int, const Roman&); //A testing function.  It is friended so it can access the class.
    friend void testOutput(); //Another test function that needs to access private class members.

};


#endif //ROMANTEST_ROMANNUM_H
