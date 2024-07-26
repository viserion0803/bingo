#include <stdio.h> 
#include <string.h> 
#define MAX_LENGTH 100 
// Function to find the LCS 
void findLCS(char *X, char *Y) { 
 int m = strlen(X);
 int n = strlen(Y); 
 int dp[MAX_LENGTH + 1][MAX_LENGTH + 1];  // Build the dp array 
 for (int i = 0; i <= m; i++) { 
 for (int j = 0; j <= n; j++) { 
 if (i == 0 || j == 0) { 
 dp[i][j] = 0; 
 } else if (X[i - 1] == Y[j - 1]) { 
 dp[i][j] = dp[i - 1][j - 1] + 1; 
 } else { 
 dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];  } 
 } 
 } 
 // Backtrack to find the LCS 
 int index = dp[m][n]; 
 char lcs[index + 1]; 
 lcs[index] = '\0'; // Null-terminate the string 
 int i = m, j = n; 
 while (i > 0 && j > 0) { 
 if (X[i - 1] == Y[j - 1]) { 
 lcs[index - 1] = X[i - 1]; 
 i--; 
 j--; 
 index--; 
 } else if (dp[i - 1][j] > dp[i][j - 1]) { 
 i--; 
 } else {
 j--; 
 } 
 } 
 // Print the LCS 
 printf("Longest Common Subsequence: %s\n", lcs); 
} 
int main() { 
 char X[MAX_LENGTH], Y[MAX_LENGTH]; 
 printf("Enter the first sequence: "); 
 scanf("%s", X); 
 printf("Enter the second sequence: "); 
 scanf("%s", Y); 
 findLCS(X, Y); 
 return 0; 
} 
