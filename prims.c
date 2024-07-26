#include <stdio.h> 
#include <stdbool.h> 
#include <limits.h> 
#define MAX_VERTICES 100 
int graph[MAX_VERTICES][MAX_VERTICES]; 
int numVertices; 
int findMinimumKey(int key[], bool mstSet[])  
{ 
     int minKey = INT_MAX; 
    int minIndex, v; 
     for (v = 0; v < numVertices; v++) 
{ 
          if (mstSet[v] == false && key[v] < minKey)  
{ 
               minKey = key[v]; 
              minIndex = v; 
          } 
     } 
 

 
     return minIndex; 
} 
void printMST(int parent[])  
{ 
   int i; 
     printf("Edge \tWeight\n"); 
     for (i = 1; i < numVertices; i++)  
{ 
          printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]); 
     } 
} 
void primMST()  
{ 
     int parent[MAX_VERTICES]; 
     int key[MAX_VERTICES]; 
     bool mstSet[MAX_VERTICES]; 
     int i, count, u, v; 
     for (i = 0; i < numVertices; i++)  
{ 
          key[i] = INT_MAX; 
         mstSet[i] = false; 
     } 
    key[0] = 0; 
     parent[0] = -1; 
for (count = 0; count < numVertices - 1; count++)  
{ 
          u = findMinimumKey(key, mstSet); 
          mstSet[u] = true; 
         for (v = 0; v < numVertices; v++)  
{ 
               if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
{ 
                   parent[v] = u; 

 
                  key[v] = graph[u][v]; 
               } 
          } 
     } 
     printMST(parent); 
} 
int main()  
{ 
     int i, j; 
     printf("Enter the number of vertices: "); 
     scanf("%d", &numVertices); 
printf("Enter the adjacency matrix:\n"); 
     for (i = 0; i < numVertices; i++)  
{ 
          for (j = 0; j < numVertices; j++)  
{ 
               scanf("%d", &graph[i][j]); 
          } 
     } 
     printf("Minimum Spanning Tree:\n"); 
     primMST(); 
return 0; 
}