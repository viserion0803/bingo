#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int i, n, a[100];
    clock_t start, end;
    printf("Enter the number of elements\n");
    scanf("%d", &n);

    srand(time(0)); // Seed the random number generator
    for (i = 0; i < n; i++) {
        a[i] = rand();
        printf("%d\t", a[i]);
    }

    start = clock();
    mergesort(a, 0, n - 1);
    end = clock();

    printf("\nSorted array elements are\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    double tc = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken is %f seconds\n", tc);

    return 0;
}
