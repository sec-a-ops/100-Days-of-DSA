#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int getSum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for(int i = 0; i < n; i++) {
        if(pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];
        } else {
            pages += arr[i];
        }
    }

    return students <= m;
}

int main() {
    int n, m;

    printf("Enter number of books and students:\n");
    scanf("%d %d", &n, &m);

    int arr[n];

    printf("Enter pages in books:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if(m > n) {
        printf("Not possible\n");
        return 0;
    }

    int low = getMax(arr, n);
    int high = getSum(arr, n);
    int ans = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(canAllocate(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("Minimum maximum pages = %d\n", ans);

    return 0;
}
