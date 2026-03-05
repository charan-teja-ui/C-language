#include <stdio.h>

int main()
{
    int i, j, k,n;
    printf("enter the value of n:");
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
     
        for(j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for(j = 0; j < i; j++)
        {
            printf("%d", n - j);
        }
        for(k = i - 2; k >= 0; k--)
        {
            printf("%d", n - k);
        }

        printf("\n");
    }
    for(i = n-1; i >= 1; i--)
    {
        for(j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for(j = 0; j < i; j++)
        {
            printf("%d", n - j);
        }

        for(k = i - 2; k >= 0; k--)
        {
            printf("%d", n - k);
        }

        printf("\n");
    }

    return 0;
}