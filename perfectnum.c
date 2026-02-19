#include <stdio.h>
#include <math.h>

int main() {
    int i, num;
    long long perfectnum;
    int isPrime = 1;
    scanf("%d", &num);
    if (num <= 1) {
        printf("Not a prime number");
        return 0;
    }
    for (i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            isPrime = 0;
            break;
        }
    }
    if (isPrime) {
        printf("%d is a prime number\n", num);
        perfectnum = (long long)pow(2, num - 1) * (pow(2, num) - 1);
        printf("Perfect number formed = %lld\n", perfectnum);
        int sum = 0;
        for (i = 1; i <= perfectnum; i++) {
            if (perfectnum % i == 0)
                sum += i;
        }
        sum=sum/2;
        if (sum == perfectnum)
            printf("%lld is a perfect number", perfectnum);
        else
            printf("%lld is not a perfect number", perfectnum);
    }
    else {
        printf("%d is not a prime number", num);
    }

    return 0;
}
