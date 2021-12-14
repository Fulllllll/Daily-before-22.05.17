#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#define MAX 26
int dp[MAX], H[MAX];
int main()
{
	int i = 0, num = 0;
	int ret = 0;
	cin >> num;
	for (i = 0; i < num; i++)
	{
		cin >> H[i];
		dp[i] = 1;
	}
	for (int j = 0; j < num; j++)
	{
		for (int k = 0; k < j; k++)
		{
			if (H[k] >= H[j]) dp[j] = dp[j] > dp[k] + 1 ? dp[j] : dp[k] + 1;
		}
		ret = ret > dp[j] ? ret : dp[j];
	}
	cout << ret << endl;
	return 0;
}


//int mins[100], minv[100];
//int min = 9999999;
//int main()
//{
//	int N, M; 
//	for (int i = 1; i < 21; i++)
//	{
//		mins[i] = mins[i - 1] + i * i * 2;
//		minv[i] = minv[i - 1] + i * i * i;
//	}
//	scanf("%d%d", &N, &M);
//
//	int sum = 0, V = 0;
//	int H = M, h = N + 1, r = N + 1;
//	if (V > N)
//	{
//		printf("0");
//		return 0;
//	}
//	if (H == 0)
//	{
//		if (V == N && sum < min)
//			min = sum;
//		printf("%d\n", min);
//		return 0;
//	}
//	if (V + minv[H - 1] > N || sum + mins[H - 1] > min || (N - V) / r * 2 + sum >= min)
//	{
//		printf("%d\n", min);
//		return 0;
//	}
//	for (int i = r - 1; i >= H; i--)
//	{
//		if (H == M)		sum = i * i;
//		int hn = (N - V - minv[H - 1]) / (i * i);
//		int ht;
//		if (hn < (h - 1))
//			ht = hn;
//		else ht = h - 1;
//		for (int j = ht; j >= H; j--)
//		{
//			func(sum + 2 * i * j, i * i * j + V, H - 1, j, i);
//		}
//	}
//	printf("%d\n", min);
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int N, M; 
//int mins[30], minv[30];
//int min = 9999999;
//int dfs(int sum, int V, int H, int h, int r)
//{
//	if (V > N)
//		return min;
//	if (H == 0)
//	{
//		if (V == N && sum < min)
//			min = sum;
//		return min;
//	}
//
//	if (V + minv[H - 1] > N || (N - V) / r * 2 + sum >= min|| sum + mins[H - 1] > min)
//		return min;
//	for (int i = r - 1; i >= H; i--)
//	{
//		if (H == M)
//			sum = i * i;
//		int h2 = (N - V - minv[H - 1]) / (i * i);
//		int hx = (h2 < (h - 1)) ? h2 : (h - 1);
//		for (int j = hx; j >= H; j--)
//		{
//			dfs(sum + 2 * i * j, i * i * j + V, H - 1, j, i);
//		}
//	}
//	return min;
//}
//int main()
//{
//	for (int i = 1; i < 21; i++)
//	{
//		mins[i] = mins[i - 1] + i * i * 2;
//		minv[i] = minv[i - 1] + i * i * i;
//	}
//	scanf("%d%d", &N, &M);
//	if (dfs(0, 0, M, N + 1, N + 1) == 9999999) min = 0;
//	printf("%d\n", min);
//	return 0;
//}

//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//#define MAX_M 1000
//#define MAX_N 100
//int main()
//{
//    int w[MAX_N], c[MAX_N] = { 0 };
//    int f[MAX_N][MAX_M] = {0};
//    int num, V;
//    cin >> num >> V;
//    int i = 0;
//    for (i = 1; i <= num; i++)
//    {
//        cin >> w[i] >> c[i];
//    }
//    for (int i = 1; i <= num; i++)            
//    {
//        for (int j = 1; j <= V; j++)
//            if (j < w[i])
//                f[i][j] = f[i - 1][j];
//            else
//            {
//                if (f[i - 1][j] > f[i][j - w[i]] + c[i])
//                    f[i][j] = f[i - 1][j];
//                else
//                    f[i][j] = f[i][j - w[i]] + c[i];
//            }
//
//    }
//    cout << f[num][V];
//    return 0;
//}

//#include<cstdio>
//using namespace std;
//const int maxm = 201, maxn = 31;
//int m, n;
//int w[maxn], c[maxn];
//int f[maxn][maxm];
//int main()
//{
//    scanf("%d%d", &m, &n);            //背包容量m和物品数量n
//    for (int i = 1; i <= n; i++)
//        scanf("%d%d", &w[i], &c[i]);    //每个物品的重量和价值
//    for (int i = 1; i <= n; i++)            //f[i][v]表示前i件物品，总重量不超过v的最优价值
//        for (int v = 1; v <= m; v++)
//            if (v < w[i])
//                f[i][v] = f[i - 1][v];
//            else
//                if (f[i - 1][v] > f[i][v - w[i]] + c[i])
//                    f[i][v] = f[i - 1][v];
//                else
//                    f[i][v] = f[i][v - w[i]] + c[i];
//    printf("max=%d", f[n][m]);         // f[n][m]为最优解
//    return 0;
//}


