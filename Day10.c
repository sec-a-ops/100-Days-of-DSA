#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int i = 0;
    int j = strlen(s) - 1;
    bool p = true;

    while (i < j) {
        if (s[i] != s[j]) {
            p = false;
            break;
        }
        i++;
        j--;
    }

    if (p)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
