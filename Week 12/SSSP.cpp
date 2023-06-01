/**
 * @file SSSP.cpp
 * @author D. G. H. Prabashwara.
 * @brief This programme implement the dijkstra's algorithem
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <limits.h>

// This is to store the amount of cities
#define CITIES 6 

using namespace std;

/**
 * @brief This fuction returns the adjacent index that has the minimum weight(time).
 * 
 * @param time 
 * @param traversed
 * @return int 
 */
int minimumTime(int time[], bool traversed[]){
    int min = INT_MAX; 
    int min_index;
  
    for (int v = 0; v < CITIES; v++){
        if (traversed[v] == false && time[v] <= min)
            min = time[v],min_index = v;
        }
    return min_index;    
}

/**
 * @brief This function print the shortest time for a given graph and a given source
 * 
 * @param time 
 * @param src 
 */
void printShortestTime(int time[], int src){
    for (int i = 0; i < CITIES; i++){
        if(i == src){
            continue;
        }
        cout << "The shortest time takes to travel between "<< src << " to " << i << " is " << time[i] << "h" << endl;
    }
}


/**
 * @brief This function implements the Dijkstra's algorithem.
 * 
 * @param graph 
 * @param src 
 */
void dijkstraSSSP(int graph[CITIES][CITIES], int src){
    // Create a list to store cities (vertices)
    int time[CITIES];
    // A list to find traversed cities
    bool traversed[CITIES];

    // Make all values in time infinity, and make all values in traversed false
    for (int i = 0; i < CITIES; i++){
        time[i] = INT_MAX, traversed[i] = false;
    }
    
    // Since source does not take time to travel to itself make its time 0 
    time[src] = 0;
    

    for (int count = 0; count < CITIES - 1; count++) {
        // Find the neighbour corresponding to the minimum weighted edge 
        int u =  minimumTime(time, traversed);
        // Since we traversed that node make the node u traversed = true
        traversed[u] = true;

        
        for (int v = 0; v < CITIES; v++)
            if (!traversed[v] && graph[u][v] && time[u] != INT_MAX && time[u] + graph[u][v] < time[v])
                time[v] = time[u] + graph[u][v];
            }
        printShortestTime(time, src);
}
    


int main(){
    int cityGraph[CITIES][CITIES] = { {0,10,0,0,15,5},
                                    {10,0,10,30,0,0},
                                    {0,10,0,12,5,0},
                                    {0,30,12,0,0,20},
                                    {15,0,5,0,0,0},
                                    {5,0,0,20,0,0}};
    
    dijkstraSSSP(cityGraph, 5);


    return 0;
}   
  
