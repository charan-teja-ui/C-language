#include <stdio.h>
#include <stdbool.h>

bool canWinNim(int n) {
    return (n % 4 != 0);
}

int main() {
    int n;
    printf("Enter the number of stones: ");
    scanf("%d", &n);

    if (canWinNim(n))
        printf("You can win!\n");
    else
        printf("You will lose.\n");

    return 0;
}
