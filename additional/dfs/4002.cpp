#include <queue>
#include <vector>
#include <iostream>

using namespace std;

#define RED -1
#define BLUE 1
#define WHITE 0

bool isBipartite(vector<int> *listOfVertices, int *colorOfVertices, int sourceVertex, int quantityOfVertex) {
	bool isBipartite = true;
	colorOfVertices[sourceVertex] = RED;
	queue <int> orderOfBypassing;
	orderOfBypassing.push(sourceVertex);
	while (!orderOfBypassing.empty()) {
		int currentVertex = orderOfBypassing.front();
		orderOfBypassing.pop();
		for (auto adjacentVertex : listOfVertices[currentVertex]) {
			if (colorOfVertices[adjacentVertex] == WHITE) {
				colorOfVertices[adjacentVertex] = -colorOfVertices[currentVertex];
				orderOfBypassing.push(adjacentVertex);
			}
			else if (colorOfVertices[adjacentVertex] == colorOfVertices[currentVertex]) {
				isBipartite = false;
				break;
			}
		}
	}
	return isBipartite;
}

int main() {
	bool answer = true;
	int quantityOfVertex, quantityOfConnections;
	cin >> quantityOfVertex >> quantityOfConnections;
	vector<int> *listOfVertices = new vector<int>[quantityOfVertex];
	while (quantityOfConnections--) {
		int firstVertex, secondVertex;
		cin >> firstVertex >> secondVertex;
		firstVertex--;
		secondVertex--;
		listOfVertices[firstVertex].push_back(secondVertex);
		listOfVertices[secondVertex].push_back(firstVertex);
	}
	int *colorOfVertices = new int[quantityOfVertex];
	for (int indexOfVertex = 0; indexOfVertex < quantityOfVertex; indexOfVertex++) {
		colorOfVertices[indexOfVertex] = WHITE;
	}
	for (int indexOfVertex = 0; indexOfVertex < quantityOfVertex && answer; indexOfVertex++) {
		if (colorOfVertices[indexOfVertex] == WHITE) {
			answer &= isBipartite(listOfVertices, colorOfVertices, indexOfVertex, quantityOfVertex);
		}
	}
	cout << (answer ? "YES" : "NO");
	return 0;
}
