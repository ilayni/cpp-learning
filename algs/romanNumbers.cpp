#include <vector>
#include <iostream>


const string convertToThousands[]
{
    "M",
    "MM",
    "MMM"
}

const string convertToHundreds[]
{
    "C",
    "CC",
    "CCC"
    "CD"
    "D"
    "DC"
    "DCC"
    "DCCC"
}


vecotr<char> decToRoman(int decimal)
{
    vecotr<string> res = new vector<char>();

    int curFig;
    int tempNum = decimal;
    string curString;
    curfig = decimal/1000;
    curString = convertToThousands[curfig-1];
    tempNum = tempNum - curfig*1000;






}