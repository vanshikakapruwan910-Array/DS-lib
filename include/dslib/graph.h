#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Abstract Base Class
class GraphOperations
{
public:
    virtual void createGraph() = 0;
    virtual void addVertex(int v) = 0;
    virtual void addEdge(int u, int v) = 0;
    virtual void deleteVertex(int v) = 0;
    virtual void deleteEdge(int u, int v) = 0;
    virtual void displayGraph() const = 0;
    virtual void searchVertex(int v) const = 0;
    virtual void findDegree(int v) const = 0;
    virtual void BFS(int start) const = 0;
    virtual void DFS(int start) const = 0;
    virtual void checkConnectivity() const = 0;
    virtual void findPath(int start, int end) const = 0;
    virtual ~GraphOperations() {}
};

// Derived Class
class UndirectedGraph : public GraphOperations
{
private:
    // Encapsulation
    vector<int> vertices;
    vector<vector<int>> adj;
    // Private helper functions
    int findIndex(int v) const;
    bool edgeExists(int u, int v) const;
    void DFSHelper(int index, vector<bool>& visited) const;

public:
    UndirectedGraph();
    // Graph operations
    void createGraph() override;
    void addVertex(int v) override;
    void addEdge(int u, int v) override;
    void deleteVertex(int v) override;
    void deleteEdge(int u, int v) override;
    void displayGraph() const override;
    void searchVertex(int v) const override;
    void findDegree(int v) const override;
    void BFS(int start) const override;
    void DFS(int start) const override;
    void checkConnectivity() const override;
    void findPath(int start, int end) const override;
};
#endif
