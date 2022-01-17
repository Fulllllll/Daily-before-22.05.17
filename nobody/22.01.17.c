#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//#include <math.h>
//static int a[100010];
//int* printNumbers(int n, int* returnSize) {
//	*returnSize = pow(10, n) - 1;
//	for (int i = 0; i < *returnSize; i++)
//	{
//		a[i] = i + 1;
//	}
//	return a;
//}


//int main()
//{
//
//	//char c2[] = { '\x10', '\xa', '\8' };
//	//for (int i = 0; i < 3; i++)
//	//{
//	//	printf("%c\n", c2[i]);
//	//}
//
//	int b; char c[10];
//	scanf("%d%s", b, &c);
//	printf("%d\n", b);
//	printf("%s", c);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int year, month, day, time = 0, i;
//    int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//    while ((scanf("%d %d %d", &year, &month, &day)) != EOF)
//    {
//
//        if (month > 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))//≈–∂œ «∑Ò»ÚƒÍ
//        {
//            for (i = 0; i < month - 1; i++)
//            {
//
//                time = a[i] + time;
//
//            }
//            printf("%d\n", time + day + 1);
//            time = 0;
//        }
//        else
//        {
//            for (i = 0; i < month - 1; i++)
//            {
//                time = a[i] + time;
//
//            }
//            printf("%d\n", time + day);
//            time = 0;
//        }
//    }
//    return 0;
//}
//
//#include <bits/stdc++.h>
//using namespace std;
//
//int y, m, d;
//int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//int ans;
//
//int main()
//{
//    cin >> y >> m >> d;
//    int run = 0;
//    if (m > 2 && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)) run++;
//    for (int i = 0; i < m - 1; i++)
//    {
//        ans += a[i];
//    }
//    ans += run;
//    ans += d;
//    cout << ans << endl;
//    return 0;
//}



//int main() 
//{ char s[] = "\\123456\123456\t"; 
//printf("%s\n", s);
//printf("%d\n", strlen(s)); return 0; }



#include <stdio.h> 

int main() { int a = 3; printf("%d\n", (a += a -= a * a)); return 0; }