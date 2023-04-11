#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>

class Graph {
public:
    Graph() = default;

    void addVertex(int v) {
        if (adjacencyList.find(v) == adjacencyList.end()) {
            adjacencyList[v] = std::vector<int>();
        }
    }

    void addEdge(int v, int w) {
        if (adjacencyList.find(v) == adjacencyList.end()) {
            addVertex(v);
        }
        if (adjacencyList.find(w) == adjacencyList.end()) {
            addVertex(w);
        }

        adjacencyList[v].push_back(w);
        adjacencyList[w].push_back(v);
    }

    void printGraph() {
        for (const auto& vertex : adjacencyList) {
            std::cout << "Vertex " << vertex.first << ":";
            for (const auto& neighbor : vertex.second) {
                std::cout << " " << neighbor;
            }
            std::cout << std::endl;
        }
    }

    std::map<int, std::vector<int>> adjacencyList;
//private:
//    std::map<int, std::vector<int>> adjacencyList;
};

bool iterativeDFS(Graph graph, int startVertex, int wantedVertex) {
  std::set<int> visited;
  std::stack<int> vertexStack;

  vertexStack.push(startVertex);

  while(!vertexStack.empty()) {
    if(startVertex == wantedVertex) {
      return true;
    }
    int currentVertex = vertexStack.top();
    vertexStack.pop();
    if(currentVertex == wantedVertex) {
      return true;
    }
    if(visited.find(currentVertex) == visited.end()) {
      ;
    } else {
      visited.insert(currentVertex);
      for(const auto& adjacent : graph.adjacencyList[currentVertex]) {
        if(visited.find(adjacent) != visited.end()) {
          vertexStack.push(adjacent);
        }
      }
    }
  }
  return false;
}

int main() {
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
