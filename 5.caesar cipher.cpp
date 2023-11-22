#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int b = 0; // For affine Caesar cipher, 'b' can be any integer
    int a;

    printf("Allowed values of 'a': ");

    for (a = 0; a < 26; a++) {
        if (gcd(a, 26) == 1) {
            printf("%d ", a);
        }
    }

    printf("\n");

    return 0;
}