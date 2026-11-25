

#include <stdlib.h>

int *rankArr;
int n, gap;

int compare(const void *a, const void *b) {
    int i = *(int *)a;
    int j = *(int *)b;

    if (rankArr[i] != rankArr[j])
        return rankArr[i] < rankArr[j] ? -1 : 1;

    int ri = (i + gap < n) ? rankArr[i + gap] : -1;
    int rj = (j + gap < n) ? rankArr[j + gap] : -1;

    if (ri != rj)
        return ri < rj ? -1 : 1;

    return 0;
}

int smallestUniqueSubarray(int* nums, int numsSize) {
    n = numsSize;

    int *sa = malloc(n * sizeof(int));
    int *temp = malloc(n * sizeof(int));
    int *pos = malloc(n * sizeof(int));
    int *lcp = calloc(n, sizeof(int));

    rankArr = malloc(n * sizeof(int));

    // Step 1: Initialize suffix array
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rankArr[i] = nums[i];
    }

    // Step 2: Build suffix array
    for (gap = 1; gap < n; gap *= 2) {

        qsort(sa, n, sizeof(int), compare);

        temp[sa[0]] = 0;

        for (int i = 1; i < n; i++) {
            temp[sa[i]] = temp[sa[i - 1]] +
                (compare(&sa[i - 1], &sa[i]) != 0);
        }

        for (int i = 0; i < n; i++) {
            rankArr[i] = temp[i];
        }

        if (rankArr[sa[n - 1]] == n - 1)
            break;
    }

    // Step 3: Store suffix positions
    for (int i = 0; i < n; i++) {
        pos[sa[i]] = i;
    }

    // Step 4: Calculate LCP
    int h = 0;

    for (int i = 0; i < n; i++) {
        int p = pos[i];

        if (p == 0) {
            h = 0;
            continue;
        }

        int j = sa[p - 1];

        while (i + h < n && j + h < n &&
               nums[i + h] == nums[j + h]) {
            h++;
        }

        lcp[p] = h;

        if (h > 0)
            h--;
    }

    // Step 5: Find minimum unique length
    int ans = n;

    for (int i = 0; i < n; i++) {
        int p = pos[i];

        int mx = lcp[p];

        if (p + 1 < n && lcp[p + 1] > mx) {
            mx = lcp[p + 1];
        }

        int len = mx + 1;

        if (len <= n - i && len < ans) {
            ans = len;
        }
    }

    free(sa);
    free(temp);
    free(pos);
    free(lcp);
    free(rankArr);

    return ans;
}
