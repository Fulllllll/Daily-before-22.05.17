#include<vector>
#include<deque>
#include<iostream>
#include<string>
#include<list>


using namespace std;

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	vector<int> v1(10);
//	vector<int> v2;
//
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	cout << v1[i] << endl;
//	//}
//	//cout << v1.capacity() << "  " << v1.size() << endl;
//	
//	
//	v2.push_back(458);
//	v2.push_back(423);
//	v2.push_back(42);
//	v2.push_back(4);
//	v2.pop_back();
//
//	for (int i = 0; i < v2.size(); i++)
//	{
//		cout << v2[i] << endl;
//	}
//	cout << v2.capacity() << "  " << v2.size() << endl;
//
//	//v2.clear();
//
//	//for (int i = 0; i < v2.size(); i++)
//	//{
//	//	cout << v2[i] << endl;
//	//}
//	//cout << v2.capacity() << "  " << v2.size() << endl;
//
//	v2 = { 1 };
//	for (int i = 0; i < v2.size(); i++)
//	{
//		cout << v2[i] << endl;
//	}
//	cout << v2.capacity() << "  " << v2.size() << endl;
//}


//#include <vector>
//#include <ctime>
//#include <iostream>
//using namespace std;
//
//void main()
//{
//	vector<int> arrar(1000000, 2);
//
//	clock_t sT1 = clock();
//	for (size_t i = 0; i < arrar.size(); i++)
//	{
//		arrar[i]++;
//	}
//	clock_t eT1 = clock();
//
//	cout << eT1 - sT1 << endl;
//
//	clock_t sT2 = clock();
//	for (vector<int>::iterator p = arrar.begin(); p != arrar.end(); p++)
//	{
//		*p++;
//	}
//	clock_t eT2 = clock();
//
//	cout << eT2 - sT2 << endl;
//}



//int main() {
//
//	vector<int> v(100);
//	cout << "capacity:" << v.capacity() << endl;
//	cout << "size:" << v.size() << endl;
//
//	v.resize(10);//此时 通过resize改变容器大小
//	cout << "capacity:" << v.capacity() << endl;
//	cout << "size:" << v.size() << endl;
//	//容量没有改变
//	
//	//利用swap，收缩内存空间
//	vector<int>(v).swap(v);
//	cout << "capacity:" << v.capacity() << endl;
//	cout << "size:" << v.size() << endl;
//
//	return 1;
//}

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	vector<int> v1(10,5);
//	vector<int> v2;
//
//
//
//	cout << v1.capacity() << "  " << v1.size() << endl;
//	cout << v2.capacity() << "  " << v2.size() << endl;
//
//	v2.swap(v1);
//
//	cout << v1.capacity() << "  " << v1.size() << endl;
//	cout << v2.capacity() << "  " << v2.size() << endl;
//
//}

//int main() 
//{
//
//	vector<int> v(100);
//	cout << "capacity:" << v.capacity() << endl;
//	cout << "size:" << v.size() << endl;
//
//	v.resize(10);//此时 通过resize改变容器大小
//	cout << "capacity:" << v.capacity() << endl;
//	cout << "size:" << v.size() << endl;
//	//容量没有改变
//
//	//利用swap，收缩内存空间
//	//vector<int>(v).swap(v);
//	//cout << "capacity:" << v.capacity() << endl;
//	//cout << "size:" << v.size() << endl;
//
//
//	vector<int> a(v);
//	a.swap(v);
//	cout << "capacity:" << v.capacity() << endl;
//	cout << "size:" << v.size() << endl;
//	return 1;
//}



//
//int main() {
//
//	vector<int> v;
//
//	//预先开辟空间
//	v.reserve(100000);
//
//	int* pStart = NULL;
//	int count = 0;
// 	for (int i = 0; i < 100000; i++) {
//		v.push_back(i);
//		if (pStart != &v[0]) {
//			pStart = &v[0];
//			count++;
//		}
//	}
//
//	cout << "count:" << count << endl;
//
//	system("pause");
//	return EXIT_SUCCESS;
//}

//class A
//{
//public:
//	int a;
//	int b;
//	A() = default;
//	A(int _a, int _b)
//	{
//		a = _a; b = _b;
//	}
//};
//class B
//{
//public:
//	int a;			//如果在类中对变量进行初始化?????
//	int b;
//	B(int _a, int _b)
//	{
//		a = _a; b = _b;
//	}
//	B(int g)
//	{
//		a = 1;
//	}
//};
//
//int main()
//{
//	//A A1;
//	//cout << A1.a << "  " << endl;
//	//cout << A1.b << "  " << endl;
//
//	B B1;
//	cout << B1.a << "  " << endl;
//	cout << B1.b << "  " << endl;
//	B1.b = 456;
//	cout << B1.a << "  " << endl;
//	cout << B1.b << "  " << endl;
//
//	B B2;
//	cout << B2.a << "  " << endl;
//	cout << B2.b << "  " << endl;
//
//	B B3(0);
//	cout << B3.a << "  " << endl;
//	cout << B3.b << "  " << endl;
//	return 0;
//}

//
//class asd
//{
//public:
//	int a=0;
//	asd() = default;
//};
//
//int main()
//{
//	asd aaa;
//
//	return 1;
//}


//int main()
//{
//	vector<int> v1(10);
//	v1 = { 1, 2, 3, 4, 5 };
//	//vector<vector<int>::iterator> iter(5);
//	//iter[0] = v1.begin();
//	//iter[1] = v1.end();
//	//cout << *(iter[0]) << endl;
//	//cout << *(iter[1]) << endl;
//
//	vector<int>::iterator it1, it2;
//	it1 = v1.begin();
//	it2 = v1.end() - 1;
//
//	cout << *it1 << endl;
//	cout << *it2 << endl;
//
//	
//	
//	
//	
//	//cout << &iter << " " << *iter << endl;;
//	//printf("%d 0x%x", iter, iter);
//
//	return 0;
//}


int main()
{
	string s1 = "Everything sucks!";
	cout << s1 << endl;

	string s2 = "asd";
	cout << s2 << endl;

	s2.assign(s1);
	cout << s2 << endl;

	s2.assign("I'm sad");
	cout << s2 << endl;


	s2.assign("I'm sad", 3);
	cout << s2 << endl;
	
	s2.assign(5, 'f');
	cout << s2 << endl;

	s2.assign(s1, 0, 5);
	cout << s2 << endl;


	vector<char> str(5,'s');
	//cout << str << endl;//error
	//s2 = str;//error
	s2.assign(str.begin(), str.end());
	cout << s2 << endl;


	return 0;
}
