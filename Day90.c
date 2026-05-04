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

int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for(int i = 0; i < n; i++) {
        if(time + arr[i] > maxTime) {
            painters++;
            time = arr[i];
        } else {
            time += arr[i];
        }
    }

    return painters <= k;
}

int main() {
    int n, k;

    printf("Enter number of boards and painters:\n");
    scanf("%d %d", &n, &k);

    int boards[n];

    printf("Enter board lengths:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int low = getMax(boards, n);
    int high = getSum(boards, n);
    int ans = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("Minimum time required = %d\n", ans);

    return 0;
}
