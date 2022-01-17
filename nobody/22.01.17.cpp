//#include<bits/stdc++.h>
//using namespace std;
//int m, m3;
//int main()
//{
//	while (cin >> m)
//	{
//		m3 = m * m * m;
//		if (m % 2)
//		{
//			int i = 0;
//			for (i = 0; i < m - 1; i++)
//			{
//				cout << m * m - (m / 2 - i) * 2 << "+";
//			}
//			cout << m * m + (m / 2) * 2 << endl;
//		}
//		else
//		{
//			int i = 0;
//			for (i = 0; i < m - 1; i++)
//			{
//				cout << m * m - 1 - (m / 2 - i - 1) * 2 << "+";
//			}
//			cout << m * m - 1 + (m / 2) * 2 << endl;
//		}
//	}
//	return 0;
//}

//int main()
//{
//    int a = 2;
//    int n = 0;
//    while (cin >> n)
//    {
//        int sum = a;
//        for (int i = 0; i < n - 1; i++)
//        {
//            a += 3;
//            sum += a;
//        }
//        cout << sum << endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//
//int a[2005];
//int n, num1, num2, sum;
//
//int main()
//{
//    while (cin >> n)
//    {
//        num1 = num2 = sum = 0;
//        for (int i = 0; i < n; i++)
//        {
//            cin >> a[i];
//            if (a[i] < 0) num1++;
//            if (a[i] > 0) { num2++; sum += a[i]; }
//        }
//        printf("%d %.1f\n", num1, (float)sum / num2);
//    }
//    return 0;
//}



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n < 0) return -1;
        while (n > 0 && nums[n] == nums[0]) n--;
        if (nums[n] >= nums[0]) return nums[0];
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;       // [l, mid], [mid + 1, r]
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};



//int main()
//{
//    int a[7] = { 6, 7, 1, 2, 3, 4, 5};
//    Solution A;
//    cout << A.findMin()
//
//} 