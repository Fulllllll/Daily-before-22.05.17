//#include<bits/stdc++.h>
//using namespace std;
//
//typedef int ElementType;
//
//typedef struct AVLNode {
//	ElementType val;
//	AVLNode* lchild;
//	AVLNode* rchild;
//	AVLNode* parent;      //是否有必要
//	int height;
//}Node, AVLTree;
//
//Node* CreatNode(int val = 0);
//void Insert(Node*& root, ElementType val);
//int getHeight(Node* root);
//void updateHeight(Node* root);
//int getBalancedFactor(Node* root);
//
//void R(Node*& root);
//void L(Node*& root);
//
//void R(Node*& root)
//{
//	Node* temp = root->lchild;
//	root->lchild = temp->rchild;
//	temp->rchild = root;
//	updateHeight(root);
//	updateHeight(temp);
//	root = temp;
//}
//void L(Node*& root)
//{
//	Node* temp = root->rchild;
//	root->rchild = temp->lchild;
//	temp->lchild = root;
//	updateHeight(root);
//	updateHeight(temp);
//	root = temp;
//}
//int getHeight(Node* root)
//{
//	if (root == NULL) return 0;
//	else {
//		return root->height;
//	}
//}
//void updateHeight(Node* root) 
//{
//	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
//}
//int getBalancedFactor(Node* root)
//{
//	return getHeight(root->lchild) - getHeight(root->rchild);
//}
//
//
//Node* CreatNode(int val)
//{
//	Node* node = (Node*)malloc(sizeof(Node));
//	if (!node)
//	{
//		cout << "error" << endl;
//		exit(-1);
//	}
//
//	node->val = val;
//	node->lchild = node->rchild = node->parent = NULL;
//	node->height = 1;
//	return node;
//}
//
//void Insert(Node*& root, ElementType val)
//{
//	if (root == NULL)
//	{
//		root = CreatNode(val);
//		return;
//	}
//	if (val < root->val)
//	{
//		Insert(root->lchild, val);
//		updateHeight(root);
//		if (getBalancedFactor(root) == 2) {
//			if (getBalancedFactor(root->lchild) == 1)
//				R(root);
//			else if (getBalancedFactor(root->lchild) == -1) {
//				L(root->lchild);
//				R(root);
//			}
//		}
//	}
//	else if(val > root->val)
//	{
//		Insert(root->rchild, val);
//		updateHeight(root);
//		if (getBalancedFactor(root) == -2) {
//			if (getBalancedFactor(root->rchild) == -1)
//				L(root);
//			else if (getBalancedFactor(root->rchild) == 1) {
//				R(root->rchild);
//				L(root);
//			}
//		}
//	}
//	else
//	{
//		cout << "error" << endl;
//		system("pause");
//		exit(-1);
//	}
//}
//
//
//
//int main()
//{
//	AVLTree* Root = NULL;
//	Insert(Root, 50);
//	Insert(Root, 25); 
//	Insert(Root, 75);
//	Insert(Root, 20);
//	Insert(Root, 30);
//	Insert(Root, 60);
//	Insert(Root, 55);
//
//	return 0;
//}

//#include<bits/stdc++.h>
//#include<stack>
//using namespace std;
//
//class Solution {
//public:
//    stack<char> STACK;
//    bool check(char c)
//    {
//        if (c == ')' && STACK.top() == '(')
//            return 0;
//        if (c == '}' && STACK.top() == '{')
//            return 0;
//        if (c == ']' && STACK.top() == '[')
//            return 0;
//        return 1;
//    }
//    bool isValid(string s) {
//        STACK.push('&');
//        for (char c : s)
//        {
//            if (check(c)) 
//                STACK.push(c);
//            else
//            {
//                STACK.pop();
//            }
//        }
//        STACK.pop();
//        if (STACK.empty()) return 1;
//        else return 0;
//    }
//};
//
//int main()
//{
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//
//typedef int STDataType;
//typedef struct ST
//{
//	STDataType* a;
//	int top;		// 栈顶
//	int capacity;  // 容量 
//}ST;
//// 初始化栈 
//void StackInit(ST* ps);
//// 入栈 
//void StackPush(ST* ps, STDataType data);
//// 出栈 
//void StackPop(ST* ps);
//// 获取栈顶元素 
//STDataType StackTop(ST* ps);
//// 获取栈中有效元素个数 
//int StackSize(ST* ps);
//// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
//bool StackEmpty(ST* ps);
//// 销毁栈 
//void StackDestroy(ST* ps);
//
////#include "Stack.h"
//
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity + 5;
//		ps->a = (STDataType*)realloc(ps->a, newCapacity * sizeof(STDataType));
//		if (ps->a == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ps->capacity = newCapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	ps->top--;
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	return ps->a[ps->top - 1];
//}
//
//
//int StackSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//typedef int QDataType;
//typedef struct QueueNode
//{
//	QDataType data;
//	struct QueueNode* next;
//}QNode;
//
//typedef struct Queue
//{
//	QNode* head;
//	QNode* tail;
//}Queue;
//
//void QueueInit(Queue* pq);
//void QueueDestory(Queue* pq);
//void QueuePush(Queue* pq, QDataType x);
//void QueuePop(Queue* pq);
//bool QueueEmpty(Queue* pq);
//size_t QueueSize(Queue* pq);
//QDataType QueueFront(Queue* pq);
//QDataType QueueBack(Queue* pq);
//
//
//Queue.h
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = pq->tail = NULL;
//}
//
//void QueueDestory(Queue* pq)
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	while (cur)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//}
//
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	assert(newnode);
//
//	newnode->data = x;
//	newnode->next = NULL;
//
//	if (pq->tail == NULL)
//	{
//		assert(pq->head == NULL);
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head && pq->tail);
//
//	if (pq->head->next == NULL)
//	{
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else
//	{
//		QNode* next = pq->head->next;
//		free(pq->head);
//		pq->head = next;
//	}
//}
//
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head == NULL;
//}
//
//size_t QueueSize(Queue* pq)
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	size_t size = 0;
//	while (cur)
//	{
//		size++;
//		cur = cur->next;
//	}
//	return size;
//}
//
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head);
//
//	return pq->head->data;
//}
//
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(pq->tail);
//
//	return pq->tail->data;
//}

#include<stack>
using namespace std;
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    }
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (this->empty()) exit(-1);
        if (!s2.empty())
        {
            int temp = s2.top();
            s2.pop();
            return temp;
        }
        else
        {
            while (!s1.empty())
            {
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
            int temp = s2.top();
            s2.pop();
            return temp;
        }
    }

    int peek() {
        if (this->empty()) exit(-1);
        if (!s2.empty())
        {
            return  s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
            return s2.top();
        }
    }

    bool empty() {
        if (s1.empty() && s2.empty())
            return true;
        else
            return false;
    }
};