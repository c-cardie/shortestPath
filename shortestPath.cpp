#include <iostream>
#include <vector>
using namespace std;

using graph = vector<vector<int>>;
using visited = vector<bool>;
using path = vector<int>;


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

void findAllPaths(graph& graph, int start, int end, path& path, visited& visited, vector<vector<int>>& allPaths) {

    //Base case: if start equals end, add the end node to the path
    //and store the path in allPaths

    if (start == end) {
        path.push_back(end);
        allPaths.push_back(path);
        path.pop_back();
        return; //end current function call
    }

    //Add the start node to the current path and mark it as visited
    path.push_back(start);
    visited[start] = true;

    //iterate over all the neighbors of the current start node
    for (auto &neighbor : graph[start]) {

        //if the neighbor has not been visited, recursively call findAllPaths
        //with the neighbor as the new "start"
        if (!visited[neighbor]) {

            findAllPaths(graph, neighbor, end, path, visited, allPaths);
        }

    }

    //Unmark the start node as visited and remove it from the current path (unwinding)
    visited[start] = false;
    path.pop_back();

}

void printAllPaths(vector<vector<int>>& allPaths) {

    if (allPaths.empty()) {

    cout << "no paths found" << endl;

    }

    else {
        for (int i = 0; i <= allPaths.size() - 1; i++) {

            cout << "path " << i << ":   ";

            for(int j = 0; j <= allPaths[i].size() - 1; j++) {

            cout << allPaths[i][j] << " ";

            }

            cout << endl;

        }

    }

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
//printGraph(graph);

path path;

vector<bool> visited(graph.size());


//testing to see if visited has the correct number of slots based on the graph
//printVisited(visited);

vector<vector<int>> allPaths;

findAllPaths(graph, 0, 3, path, visited, allPaths);

//print all paths
printAllPaths(allPaths);

}