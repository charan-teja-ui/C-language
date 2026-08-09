#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int start[n], end[n];
    long long total = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &end[i]);
        total += llabs((long long)end[i] - start[i]);
    }

    printf("The intervals are:\n");

    for (int i = 0; i < n; i++) {
        printf("[%d, %d]\n", start[i], end[i]);
    }

    printf("Total interval sum = %lld\n", total);

    printf("Sum after removing each interval:\n");

    for (int i = 0; i < n; i++) {
        long long length = llabs((long long)end[i] - start[i]);
        long long remaining = total - length;

        printf("Remove [%d, %d] -> %lld\n",
               start[i], end[i], remaining);
    }

    return 0;
}
