//Library
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <forward_list>
#include <deque>

//custom
#include "helloworld.h"

//using
using namespace std;


int main()
{
    _container();
    
    _auto();
    return 0;
}

void showVector(vector<int>& vec)
{
    cout << "Size is :" << vec.size() <<  " ;\t";
    for(
        vector<int>::const_iterator iter = vec.begin();
        iter != vec.end();
        iter ++
        )
        {
            cout << *iter << " ";
        }
        cout << endl;
}


void  _container()
{
    cout << "Hello world!" << endl;
    //assign
    vector<int> vTelPhoneNum(8,1);
    vector<int> vCelPhoneNum{0,1,2,3,4,5,6,7,8,9,10};
    
    vector<int> copyCellPhoneNum(vCelPhoneNum);

    cout<< "vTelPhoneNum: " ; showVector(vTelPhoneNum);
    cout<< "vCelPhoneNum: " ; showVector(vCelPhoneNum);

    vTelPhoneNum.assign(vCelPhoneNum.begin(), vCelPhoneNum.end());
    cout << "\033[31mafter vTelPhoneNum.assign(vCelPhoneNum): \033[0m" << endl;
    cout<< "vTelPhoneNum: " ; showVector(vTelPhoneNum);
    cout<< "vCelPhoneNum: " ; showVector(vCelPhoneNum);

     vTelPhoneNum.assign(copyCellPhoneNum.rbegin(), copyCellPhoneNum.rend());
    cout << "\033[31m vTelPhoneNum.assign(copyCellPhoneNum.rbegin(), copyCellPhoneNum.rend());\033[m" << endl;
    cout<< "vTelPhoneNum: " ; showVector(vTelPhoneNum);
    cout<< "copyCellPhoneNum: " ; showVector(copyCellPhoneNum);

    cout <<vCelPhoneNum.max_size() << endl;
    ShowContainer(vTelPhoneNum);
    cout << endl;
}

void  _auto()
{
    auto nInt = 10; ShowVariableInfo(nInt);
    auto cChar = 'a';ShowVariableInfo(cChar);
    
    cout <<endl;
    cout << "int+char:" << endl;
    ShowVariableInfo(nInt+cChar);
    cout << "char+int:" << endl;
    ShowVariableInfo(cChar+nInt);
    
    cout <<endl;
    
    auto dFloat = 0.1;ShowVariableInfo(dFloat);
    auto dDouble = 0.0;ShowVariableInfo(dDouble);
    auto sString = "abc";ShowVariableInfo(sString);
    auto bBool = true;ShowVariableInfo(bBool);
    //auto bLong = ;??? how can I judge this variable is int or long?
    //And the same as 'float' with 'double'
    //What will happen if I plus an int with a char?
    //And how about auto for container?
    vector<int> aVec;
    auto vec = aVec; cout << typeid(vec).name() << endl;
    vec = {0,1,2,3,4,5};
    ShowContainer(vec);
}
