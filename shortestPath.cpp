#include <iostream>
#include <vector>
using namespace std;

using graph = vector<vector<int>>;


//function to test if graph is initialized correctly
void printGraph(graph& graph) {

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

}

//function to test if visited has the correct number of slots based on the graph
void printVisited(vector<bool>& visited) {

    for (int i = 0; i <= visited.size() - 1; i++ ) {

        cout << visited[i] << endl;

    }

}

void findAllPaths() {

    //Add the start node to the current path and mark it as visited
    //path.push_back()


}

int main() {

graph graph = {

    {1,2},
    {3,5},
    {3},
    {},
    {1},
    {3,4}

};

//testing if graph is initialized correctly
printGraph(graph);

vector<bool> visited(graph.size());


//testing to see if visited has the correct number of slots based on the graph
printVisited(visited);

vector<vector<int>> allPaths;

}