//
//int n, v, N;
//int c[2005], w[2005];
//int dp[50005];
//int main() {
//	scanf("%d", &N);
//	while (N--) {
//
//		scanf("%d%d", &n, &v);
//		for (int i = 0; i <= 50005; i++) dp[i] = -1000000;
//
//		dp[0] = 0; // 注意这里 
//		for (int i = 0; i < n; i++) {
//			scanf("%d%d", &c[i], &w[i]);
//		}
//
//		for (int i = 0; i < n; i++) {
//			for (int j = c[i]; j <= v; j++) {
//				dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
//			}
//		}
//
//		if (dp[v] < 0)
//			puts("NO");
//		else
//			printf("%d\n", dp[v]);
//	}
//	return 0;
//}

//#include<cstdio>
//#include<cstring>
//const int maxn = 1e4;
//int f[maxn];
//int w[maxn], val[maxn];
//void solve(int n, int m) {
//	memset(f, 0, sizeof f);
//	for (int i = 1; i <= n; i++) {
//		for (int v = m; v > 0; v--) {
//			if (v >= w[i])
//				f[v] = max(f[v], f[v - w[i]] + val[i]);
//		}
//	}
//	printf("%d\n", f[m]);
//}
//int main() {
//	int n, m;
//	while (scanf("%d%d", &n, &m) != EOF) {
//		for (int i = 1; i <= n; i++) scanf("%d%d", w + i, val + i);
//		solve(n, m);
//	}
//	return 0;
//}








//#define R 15
//#define C 20
//int main()
//{
//	int a[R][C] = { 0 };
//	for (int i = 0; i < R; i++)
//		for (int j = 0; j < C; j++)
//			cout << a[i*C + j ]<<" ";
//}
//int main()
//{
//    int a=0, b=0, c=0, d=0, e=0, f=0;
//    while (cin >> a >> b >> c >> d >> e >> f && a + b + c + d + e != 0)
//    {
//        int N = 0;
//        N += e + f;
//        if (a >= 11 * e)
//            a -= 11 * e;
//        N += d;
//        if (b >= 5 * d)
//            b -= 5 * d;
//        else
//        {
//            int x = 0;
//            x = (5 * d - b) * 4;
//            b = 0;
//            if (a > x)
//                a = a - x;
//            else
//                a = 0;
//        }
//        if (c % 4 == 0)
//            N += c / 4;
//        else
//        {
//            int x = 0, y = 0;
//            N = c / 4 + 1 + N;
//            x = 36 - (c % 4) * 9;
//            if (x == 27)
//                y = 5;
//            if (x == 18)
//                y = 3;
//            if (x == 9)
//                y = 1;
//
//            if (b >= y)
//            {
//                b -=y;
//                x -= 4 * y;
//            }
//            else
//            {
//                b = 0;
//                x -= 4 * b;
//            }
//            if (a > x)
//                a -= x;
//            else
//                a = 0;
//        }
//        if (b > 0)
//        {
//            if ((b * 4) % 36)
//            {
//                int x = 0;
//                N += (b * 4) / 36 + 1;
//                x = 36 - (b * 4) % 36;
//                if (a > x)
//                {
//                    a = a - x;
//                }
//                else
//                    a = 0;
//            }
//            else
//                N += (b * 4) / 36;
//        }
//        if (a > 0)
//        {
//            if (a % 36)
//                N += a / 36 + 1;
//            else
//                N += a / 36;
//        }
//        printf("%d\n", N);
//    }
//    return 0;
//}

//int compare(const void* e1, const void* e2)
//{
//	return	*(int*)e1 < *(int*)e2;
//}
//
//int main()
//{
//	int i, j;
//	int m, n, k;
//	while (cin >> m >> n >> k)
//	{
//		int* a1 = new int[m];
//		int* a2 = new int[n];
//		int* a3 = new int[m * n];
//		for (i = 0; i < m; i++)
//			cin >> a1[i];
//		for (i = 0; i < n; i++)
//			cin >> a2[i];
//		for (i = 0; i < m; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				a3[i * m + j] = a1[i] * a2[j];
//			}
//		}
//		qsort(a3, m * n, 4, compare);
//		cout << a3[k - 1] << endl;
//	}
//	return 0;
//}