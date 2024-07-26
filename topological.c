#include <stdio.h> 
#include <stdbool.h> 
#define MAX_NODES 100 
typedef struct Node  
{ 
int id; 
int dependencies[MAX_NODES]; 
int numDependencies; 
bool visited; 
} Node; 
Node nodes[MAX_NODES]; 
int numNodes; 
void initializeNodes()  
{ 
int i; 
for (i = 0; i < MAX_NODES; i++)  
{
nodes[i].id = i; 
nodes[i].numDependencies = 0; 
nodes[i].visited = false; 
} 
numNodes = 0; 
} 
void addDependency(int from, int to) 
{ 
nodes[to].dependencies[nodes[to].numDependencies] = from; nodes[to].numDependencies++; 
} 


void topologicalSort()  
{ 
int i, j; 
int numVisited = 0; 
bool noDependencies; 
while (numVisited < numNodes)  
{ 
noDependencies = true; 
for (i = 0; i < numNodes; i++)  
{ 
if (!nodes[i].visited)  
{ 
for (j = 0; j < nodes[i].numDependencies; j++)  
{ 
if (!nodes[nodes[i].dependencies[j]].visited) 
{ 
noDependencies = false; 
break; 
} 
}
if (noDependencies)  
{ 
printf("%d ", nodes[i].id); 
nodes[i].visited = true; 
numVisited++; 
break; 
} 
} 
} 
} 
} 


int main()  
{ 
initializeNodes(); 
addDependency(1, 3); 
addDependency(2, 3); 
addDependency(3, 4); 
addDependency(3, 5); 
addDependency(4, 6); 
addDependency(5, 6); 
numNodes = 7;  
printf("Topological Order: "); 
topologicalSort(); 
return 0; 
} 
