//
// Created by Javier Zarate on 10/26/17.
//
#include "RomanNum.h"

//This helps with testing, do not modify.
void testConstructor()
{
    //Test to make sure that empty objects are set to zero.
    Roman blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    Roman a ("LXVI");
    checkTest("testConstructor #2", 66, a);

    //Test a bigger number.
    //Roman b ("MMMDDCCLLXXVVII");
    //checkTest("testConstructor #3", 4332, b);}
}

//this helps with testing, do not modify
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

Roman::Roman(const string &str)
{
    convertFromRoman(str);
}

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

/*
string Roman::convertToRoman() const
{
    return std::string();
}
*/

//this helps with testing, do not modify
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
