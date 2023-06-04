/**
 * @file Prim_MST.cpp
 * @author D.G.H.Prabashwara.
 * @brief Takes and adjacaency matrix and find the MST by Prim's Algorithm
 * @version 0.1
 * @date 2023-06-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <limits>

// The amount of streets(vertices)
#define STREETS 6 


/**
 * @brief Returns the index of the neighbour vertex of the tree with the minimum weight edge
 * 
 * @param key 
 * @param mstSet 
 * @return int 
 */
int minimumCost(int key[], bool mstSet[])
{
    int minCost = INT_MAX, min_index;

    for (int v = 0; v < STREETS; ++v)
        if (!mstSet[v] && key[v] < minCost)
            minCost = key[v], min_index = v;

    return min_index;
}


/**
 * @brief Print the MST
 * 
 * @param parent 
 * @param graph 
 */
void printMST(int parent[], int graph[STREETS][STREETS])
{
    std::cout << "Edge : Weight\n";
    for (int i = 1; i < STREETS; ++i)
        std::cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
}

/**
 * @brief deploy the prims algorithm to find the MST
 * 
 * @param graph 
 */
void prims(int graph[STREETS][STREETS])
{
    int parent[STREETS];
    int key[STREETS];
    bool mstSet[STREETS];

    for (int i = 0; i < STREETS; ++i)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < STREETS - 1; ++count) {
        int u = minimumCost(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < STREETS; ++v)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main(){
    // Initialize a adjacency matrix
    int graph[STREETS][STREETS] = {{ 0,	3,	0,	0,	0,	1},
                                    {3,	0,	2,	5,	10,	0},
                                    {0,	2,	0,	12,	5,	0},
                                    {0,	5,	12,	0,	5,	0},
                                    {0,	10,	5,	5,	0,	4},
                                    {1,	0,	0,	0,	4,	0}};

    // Call the prims function.
    prims(graph);

    return 0;
}
