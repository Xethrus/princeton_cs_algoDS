#include <stack>
#include <set>
#include <vector>
#include <tuple>

class Graph {
public:
  Graph() = default;

  void addVertex(int vertex) {
    if(adjacencyList.find(vertex) == adjacencyList.end()) {
      adjacencyList[vertex] = std::vector<int>();
    }
  }

  void addConnection(int first, int second) {
    addVertex(first);
    addVertex(second);
    adjacencyList[first].push_back(second);
    adjacencyList[second].push_back(first);
  }
};

int findDiameterDFS(Graph graph, int startVertex) {
  std::set<int> visited;
  std::stack<std::tuple<int,int>> vertexStack;
  std::vector<std::tuple<int,int>> vertexDistancePaths;

  int diameter = 0;
  vertexStack.push(startVertex, 0);
  while(!vertexStack.empty()) {
    std::tuple<int,int> currentVertex = vertexStack.top();
    vertexStack.pop();
    if(visited.find(currentVertex) != visited.end()) {
      visited.insert(currentVertex);
      if(currentVertex.second > 0) {
        vertexDistancePaths.push_back(currentVertex);
      }
      for(const auto& adjacent : graph.adjacencyList[currentVertex]) {
        if(visited.find(adjacent) != visited.end()) {
          vertexStack.push(adjacent.first, adjacency.second + 1)
        }
      }
    }

  }
  int maxDepth = 0;
  for(const auto& vertex : vertexDistancePaths) {
    if(vertex.second >= maxDepth) {
      maxDepth = vertex.second;
    }
  }
  return maxDepth;
}
