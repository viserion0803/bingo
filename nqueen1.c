#include <stdio.h>
#include <stdlib.h>

int a[30], count = 0;

int place(int pos) {
    for (int i = 1; i < pos; i++) {
        if (a[i] == a[pos] || abs(a[i] - a[pos]) == abs(i - pos))
            return 0;
    }
    return 1;
}

void print_solution(int n) {
    count++;
    printf("\n\nSolution #%d:\n", count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf(a[i] == j ? "Q\t" : "*\t");
        }
        printf("\n");
    }
}

void solve_queen(int n) {
    int k = 1;
    a[k] = 0;
    while (k != 0) {
        a[k]++;
        while (a[k] <= n && !place(k))
            a[k]++;
        if (a[k] <= n) {
            if (k == n)
                print_solution(n);
            else
                a[++k] = 0;
        } else {
            k--;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d", &n);
    solve_queen(n);
    printf("\nTotal solutions = %d\n", count);
    return 0;
}
