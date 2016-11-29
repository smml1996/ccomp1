#include "graph.h"
#include <stdexcept>

using namespace std;

Graph::Graph(const vector<int> starts, const vector<int> ends){
    if(starts.size()!=ends.size()){throw invalid_argument("los vectores son de diferente tamanio");
    }
    for(int i = 0; i<starts.size();i++){
        nodes[starts[i]].push_back(ends[i]);
    }
}
int Graph::numOutGoing(const int nodeID)const{
    return (nodes.find(nodeID))->second.size();
}
const vector<int> &Graph::adjacent(const int nodeID){
    return (nodes.find(nodeID))->second;
}


