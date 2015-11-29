#include "helloworld.h"


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
    vector<int> vCelPhoneNum = {0,1,2,3,4,5,6,7,8,9,10};

    vector<int> copyCellPhoneNum(vCelPhoneNum);

    cout<< "vTelPhoneNum: " ; showVector(vTelPhoneNum);
    cout<< "vCelPhoneNum: " ; showVector(vCelPhoneNum);

    vTelPhoneNum.assign(vCelPhoneNum.begin(), vCelPhoneNum.end());
    cout << "\033[31m after vTelPhoneNum.assign(vCelPhoneNum): \033[0m" << endl;
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
	str = "Hello World !!!";
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

	//典型的erase操作
	cout << endl << "erase()" << endl;
	nVec = {1,2,3,4,5,6,7,8,9,10};
	for(vector<int>::iterator it = nVec.begin(); it != nVec.end(); cout << endl)
	{
		auto &i = *it;
		if(( i % 2) == 0)
		{
			cout << "删除" << i ;
			it = nVec.erase(it);
		}else{
			cout << "保留" << i ;
			it++;
		}
		cout << endl;
		ShowContainer(nVec);
	}
	ShowContainer(nVec);
}

void _charArray()
{
	// 下面两个数组的区别
	char ch[10] = {'1','2','3','4','5','6','7','8','9','\0',};
	char charray[10] = {'1','2','3','4','5','6','7','8','9','10',};
	cout << ch << endl;
	for(int i=0; i<10; i++)
	{
		cout<<charray[i] <<" " ;
	}

	cout << endl;
	char c = '\0';
	int  nEnd = (int)c;
	cout << nEnd << endl;
}


void _capacity()
{
	vector<int>ivec  = {1,2,3,4,5,6,7,8,9,10};
	cout << "size : "<<ivec.size() <<"capacity : "<<ivec.capacity() << endl;
	ivec.push_back(11);
	cout << "size : "<<ivec.size() <<"capacity : "<<ivec.capacity() << endl;
	ivec.resize(21,1);
	cout << "size : "<<ivec.size() <<"capacity : "<<ivec.capacity() << endl;
	ivec.push_back(12);
	cout << "size : "<<ivec.size() <<"capacity : "<<ivec.capacity() << endl;
	ShowContainer(ivec);
}

typedef struct _st
{
	char ch;
	char note[32];
	char tips[32];

	_st()
	{
		ch = '\0';
		memset(note, 0, 32);
		memset(tips, 0, 32);
	}
}ST;

void AnalyzeData(char* lp)
{
	char ch;
	ch = * lp;
	cout << "ch\t"<<ch << endl;

	char note[32] = {0};
	lp ++;
	memcpy(note,lp,32);
	string str(note);
	cout <<"note\t" <<str << endl;
}
void _sizeof()
{
	char ch[10] = {'1','2','3','4','5','6','7','8','9','\0',};
	cout << "sizeof :" << sizeof(ch) << endl;

	char lpData[65] = {0};
	ST st;
	st.ch = 'a';
	memcpy(st.note ,"Hello World!!!",32);;

	*lpData = st.ch;

	memcpy(lpData +1,st.note,32);

	memcpy(lpData + 33, st.tips,32);

	AnalyzeData(lpData);

	string str;
	str.append(lpData);
	cout << str << endl;
}
