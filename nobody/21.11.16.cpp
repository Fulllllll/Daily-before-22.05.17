#include <iostream>
using namespace std;
#define MAX 25

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n,i;
	cin >> n;
	int* p = NULL;
	p = (int*)malloc(4 * n);
	if (!p) return 1;
	for (i = 0; i < n; i++)
	{
		cin >> *(p + i);
	}
	

	int dp[MAX] = { 0 };
	int ans = 0;
	int j, k;
	for (i = 0; i < MAX; i++) dp[i] = 1;
	for (j = 0; j < n; j++)
	{
		for (k = 0; k < j; k++)
		{
			if (*(p + k) >= *(p + j))
				dp[j] = max(dp[j], dp[k] + 1);
		}
		ans = (max(ans, dp[j]));
	}
	cout << ans << endl;
}
