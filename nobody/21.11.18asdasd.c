#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
int main()
{
    char x;
    char ch[10] = { 'a','e','i','o','u','A','E','I','O','U' };
    while ((x = getchar())!= EOF)
    {
        int i = 0;
        for (i = 0; i < 10; i++)
        {
            if (x == ch[i]) break;
        }
        if (i >= 10) printf("Consonant\n");
        else printf("Vowel\n");
        getchar();
    }
    return 0;
}

//#include<stdio.h>
//int i;
//int main()
//{
//    i--;
//    unsigned int x = sizeof(i);
//    if ((unsigned)i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}