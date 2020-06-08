#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define DELETED -1
#define WHITE 0
#define GREY 1
#define BLACK 2
#define RED 3
#define BLUE 4
#define MAX_INT 2147483647

struct Route {
  int color;
  unsigned int to, length;
  Route(unsigned int to, unsigned int length, int color) {
    this->to = to;
    this->color = color;
    this->length = length;
  }
};

void djikstra(vector<Route>* graph,
              int* distancesInColoredGraph,
              unsigned int quantityOfAllVertices,
              int finishVertex,
              int color) {
  int vertexWithMinDist = -1;
  bool* passed = new bool[quantityOfAllVertices];
  fill(passed, passed + quantityOfAllVertices, false);
  fill(distancesInColoredGraph, distancesInColoredGraph + quantityOfAllVertices,
       MAX_INT);
  distancesInColoredGraph[finishVertex] = 0;
  for (unsigned int indexOfCurrentVertex = 0;
       vertexWithMinDist == -1 ||
       indexOfCurrentVertex < quantityOfAllVertices &&
           distancesInColoredGraph[vertexWithMinDist] != MAX_INT;
       indexOfCurrentVertex++) {
    vertexWithMinDist = -1;
    for (unsigned int indexOfVertex = 0; indexOfVertex < quantityOfAllVertices;
         indexOfVertex++) {
      if (!passed[indexOfVertex] &&
          (vertexWithMinDist == -1 ||
           distancesInColoredGraph[indexOfVertex] <
               distancesInColoredGraph[vertexWithMinDist])) {
        vertexWithMinDist = indexOfVertex;
      }
    }
    passed[vertexWithMinDist] = true;
    for (unsigned int adjacentVertex = 0;
         adjacentVertex < graph[vertexWithMinDist].size(); adjacentVertex++) {
      if (graph[vertexWithMinDist][adjacentVertex].color == color &&
          graph[vertexWithMinDist][adjacentVertex].length +
                  distancesInColoredGraph[vertexWithMinDist] <
              distancesInColoredGraph[graph[vertexWithMinDist][adjacentVertex]
                                          .to]) {
        distancesInColoredGraph[graph[vertexWithMinDist][adjacentVertex].to] =
            graph[vertexWithMinDist][adjacentVertex].length +
            distancesInColoredGraph[vertexWithMinDist];
      }
    }
  }
}

void simplify(vector<Route>* graph,
              int* distance,
              unsigned int quantityOfAllVertices,
              int color) {
  for (unsigned int indexOfCurrentVertex = 0;
       indexOfCurrentVertex < quantityOfAllVertices; indexOfCurrentVertex++) {
    for (unsigned int adjacentVertex = 0;
         adjacentVertex < graph[indexOfCurrentVertex].size();
         adjacentVertex++) {
      if (graph[indexOfCurrentVertex][adjacentVertex].color == color &&
          distance[indexOfCurrentVertex] <=
              distance[graph[indexOfCurrentVertex][adjacentVertex].to]) {
        graph[indexOfCurrentVertex][adjacentVertex].color = DELETED;
      }
    }
  }
}

bool cyclicDFS(vector<Route>* graph,
               int* passedInRedGraph,
               int* passedInBlueGraph,
               int currentVertex,
               int color) {
  bool answer = false;
  if (color == RED)
    passedInRedGraph[currentVertex] = GREY;
  else
    passedInBlueGraph[currentVertex] = GREY;
  for (unsigned int adjacentVertex = 0;
       adjacentVertex < graph[currentVertex].size() && !answer;
       adjacentVertex++) {
    if (graph[currentVertex][adjacentVertex].color == color) {
      if (color == BLUE &&
              passedInRedGraph[graph[currentVertex][adjacentVertex].to] ==
                  GREY ||
          color == RED &&
              passedInBlueGraph[graph[currentVertex][adjacentVertex].to] ==
                  GREY) {
        answer = true;
      }
      if (color == RED &&
          passedInBlueGraph[graph[currentVertex][adjacentVertex].to] == WHITE) {
        if (cyclicDFS(graph, passedInRedGraph, passedInBlueGraph,
                      graph[currentVertex][adjacentVertex].to, BLUE)) {
          answer = true;
        }
      } else if (passedInRedGraph[graph[currentVertex][adjacentVertex].to] ==
                 WHITE) {
        if (cyclicDFS(graph, passedInRedGraph, passedInBlueGraph,
                      graph[currentVertex][adjacentVertex].to, RED)) {
          answer = true;
        }
      }
    }
  }
  if (color == RED)
    passedInRedGraph[currentVertex] = BLACK;
  else
    passedInBlueGraph[currentVertex] = BLACK;
  return answer;
}

