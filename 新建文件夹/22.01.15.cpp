#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstdio>
//#include<string.h>
//using namespace std;
//const int MAXN = 100000 + 5;
//int N, F;
//double num[MAXN];
//double sum[MAXN];
//double rmaxsum[MAXN];
//double l = 9999999, r;
//inline bool qualify(double tans) {
//    for (int i = N; i >= 1; i--)
//        rmaxsum[i] = max(num[i] - tans, rmaxsum[i + 1] + num[i] - tans);
//    for (int i = 1; i <= N - F + 1; i++) {
//        //  cout<<sum[i+F-1]-sum[i-1]<<" "<<F*tans<<" "<<tans<<endl;
//        if (sum[i + F - 1] - sum[i - 1] >= F * tans)
//            return true;
//        //  cout<<"sec:"<<sum[i+F-1]-sum[i-1]-F*tans+rmaxsum[i+F]<<endl;
//        if (sum[i + F - 1] - sum[i - 1] - F * tans + rmaxsum[i + F] >= 0)
//            return true;
//    }
//    return false;
//}
//int main() {
//    cin >> N >> F;
//    for (int i = 1; i <= N; i++) {
//        scanf("%lf", &num[i]);
//        sum[i] = sum[i - 1] + num[i];
//        r = max(r, num[i]);
//        l = min(l, num[i]);
//    }
//    while (l < r - 0.0001) {
//        double mid = (r + l) / 2;
//        if (qualify(mid))
//            l = mid;
//        else
//            r = mid;
//    }
//    cout << int(r * 1000) << endl;
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int MAXN = 1e5 + 5;
//int N, F;
//double num[MAXN], sum[MAXN], rmaxsum[MAXN];
//double l = 9999999, r;
//bool qualify(double tans) {
//    for (int i = N; i >= 1; i--)
//        rmaxsum[i] = max(num[i] - tans, rmaxsum[i + 1] + num[i] - tans);
//    for (int i = 1; i <= N - F + 1; i++) {
//        if (sum[i + F - 1] - sum[i - 1] >= F * tans)
//            return true;
//        if (sum[i + F - 1] - sum[i - 1] - F * tans + rmaxsum[i + F] >= 0)
//            return true;
//    }
//    return false;
//}
//int main() {
//    cin >> N >> F;
//    for (int i = 1; i <= N; i++) {
//        scanf("%lf", &num[i]);
//        sum[i] = sum[i - 1] + num[i];
//        r = max(r, num[i]);
//        l = min(l, num[i]);
//    }
//    while (l < r - 0.0001) {
//        double mid = (r + l) / 2;
//        if (qualify(mid))
//            l = mid;
//        else
//            r = mid;
//    }
//    cout << int(r * 1000) << endl;
//    return 0;
//}


//#include<cstdio>
//using namespace std;
//int n, f;
//double a[100001], l, r, qzh[100001], b[100001], an, ans;
//int main()
//{
//    scanf("%d%d", &n, &f);
//    for (int i = 1; i <= n; i++)
//        scanf("%lf", &a[i]);
//
//    l = -1e6; r = 1e6;
//    while (r - l > 1e-5)
//    {
//        double mid = (l + r) / 2;
//        for (int i = 1; i <= n; i++)
//            b[i] = a[i] - mid;
//        for (int i = 1; i <= n; i++)
//            qzh[i] = qzh[i - 1] + b[i];
//        ans = -1e10; an = 1e10;
//        for (int i = f; i <= n; i++)
//        {
//            an = an > qzh[i - f] ? an : qzh[i - f];
//            ans = ans > qzh[i] - an ? ans : qzh[i] - an;
//        }
//        if (ans >= 0) l = mid;
//        else r = mid;
//    }
//    printf("%d", int(r * 1000));
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int arr[5005][5005];

//int main()
//{
//    int n = 0, R = 0;
//    int ans = 0;
//    cin >> n >> R;
//    //for (int i = 0; i < n; ++i) {             //错误 ：在读入arr[x+1][y+1]时，
//    //    int x = 0, y = 0;                     //实际上前半句输入的x y值未知的，
//    //    cin >> x >> y >> arr[x+1][y+1];       //此时，是在给arr[1][1]赋值                                       
//    //}                                         //解决办法是在避免在同一句中这样赋值                                         
//    for (int i = 0; i < n; ++i) {
//        int x = 0, y = 0, z = 0;
//        cin >> x >> y >> z;
//        arr[x + 1][y + 1] = z;
//    }
//
//    for (int i = 1; i <= 5000; ++i)
//        for (int j = 1; j <= 5000; ++j)
//            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] + arr[i][j] - arr[i - 1][j - 1];
//
//    for (int i = 0; i <= 5000-R; ++i)
//        for (int j = 0; j <= 5000-R; ++j)
//            ans = max(ans, arr[i+R][j+R] - arr[i][j+R] - arr[i+R][j] + arr[i][j]);
//    cout <<ans<<endl;
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int arr[10] = {1,2,5,6,4,8,7,9};
//	int a = 0;
//	cin >> a >> arr[a];
//	cout << arr[0]<<"  " << arr[a];
//
//	return 0;
//}

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10; 
long long a[N],s[N];

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		s[i] = a[i] - a[i - 1];

	long long p = 0, q = 0;	
	for (int i = 2; i <= n; i++)
	{
		if (s[i] > 0) p += s[i];
		else q += (-s[i]);
	}

	long long ans1 = max(p, q);
	long long ans2 = abs(p - q) + 1;
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%ld", &a[i]);
	long long p = 0, q = 0;	
	for (int i = 2; i <= n; i++)
	{
		s[i] = a[i] - a[i - 1];
		if (s[i] > 0) p+=s[i];
		else q+= (-s[i]);
	}
	printf("%ld\n%d\n", max(p, q), abs(p - q) + 1);
	return 0;
}