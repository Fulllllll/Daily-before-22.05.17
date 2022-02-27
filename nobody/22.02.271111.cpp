//#include<bits/stdc++.h>
//using namespace std;
//
//int f[11];
//int n, ans;
//
//void check()
//{
//	int num = 0;
//	int num1, num2;
//	for (int i = 1; i <= 7; i++)
//	{
//		num = num * 10 + f[i];
//		if (num > n) return;
//		num1 = num2 = 0;
//		for (int j = i + 1; j < 9; j++)
//		{
//			num1 = num1 * 10 + f[j];
//			num2 = 0;
//			for (int k = j + 1; k <= 9; k++) 
//				num2 = num2 * 10 + f[k];
//
//			if (num1 % num2 == 0)
//			{
//				if (num + num1 / num2 == n) ans++;
//			}
//		}
//	}
//}
//int main()
//{
//	while (~scanf("%d", &n))
//	{
//		ans = 0;
//		for (int i = 1; i <= 9; i++) f[i] = i;
//		do {
//			check();
//		} while (next_permutation(f + 1, f + 1 + 9));
//		cout << ans << endl;
//	}
//	return 0;
//}

//int main()
//{   //Êä³öÈ«ÅÅÁĞ
//	int arr[] = { 2, 1, 3, 4};
//	do {
//		for (int i = 0; i < 4; i++)
//		{
//			printf("%d", arr[i]);
//		}
//		printf("\n");
//	} while (next_permutation(arr, arr + 4));
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//
//int N, K;
//int a[100001], b[100001];
//int counts = 0;
//
//bool check(int x)
//{
//	counts = 0;
//	for (int i = 1; i <= N; i++)
//		counts += (a[i] / x) * (b[i] / x);
//	if (counts < K)
//		return false;
//	else return true;
//}
//int main()
//{
//	cin >> N >> K;
//	int l = 1, r = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> a[i] >> b[i];
//		r = r > (a[i] < b[i] ? a[i] : b[i]) ? r : (a[i] < b[i] ? a[i] : b[i]);
//	}
//	while (l < r)
//	{
//		int mid = l + (r - l + 1) / 2;
//		if (check(mid))
//			l = mid;
//		else r = mid - 1;
//	}
//	cout << l << endl;
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[100005];

bool check(int x)
{
	int count = 1, sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sum + arr[i] > x)
		{
			count++;
			sum = 0;
		}
		sum += arr[i];
	}
	return count <= m;
}

int main()
{
	cin >> n >> m;
	int l = 0, r = 1e9;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		l = l > arr[i] ? l : arr[i];
	}
	while (l < r)
	{
		int mid = l + (r - l) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << endl;
	return 0;
}