bool isCyclic(vector<Route>* graph,
              unsigned int quantityOfAllVertices,
              int currentVertex) {
  int* passedInRedGraph = new int[quantityOfAllVertices];
  int* passedInBlueGraph = new int[quantityOfAllVertices];
  fill(passedInRedGraph, passedInRedGraph + quantityOfAllVertices, WHITE);
  fill(passedInBlueGraph, passedInBlueGraph + quantityOfAllVertices, WHITE);
  return cyclicDFS(graph, passedInRedGraph, passedInBlueGraph, currentVertex,
                   RED);
}

int maxDistDFS(vector<Route>* graph,
               int* maxDistancesInRedGraph,
               int* maxDistancesInBlueGraph,
               int currentVertex,
               int color) {
  if (color == RED && maxDistancesInRedGraph[currentVertex] != -1)
    return maxDistancesInRedGraph[currentVertex];
  if (color == BLUE && maxDistancesInBlueGraph[currentVertex] != -1)
    return maxDistancesInBlueGraph[currentVertex];
  int maxDistance = -1;
  for (unsigned int adjacentVertex = 0;
       adjacentVertex < graph[currentVertex].size(); adjacentVertex++) {
    if (graph[currentVertex][adjacentVertex].color == color) {
      int currentMaxDistance =
          maxDistDFS(graph, maxDistancesInRedGraph, maxDistancesInBlueGraph,
                     graph[currentVertex][adjacentVertex].to,
                     color == RED ? BLUE : RED) +
          graph[currentVertex][adjacentVertex].length;
      maxDistance = max(maxDistance, currentMaxDistance);
    }
  }
  if (color == RED)
    maxDistancesInRedGraph[currentVertex] = maxDistance;
  else
    maxDistancesInBlueGraph[currentVertex] = maxDistance;
  return maxDistance;
}

int getMaxDist(vector<Route>* graph,
               unsigned int quantityOfAllVertices,
               int startVertex,
               int finishVertex) {
  int* maxDistancesInRedGraph = new int[quantityOfAllVertices];
  int* maxDistancesInBlueGraph = new int[quantityOfAllVertices];
  fill(maxDistancesInRedGraph, maxDistancesInRedGraph + quantityOfAllVertices,
       -1);
  fill(maxDistancesInBlueGraph, maxDistancesInBlueGraph + quantityOfAllVertices,
       -1);
  maxDistancesInRedGraph[finishVertex] = 0;
  maxDistancesInBlueGraph[finishVertex] = 0;
  return maxDistDFS(graph, maxDistancesInRedGraph, maxDistancesInBlueGraph,
                    startVertex, RED);
}

int main() {
  ios::sync_with_stdio(false);
  unsigned int quantityOfAllVertices, quantityOfVertices, startVertex,
      finishVertex, from, to, length;
  cin >> quantityOfAllVertices >> startVertex >> finishVertex;
  startVertex--;
  finishVertex--;
  vector<Route>* graph = new vector<Route>[quantityOfAllVertices];
  cin >> quantityOfVertices;
  while (quantityOfVertices--) {
    cin >> from >> to >> length;
    from--;
    to--;
    if (from != to) {
      graph[from].push_back(Route(to, length, RED));
      graph[to].push_back(Route(from, length, RED));
    }
  }
  cin >> quantityOfVertices;
  while (quantityOfVertices--) {
    cin >> from >> to >> length;
    from--;
    to--;
    if (from != to) {
      graph[from].push_back(Route(to, length, BLUE));
      graph[to].push_back(Route(from, length, BLUE));
    }
  }
  int* distancesInRedGraph = new int[quantityOfAllVertices];
  int* distancesInBlueGraph = new int[quantityOfAllVertices];
  djikstra(graph, distancesInRedGraph, quantityOfAllVertices, finishVertex,
           RED);
  djikstra(graph, distancesInBlueGraph, quantityOfAllVertices, finishVertex,
           BLUE);
  simplify(graph, distancesInRedGraph, quantityOfAllVertices, RED);
  simplify(graph, distancesInBlueGraph, quantityOfAllVertices, BLUE);
  cout << (isCyclic(graph, quantityOfAllVertices, startVertex)
               ? -1
               : getMaxDist(graph, quantityOfAllVertices, startVertex,
                            finishVertex))
       << endl;
  return 0;
}