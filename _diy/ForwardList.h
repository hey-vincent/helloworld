/*
 * ForwardList.h
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Vincent
 */

#include <iostream>
#include <memory.h>
using namespace std;

#ifndef HDIW_FORWARDLIST_H_
#define HDIW_FORWARDLIST_H_

template <typename T > class _ForwardList {

public:
	_ForwardList()
	{
		m_size = 10;
		m_begin = new T[m_size];
	}

	_ForwardList(int nSize,T t)
	{
		m_begin = new T[nSize];
		cout<< "default value:" <<t << endl;
		memset(m_begin,t,nSize);
		m_size = nSize;
	}

	virtual ~_ForwardList()
	{
		delete m_begin;
	}


	T* begin()
	{
		return m_begin;
	}

	T GetAt(int index)
	{
		return *(m_begin + index);
	}

	int size()
	{
		return m_size;
	}


	void push_back(T t)
	{

	}

private:
	T*	m_begin;
	int m_size;

};

#endif /* HDIW_FORWARDLIST_H_ */
