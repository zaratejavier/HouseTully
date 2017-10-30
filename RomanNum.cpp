//
// Created by Javier Zarate on 10/26/17.
//
#include "RomanNum.h"


/*!
 * Test to make sure that empty objects are set to zero
 * Test reading in a number.
 *	Test a bigger number.
 */
void testConstructor()
{
    Roman blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    Roman a("LXVI");
    checkTest("testConstructor #2", 66, a);

    //Test a bigger number.
    Roman b("MMMDDCCLLXXVVII");
    checkTest("testConstructor #3", 4332, b);

}

/*!
 *Test adding two roman objects
 *Test adding an object with an int
 *Test adding an int with an object
 */
void testOperatorPlus()
{
    //Test adding two roman objects
    Roman a("XVI");
    Roman b("MDCLXVI");
    Roman c = a + b;
    checkTest("testOperatorPlus #1", 1682, c);

    //make sure the left and right operands weren't modified
    checkTest("testOperatorPlus #2", 16, a);
    checkTest("testOperatorPlus #3", 1666, b);

    c = a + 52;
    checkTest("testOperatorPlus #4", 68, c);
    //make sure the left operand wasn't modified
    checkTest("testOperatorPlus #5", 16, a);

    c = 578 + a;
    checkTest("testOperatorPlus #6", 594, c);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlus #7", 16, a);

}

/*!
 * Test adding two roman objects
 * Test adding on an integer
 */
void testOperatorPlusEqual()
{
    Roman a("MLII");
    Roman b("DDCCI");
    a += b;
    checkTest("testOperatorPlusEqual #1", 2253, a);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlusEqual #2", 1201, b);

    b += 17;
    checkTest("testOperatorPlusEqual #3", 1218, b);
}

/*!
 *Test prefix increment
 */
void testOperatorIncrement()
{
    //Test prefix increment
    Roman a("MLII");
    Roman b("DDCCI");
    b = ++a;
    checkTest("testOperatorIncrement #1", 1053, a);
    checkTest("testOperatorIncrement #2", 1053, b);
}

/*!
 * A test function that needs to access private class members.
 */
void testOutput()
{
    Roman a("MDCLXVI");
    string b = a.convertToRoman();
    checkTest("testOutput #1", "MDCLXVI", b);

    //This is really the value 7.  Your code should correctly read this in and convert it back to VII.
    Roman c("IIIIIII");
    b = c.convertToRoman();
    checkTest("testOutput #2", "VII", b);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 *helps with testing to see if it passes the test
 * @param testName: a string name
 * @param whatItShouldBe: an integer
 * @param obj: a roman object
 * @return : returns a true or a false
 */
bool checkTest(string testName, int whatItShouldBe, const Roman& obj)
{
    if(whatItShouldBe == obj.value)
    {
        cout<<"Passed "<<testName<< endl;
        return true;
    }
    else
    {
        cout<<"****** Failed test "<<testName<<"******"<<endl<<" Object contained: "
            <<obj.value<<endl<<" Output should have contained: "<<whatItShouldBe<<endl;
        return false;
    }
}

/*!
 *Defualt constructor
 */
Roman::Roman()
{
    value = 0;
}

/*!
 *The constructor which accepts a string and converts it internally to an integer.  It actually just forwards it onto convertFromRoman()
 * @param str: a string constant
 */
Roman::Roman(const string &str)
{
    convertFromRoman(str);
}

/*!
 *The method that helps us take an roman numeral in a string and convert it into the integer.
 * @param roman: a constant roman
 */
void Roman::convertFromRoman(const string &roman)
{
    value = 0;

    for (int i = 0; i <roman.length(); i++)
    {
        if(roman.at(i)=='X')
        {
            value = value + 10;
        }
        else if(roman.at(i)=='L')
        {
            value = value + 50;
        }
        else if(roman.at(i)=='V')
        {
            value = value + 5;
        }
        else if(roman.at(i)=='I')
        {
            value = value + 1;
        }
        else if(roman.at(i)=='D')
        {
            value = value + 500;
        }
        else if(roman.at(i)=='M')
        {
            value = value + 1000;
        }
        else if(roman.at(i)=='C')
        {
            value = value + 100;
        }
    }
}

/*!
 *The method that helps us take an integer and turn it into a roman numeral
 * @return: the Roman value
 */
string Roman::convertToRoman() const
{
    string RomanVal= "";
    unsigned int tempValue = value;

    while (tempValue>0)
    {
        if(tempValue >= 1000)
        {
            tempValue = tempValue -1000;
            RomanVal = RomanVal + 'M';
        }
        else if( tempValue >= 500)
        {
            tempValue = tempValue -500;
            RomanVal = RomanVal + 'D';
        }
        else if( tempValue >=100) {
            tempValue = tempValue - 100;
            RomanVal = RomanVal + 'C';
        }
        else if (tempValue >= 50)
        {
            tempValue = tempValue -50;
            RomanVal = RomanVal + 'L';
        }
        else if (tempValue>=10)
        {
            tempValue= tempValue -10;
            RomanVal = RomanVal + 'X';
        }
        else if (tempValue>=5)
        {
            tempValue= tempValue -5;
            RomanVal = RomanVal + 'V';
        }
        else if ( tempValue>= 1)
        {
            tempValue = tempValue -1;
            RomanVal = RomanVal + 'I';
        }
    }
    return RomanVal;
}

/*!
 *The left and right operands are Roman objects
 * @param rhs: adds the "right hand side" which is a roman value to the new value
 * @return: new value
 */
Roman Roman::operator+( const Roman& rhs) const
{

    Roman newValue;
    newValue.value = value + rhs.value;
    return newValue;
}

/*!
 *The left operand is a Roman object, the right is an int number.
 * @param rhs: adds the "right hand side" to the new value
 * @return: new value
 */
Roman Roman::operator+(const int rhs) const
{
    Roman newValue;
    newValue.value = value + rhs;
    return newValue;
}

/*!
 *The left operand is an int, the right operand is a Roman object.
 * @param lhsValue: is a constant integer.
 * @param rhs: is a constant Roman "right hand side"
 * @return: the new Value
 */
Roman operator+(const int lhsValue,  const Roman& rhs)
{
    Roman newValue;
    newValue.value = lhsValue + rhs.value;

    return newValue;
}

/*!
 *The left and right operands are Roman objects, but the left operand can change.
 * @param rhs: is the "right hand side" which is a constant roman.
 */
void Roman::operator+=(const Roman& rhs)
{
    value += rhs.value;


}

/*!
 *the left operand is a Roman object, the right is an int number. The left operand can change.
 * @param rhs: is the "Right Hand side" which is an Integer constant
 */
void Roman::operator+=(const int rhs)
{
    value += rhs;
}

/*!
 *The prefix ++ operator
 * @return: new value
 */
Roman Roman::operator++()
{
    Roman newValue;
    newValue.value = ++value;
    return newValue;
}

/*!
 *
 * @param testName: a string name
 * @param whatItShouldBe: a string name
 * @param whatItis: what string name
 * @return: a true or a false
 */
bool checkTest(string testName, string whatItShouldBe, string whatItis)
{
    if(whatItShouldBe == whatItis)
    {
        cout<<"Passed "<<testName<<endl;
        return true;
    }
    else
    {
        cout<<"****** Failed test"<<testName<<" ****** "<<endl<<" Object contained: "
            <<whatItis<<endl<<"Output should have contained: "<<whatItShouldBe<<endl;
        return false;
    }
}

//Good work!! 
