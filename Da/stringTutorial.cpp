#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{

    //declare string
    string str0;
    cin >> str0; // take input without space
    cout << str0;

    string str1;
    getline(cin, str1); //take input with space
    cout << str1;

    string str2 = "NIRAJ VISHWAKARMA";
    cout << str2;

    string str3(10, 'a'); // declare string of size 10 with all characters 'a'
    cout << str3;

    string str4(str2); // copy string str2 to str4
    cout << str4;

    string str5; // assign using function
    str5.assign("HELLO");

    //FUNCTIONS
    //******* APPEND ***********
    string s1 = "fam";
    string s2 = "ily";

    s1.append(s2);   // 1. add s2 to s1 So, s1= family
    s1 = s1 + s2;    // 2.  s1 = family
    cout << s1 + s2; // Output = family but s1=fam && s2= ily

    //******* DELETE ***********

    s1.clear();

    //******* ACCESS ***********

    s2.at(0);
    //OR//
    cout << s2[0];

    //******* COMPARE ***********

    string sc1 = "abc";
    string sc2 = "xyz";

    if (sc2.compare == 0)
    {
        cout << "EQUAL";
    }
    if (sc2.compare > 0)
    {
        cout << "S2 IS GREATER";
    }
    if (sc2.compare < 0)
    {
        cout << "S1 IS GREATER";
    }

    //******* EMPTY ***********

    string se;
    se.clear();
    if (se.empty)
    {
        cout << "EMPTY";
    }
    else
    {
        cout << "NOT EMPTY";
    }

    //******* ERASE ***********

    string serase = "abc12345xyz";

    serase.erase(3, 5);
    cout << serase; //it will print abcxyz

    //******* FIND ***********

    string sf = "abcdefg";
    int pos = sf.find("def"); //return  index of first character
    cout << pos;              // 3 is the output

    //******* INSERT ***********

    string si = "2x12";
    si.insert(3, "=");
    cout << si; //2x1=2

    //******* SUB STRING ***********

    string sMainString = "HelloNiraj";
    string sSubString = sMainString.substr(5, 5); //5th position and 5 char
    cout << sSubString; // Niraj

    //*******CONVERT TO INTGER & TO STRING ***********

    string sString = "786";
    int sNum = stoi(sString);
    cout << sNum + 4; // 790

    string sToString = to_string(sNum);
    cout << sToString + "4"; //7864

    //******* RESIZE ***********
    string sr = "abcdxyz"

                cout
                << sr.resize(4); //abcd

    //******* SORT ***********
    //include header file <algorithm>
    string sSort = "dgbdfgsfgqaz";

    sort(sSort.begin(), sSort.end());

    return 0;
}
