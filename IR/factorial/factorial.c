#include <stdio.h>

int main() {
    int value=1,n,i;
    printf("Enter N For Mul...\n");
    scanf("%d", &n);
    for (i=1;i<=n;i++) {
        value*=i;
    }
    printf("Value: %d\n", value);
}
