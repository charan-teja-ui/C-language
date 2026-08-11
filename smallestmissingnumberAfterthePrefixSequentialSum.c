#include <stdio.h>

int main()
{
    int nums[50], i, n;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int total = nums[0];

    for (i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1] + 1)
        {
            total += nums[i];
        }
        else
        {
            break;
        }
    }

    while (1)
    {
        int found = 0;

        for (i = 0; i < n; i++)
        {
            if (nums[i] == total)
            {
                found = 1;
                break;
            }
        }

        if (found)
            total++;
        else
            break;
    }

    printf("%d", total);

    return 0;
}
