#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int n = 0;
    int i = 0;

    while (1) {
        if (scanf("%d", &n) != 1) {
            printf("n/a");
            free(arr);
            return 0;
        }
        if (n == -1) break;
        int *temp = realloc(arr, (i + 1) * sizeof(int));
        if (temp == NULL) {
            printf("Failed to reallocate memory!");
            free(arr);
            return 0;
        }
        arr = temp;
        arr[i] = n;
        i++;
    }

    for (int s = 0; s < i - 1; s++) {
        for (int t = 0; t < i - s - 1; t++) {
            if (arr[t] > arr[t + 1]) {
                int temp;
                temp = arr[t];
                arr[t] = arr[t + 1];
                arr[t + 1] = temp;
            }
        }
    }

    for (int k = 0; k < i; k++) {
        printf("%d ", arr[k]);
    }

    free(arr);
    return 0;
}