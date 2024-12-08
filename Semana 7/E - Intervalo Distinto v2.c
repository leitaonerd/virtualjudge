#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head = 0, atualcont = 0, maxcont = 0;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int hashmap[100000] = {0}; // To track occurrences of numbers.

    for (int i = 0; i < n; i++) {
        hashmap[array[i]]++;

        // If the current number is already in the window, shrink the window
        while (hashmap[array[i]] > 1) {
            hashmap[array[head]]--;
            head++;
        }

        // Update the length of the current unique window
        atualcont = i - head + 1;
        if (atualcont > maxcont) {
            maxcont = atualcont;
        }
    }

    printf("%d\n", maxcont);

    return 0;
}
