#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int y, m, d;
int month_len[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//321年 3 月 7 日  周一
//计算一天为星期几

//int days()
//{
//	return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400  +1)%7;
//}
//int main()
//{
//	cin >> y >> m >> d;
//	printf("%d", days());
//	return 0;
//}

//计算到1971年1月1日的天数 方法 1
//bool leap(int y)
//{
//	return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
//}
//int main()
//{
//	int ans = 0;
//	scanf("%d %d %d", &y, &m, &d);
//	while (y != 1971 || m != 1 || d != 1)
//	{
//		ans++;
//		if (--d == 0)
//		{
//			if (--m == 0)
//				--y;
//		}
//		if (d == 0)
//		{
//			d = month_len[m + 1];
//			if (m == 2 && leap(y))
//				d++;
//		}
//		if (m == 0)
//			m += 12;
//	}
//	cout << ans << endl;
//	return 0;
//}

//计算某两日之前的天数 方法 2

//bool leap(int y)
//{
//	return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
//}
//int main()
//{
//	int y1, m1, d1;
//	int y2, m2, d2;
//	cin >> y1 >> m1 >> d1;
//	cin >> y2 >> m2 >> d2;
//
//	int day1 = d1 - 1;
//	int day2 = d2 - 1;
//
//	for (int i = 1; i < m1; i++)
//	{
//		day1 += month_len[i];
//	}
//	for (int i = 1; i < m2; i++)
//	{
//		day2 += month_len[i];
//	}
//	
//	int ddd = 365*(y2 - y1);
//	for (int i = y1; i < y2; i++)
//	{
//		if (leap(i)) ddd++;
//	}
//
//	int ans = ddd + day1 - day2;
//	cout << ans << endl;
//	return 0;
//}


bool leap(int y)
{
    return ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0));
}
int day(char* date)
{
	//int y, m, d;
	sscanf(date, "%d-%d-%d", &y, &m, &d);
    int ans = 0;
    ans = d - 1;
    for (int i = 1; i < m; i++)
    {
        if (i == 2 && leap(i)) ans++;
        ans += month_len[i];
    }
    for (int i = 1971; i < y; i++)
    {
        if (leap(i)) ans += 366;
        else ans += 365;
    }
    return ans;
}

int daysBetweenDates(char* date1, char* date2) {
    return abs(day(date1) - day(date2));
}

int main()
{
	char s1[] = "2009-03-04";
	char s2[] = "2080-01-05";
	cout << daysBetweenDates(s1, s2);
	return 0;
}