//Library
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <forward_list>
#include <deque>
#include <typeinfo>
#include <memory.h>
#include <iostream>
using namespace std;



#ifndef _HELLO_WORLD_H
#define _HELLO_WORLD_H



void  _auto();
void  _container();
void  _front_back();
void  _resize();
void  _at();
void  _erase();
void  _capacity();

void _sizeof();

void _charArray();

void showVector(vector<int>& vec);

template <typename T>
void ShowVariableInfo(T t)
{
    cout << t << " size: " << sizeof(t) <<"\t type:" << typeid(t).name() << endl;
}

template <typename T>
void ShowContainer(T c)
{
	cout <<"   type:" << typeid(c).name()<<"\tsize:\t" << c.size() << endl << "element:";
    for(typename T::const_iterator iter = c.begin(); iter != c.end(); iter++)
        {
            cout << *iter << " ";
        }
    cout << endl;
}

#endif
