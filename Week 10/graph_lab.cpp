#include <iostream>
#include<list>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    int label;
    //2. a int type list called neighbours
    list<int> neighbours;
};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=8;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label=i+1;
        }
    }

    Node& findNode(int label){
        for(int i=0 ; i < n ; i++){
            if(this->nodes[i].label == label){
                return this->nodes[i];
            }
        }
        throw invalid_argument(to_string(label) + " is not a label of a vertex");
    }


    void addedge(int u, int v){
        //select node u and push v into u's neighbour
        findNode(u).neighbours.push_back(v);
        //select node v and push u into v's neighbour
        findNode(v).neighbours.push_back(u);
    }

    void print(){
        //lets iterate through each node and print its neighbours
        for(int i=0 ; i < n ; i++){
            cout << this->nodes[i].label << " --> ";
            for(int j : this->nodes[i].neighbours){
                cout << j << " ";
            } 
            cout << "\n";
        }

    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    g->addedge(1,2);
    g->addedge(1,3);
    g->addedge(1,4);
    g->addedge(1,5);

    g->addedge(2,3);
    g->addedge(2,6);
    
    g->addedge(4,6);
    g->addedge(4,7);
    g->addedge(4,8);

    g->addedge(5,6);
    g->addedge(5,7);
    g->addedge(5,8);
    

    //print the graph adjaceny list
    g->print();
}
