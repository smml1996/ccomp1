#include <vector>
#include <map>
using namespace std;

class Graph{
    map<int, vector<int> >nodes;

public:
    Graph(const vector<int> starts, const vector<int> ends);
    int numOutGoing(const int nodeID) const;
    const vector<int> &adjacent(const int nodeID);
};
