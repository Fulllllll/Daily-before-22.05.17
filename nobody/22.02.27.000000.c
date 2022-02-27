#include<stdio.h>
#define ADD(m, n) {m++; n++;}
int main()
{
    int m = 1, n = 1;
    if (1)
    {
        m--; n--;
    }
    else ADD(m, n);
    printf("%d %d\n", m, n);
    return 0;
}