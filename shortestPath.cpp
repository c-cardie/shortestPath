#include <iostream>
#include <vector>
using namespace std;

int main() {

vector<vector<int>> graph = {

    {1,2},
    {3,5},
    {3},
    {},
    {1},
    {3,4}

};

//testing if graph is initialized correctly
for (int i = 0; i <= graph.size() - 1; i++) {

    cout << "node " << i << "   neigbors ";

    if (graph[i].empty()) {
            cout << "none";
    }

    else {

        for (int j = 0; j <= graph[i].size() - 1; j++) {

            cout << " "<< graph[i][j] << " ";

        }

    }

    cout << endl;

}

vector<bool> visited(graph.size());

vector<vector<int>> allPaths;

}