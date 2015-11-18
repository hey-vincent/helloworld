#pragma onece
#include <typeinfo>
#include <iostream>
using namespace std;




void showVector(vector<int>& vec);  //原始的打印容器中的全部元素的函数




void  _auto();
void  _container();
void  _front_back();
void  _resize();
void  _at();
void  _erase();


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

