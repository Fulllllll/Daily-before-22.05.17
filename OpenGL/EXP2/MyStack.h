#pragma once
// MyStack.h: interface for the MyStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MySTACK_H__3657DC2D_E518_4E5E_9A32_023B2A260ED7__INCLUDED_)
#define AFX_MySTACK_H__3657DC2D_E518_4E5E_9A32_023B2A260ED7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define TURE 1
#define FALSE 0

struct dcpt
{
	int x;
	int y;
};

struct pointStruct
{
	dcpt point;
	pointStruct* pNext;
};

class CMyStack
{
public:
    CMyStack();
    virtual ~CMyStack();
    BOOL pop();
    void push(dcpt pt);
    void empty();
    dcpt getTop();
    BOOL isEmpty();
private:
    pointStruct* pHead;
    pointStruct* p1;
    pointStruct* pTop;

};

#endif // !defined(AFX_MySTACK_H__3657DC2D_E518_4E5E_9A32_023B2A260ED7__INCLUDED_)
