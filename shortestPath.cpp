#include <iostream>
#include <vector>
#include <limits>
using namespace std;

using Graph = vector<vector<int>>;
using Visited = vector<bool>;
using Path = vector<int>;


//function to test if graph is initialized correctly
void printGraph(Graph& graph) {

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

//function to find all paths in a graph
void findAllPaths(Graph& graph, int start, int end, Path& path, Visited& visited, vector<vector<int>>& allPaths) {

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

//function to find the smallest path
void findSmallestPath(vector<vector<int>>& allPaths) {

    //smallestPaths holds the path's size (int)
    //and the path (vector<int>)
    vector<pair<int, vector<int>>> smallestPaths;

    //initialize the smallest path length with maximum possible value
    int smallestPathLength = numeric_limits<int>::max();

    //iterate through allPaths to find the smallest path(s)
    for (int i = 0; i <= allPaths.size() - 1; i++) {

        //current path length is size of the ith element of allPaths
        //allPath's elements are vectors
        int CurPathLength = allPaths[i].size() - 1;

        if (CurPathLength < smallestPathLength) {

            //Found a smaller path, clear previous paths and update smallest length
            smallestPathLength = CurPathLength;
            smallestPaths.clear();
            smallestPaths.push_back({smallestPathLength, allPaths[i]});

        }
        else if (CurPathLength == smallestPathLength) {
            //found another path of the same smallest length
            smallestPaths.push_back({smallestPathLength, allPaths[i]});

        }

    }

    //print smallest path and length
    if (smallestPaths.empty()) {

       cout << "no paths found" << endl;

    } else {

         for (int i = 0; i <= smallestPaths.size() - 1; i++) {

            cout << "length: " << smallestPaths[i].first << "   path: ";

            for (int j = 0; j <= (smallestPaths[i].second.size()) - 1; j++) {

                    cout << smallestPaths[i].second[j] << " ";

            }

            cout << endl;

        }

    }
   
}

int main() {

//test case 1
cout << "test case 1" << endl;
cout << endl;

Graph graph = {

   /*0*/ {1,2},
   /*1*/ {3,5},
   /*2*/ {3},
   /*3*/ {},
   /*4*/ {1},
   /*5*/ {3,4}

};

//printing first graph
cout << "graph 1" << endl;
printGraph(graph);
cout << endl;

Path path;
vector<bool> visited(graph.size());
vector<vector<int>> allPaths;

//printing all paths from 0 to 3 in graph 1
findAllPaths(graph, 0, 3, path, visited, allPaths);
cout << "all paths from 0 to 3 in graph 1" << endl;
printAllPaths(allPaths);
cout << endl;

//finding (and printing) the smallest path from 0 to 3 in graph 1
cout << "shortest path from 0 to 3 in graph 1" << endl;
findSmallestPath(allPaths);
cout << endl;

cout << "-----------------------------------" << endl;

//test case 2

cout << "test case 2" << endl;
cout << endl;

Graph graph2 = {

/*0*/ {1,2,3},
/*1*/ {},
/*2*/ {3},
/*3*/ {1,5},
/*4*/ {5},
/*5*/ {}

};

cout << "graph 2" << endl;
printGraph(graph2);
cout << endl;

Path path2;
Visited visited2(graph2.size());
vector<vector<int>> allPaths2;

//printing all paths from 0 to 5 in graph 2
findAllPaths(graph2, 0, 5, path2, visited2, allPaths2);
cout << "all paths from 0 to 5 in graph 2" << endl;
printAllPaths(allPaths2);
cout << endl;

//finding (and printing) the smallest path from 0 to 5 in graph 2
cout << "shortest path from 0 to 5 in graph 2" << endl;
findSmallestPath(allPaths2);
cout << endl;

cout << "-----------------------------------" << endl;

}