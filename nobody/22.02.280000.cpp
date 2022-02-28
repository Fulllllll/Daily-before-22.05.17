#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>

class Solution {
public:
    void replaceSpace(char* str, int length) {
        char* ans = (char*)malloc(100);
        memset(ans, '\0', 100);
        char* p = ans;
        int len = 0;
        for (int i = 0; i < length; i++)
        {
            if (*(str + i) != ' ')
            {
                p[len++] = str[i];
            }
            else
            {
                strcat(p - 1, "%20");
                len += 3;
            }
        }
        strcpy(str, ans);
        free(ans);
        ans = NULL;

        //char* p0 = str;
        //char* p1 = ans;
        //while (*p0 != '\n')
        //{
        //    while (*(p0) != ' ')
        //    {
        //        *p1 = *p0;
        //        p1++;
        //        p0++;
        //    }
        //    p0 += 1;
        //    p1--;
        //    strcat(p1, "%20");
        //    p1 += 4;
        //}
        //strcpy(str, ans);
        //free(ans);
        //ans = NULL;
    }
};

int main()
{
    Solution s;
    char a[] = "add ahah bbb";
    s.replaceSpace(a, 12);
    std::cout << a;
    return 0;
}