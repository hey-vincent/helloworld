//Library
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <forward_list>
#include <deque>
#include <typeinfo>

//custom
#include "helloworld.h"

//using
using namespace std;


int main()
{
    _container();
    _auto();
    _front_back();
    _resize();
    _at();
    _erase();



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

void _front_back()
{
	// 每一个顺序容器 都支持 front函数
	// 除forward_list 外的所有容器都支持back函数
	vector<int> nVec;
	// front() for empty container
	//cout << "front for empty container :" << nVec.front() << endl; // crash cause the empty container .
	// We have to check nVec.empty() before call front and back
	nVec = {1,2,3,4,5};
	cout << "vector:" ; ShowContainer(nVec);
	cout << "front()\t" << nVec.front() << endl;
	cout << "back()\t" << nVec.back() << endl;

	list<string> nList = {"a","b","c","d"};
	cout << "list: " ; ShowContainer(nList);
	cout << "front()\t" << nList.front() << endl;
	cout << "back()\t" << nList.back() << endl;
	//访问容器中的元素 返回的都是该元素的应用 而非拷贝
	nList.front() = "d";
	nList.back() = "a";
	ShowContainer(nList);
}


void _resize()
{
	//resize 可以改变容器大小，新长度比原来长度大的话 会增加元素  否则 会删除多余元素
	//当然array不支持resize操作
	cout <<endl;
	vector<string> strVec(10,"a");
	cout << "vector:";ShowContainer(strVec);
	cout << "resize(20)";strVec.resize(20);ShowContainer(strVec);
	cout << "resize(30,b)";strVec.resize(30,"b");ShowContainer(strVec);
	cout << "resize(5,c)";strVec.resize(5,"c");ShowContainer(strVec);
}

void _at()
{
	// at 可以在对容器访问越界时抛出out_of_range异常
	try
	{
		cout << endl;
		deque<string> strDq = {"One","Two","Three"};
		ShowContainer(strDq);
		cout<< "deque.at(2) = " << strDq.at(2)<< endl;
		cout<< "deque.at(3)" <<strDq.at(3);
	}
	catch(...)
	{
		cout << "out of range"<< endl;
	}
}

void _erase()
{
	// forwad_list 有特殊版本的erase,且不支持pop_back
	// vector string 不支持 pop_front

	// clear
	string str;
	str = "Hello Wolrd !!!";
	ShowContainer(str);
	str.clear();
	ShowContainer(str);

	// pop
	deque<string> dqStr = {"hello", "world" ,"!!!"};
	ShowContainer(dqStr);
	dqStr.pop_front();
	dqStr.pop_back();
	ShowContainer(dqStr);
	dqStr.clear();
	if(!dqStr.empty())
	{
		dqStr.pop_back();
		dqStr.pop_front();
	}
	vector<int> nVec = {1,2,3,4,5,6,7,8,9,10};
	ShowContainer(nVec);

	vector<int>::iterator iter = nVec.erase(nVec.begin()+2, nVec.begin()+5);
	ShowContainer(nVec);
	cout << *iter << endl;

	iter = nVec.erase(iter);
	cout << *iter << endl;
	ShowContainer(nVec);

	//?
	for(vector<int>::iterator it = nVec.begin(); it != nVec.end(); it++)
	{
		auto &i = *it;
		if(( i % 2) == 0)
		{
			nVec.erase(it);
		}
	}
	ShowContainer(nVec);
}
