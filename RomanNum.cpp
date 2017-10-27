//
// Created by Javier Zarate on 10/26/17.
//

#include "RomanNum.h"

/*!
 *Defualt constructor
 */
Roman::Roman()
{
    value = 0;
}

//This helps with testing, do not modify.
void testConstructor()
{
    //Test to make sure that empty objects are set to zero.
    Roman blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    //Roman a ("LXVI");
    //checkTest("testConstructor #2", 66, a);

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
