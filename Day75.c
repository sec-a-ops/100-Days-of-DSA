#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[MAX];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    int hash[2001];
    for (int i = 0; i < 2001; i++) hash[i] = -2;

    hash[1000] = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int index = prefixSum + 1000;

        if (hash[index] != -2) {
            int len = i - hash[index];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[index] = i;
        }
    }

    printf("Longest subarray length with sum 0: %d\n", maxLen);

    return 0;
}
