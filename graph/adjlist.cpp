// Stored as array of vector i.e. vector<Edge> arr[]

#include <iostream>
#include <vector>
using namespace std;

class Edge {
    public:
    int src;
    int dest;
    // int weight

    Edge(int src, int dest): src(src), dest(dest) {}

};

int main() {
    const int V = 4;
    vector<Edge> graph[V];
    graph[0].push_back(Edge(0, 1));
    graph[1].push_back(Edge(1, 2));
    graph[1].push_back(Edge(1, 3));
    graph[2].push_back(Edge(2, 0));
    graph[2].push_back(Edge(2, 1));
    graph[2].push_back(Edge(2, 3));
    graph[3].push_back(Edge(3, 1));
    graph[3].push_back(Edge(3, 2));

    for(int i = 0; i < graph[2].size() ; i++) {
        Edge e = graph[2].at(i);
        cout << e.dest << " ";
    }
    cout << endl;
}