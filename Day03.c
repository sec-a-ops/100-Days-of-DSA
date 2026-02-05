#include <stdio.h>

int main() {
    int n, k, i, found = 0, comparisons = 0;

    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            found = 1;
            break;
        }
    }

    if(found)
        printf("Key found at index %d\n", i);
    else
        printf("Key not found\n");

    printf("Comparisons: %d\n", comparisons);

    return 0;
}
