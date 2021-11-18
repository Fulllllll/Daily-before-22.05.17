// MyStack.cpp: implementation of the MyStack class.
//
//////////////////////////////////////////////////////////////////////

#include "MyStack.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyStack::CMyStack()
{

    pHead = new pointStruct;
    p1 = pHead;
    pTop = pHead;
    pHead->pNext = NULL;
}
CMyStack::~CMyStack()
{
    while (pTop != NULL)
    {
        p1 = pTop;
        pTop = pTop->pNext;
        delete p1;
    }
}

BOOL CMyStack::pop()
{
    if (pTop == pHead)
        return 0;
    p1 = pTop;
    pTop = pTop->pNext;
    delete p1;
    return TURE;
}
void CMyStack::push(dcpt pt)
{
    p1 = new pointStruct;
    p1->point = pt;
    p1->pNext = pTop;
    pTop = p1;
}

void CMyStack::empty()
{
    while (pTop != pHead)
    {
        p1 = pTop;
        pTop = pTop->pNext;
        delete p1;
    }
}
dcpt CMyStack::getTop()
{
    return pTop->point;
}

BOOL CMyStack::isEmpty()
{

    if (pTop == pHead)
        return TURE;
    return FALSE;
}
