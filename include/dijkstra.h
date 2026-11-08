#pragma once

#include <bits/stdc++.h>

using namespace std;

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph
// using adjacency list representation
class Graph {
	int V; // No. of vertices

	// In a weighted graph, we need to store vertex and weight par for every edge
	list<pair<int, int>>* adj;

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);

	// prints shortest path from s
	void shortestPath(int s);
};