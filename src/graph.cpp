#include<iostream>
#include "graph.h"
using namespace std;

UndirectedGraph::UndirectedGraph()
{
    vertices.clear();
    adj.clear();
}

int UndirectedGraph::findIndex(int v) const
{
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] == v)
            return i;
    }
    return -1;
}

bool UndirectedGraph::edgeExists(int u, int v) const
{
    int i = findIndex(u);

    if (i == -1)
        return false;

    return find(adj[i].begin(), adj[i].end(), v) != adj[i].end();
}

void UndirectedGraph::DFSHelper(int index, vector<bool>& visited) const
{
    if (index == -1 || visited[index])
        return;

    visited[index] = true;
    cout << vertices[index] << " ";

    for (int x : adj[index])
    {
        int i = findIndex(x);

        if (i != -1 && !visited[i])
            DFSHelper(i, visited);
    }
}

void UndirectedGraph::createGraph()
{
    vertices.clear();
    adj.clear();

    int n, m, v, u;
    cout << "Enter number of vertices: ";
    cin >> n;
    if (n < 0)
    {
        cout << "Invalid number of vertices!\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter vertex: ";
        cin >> v;

        if (findIndex(v) != -1)
        {
            cout << "Vertex already exists!\n";
            i--;
            continue;
        }
        vertices.push_back(v);
        adj.push_back({});
    }
    cout << "Enter number of edges: ";
    cin >> m;
    if (m < 0)
    {
        cout << "Invalid number of edges!\n";
        return;
    }
    for (int i = 0; i < m; i++)
    {
        cout << "Enter two vertices: ";
        cin >> u >> v;
        addEdge(u, v);
    }
}

void UndirectedGraph::addVertex(int v)
{
    if (findIndex(v) != -1)
    {
        cout << "Vertex already exists!\n";
        return;
    }

    vertices.push_back(v);
    adj.push_back({});

    cout << "Vertex added successfully!\n";
}

void UndirectedGraph::addEdge(int u, int v)
{
    int i = findIndex(u);
    int j = findIndex(v);

    if (i == -1 || j == -1)
    {
        cout << "Vertex not found!\n";
        return;
    }

    if (u == v)
    {
        cout << "Self-loops are not allowed!\n";
        return;
    }

    if (edgeExists(u, v))
    {
        cout << "Edge already exists!\n";
        return;
    }

    adj[i].push_back(v);
    adj[j].push_back(u);
    cout << "Edge added successfully!\n";
}

void UndirectedGraph::deleteVertex(int v)
{
    int index = findIndex(v);
    if (index == -1)
    {
        cout << "Vertex not found!\n";
        return;
    }
    for (int i = 0; i < adj.size(); i++)
    {
        adj[i].erase(
            remove(adj[i].begin(), adj[i].end(), v),
            adj[i].end()
        );
    }
    vertices.erase(vertices.begin() + index);
    adj.erase(adj.begin() + index);
    cout << "Vertex deleted successfully!\n";
}

void UndirectedGraph::deleteEdge(int u, int v)
{
    int i = findIndex(u);
    int j = findIndex(v);
    if (i == -1 || j == -1)
    {
        cout << "Vertex not found!\n";
        return;
    }

    if (!edgeExists(u, v))
    {
        cout << "Edge does not exist!\n";
        return;
    }

    adj[i].erase(
        remove(adj[i].begin(), adj[i].end(), v),
        adj[i].end()
    );

    adj[j].erase(
        remove(adj[j].begin(), adj[j].end(), u),
        adj[j].end()
    );
    cout << "Edge deleted successfully!\n";
}

void UndirectedGraph::displayGraph() const
{
    if (vertices.empty())
    {
        cout << "Graph is empty!\n";
        return;
    }
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i] << " -> ";

        for (int x : adj[i])
            cout << x << " ";

        cout << endl;
    }
}

void UndirectedGraph::searchVertex(int v) const
{
    if (findIndex(v) != -1)
        cout << "Vertex found!\n";
    else
        cout << "Vertex not found!\n";
}

void UndirectedGraph::findDegree(int v) const
{
    int i = findIndex(v);

    if (i == -1)
    {
        cout << "Vertex not found!\n";
        return;
    }
    cout << "Degree of " << v << " = "
         << adj[i].size() << endl;
}

void UndirectedGraph::BFS(int start) const
{
    int i = findIndex(start);
    if (i == -1)
    {
        cout << "Vertex not found!\n";
        return;
    }
    vector<bool> visited(vertices.size(), false);
    queue<int> q;

    visited[i] = true;
    q.push(i);
    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        cout << vertices[index] << " ";
        for (int x : adj[index])
        {
            int j = findIndex(x);

            if (j != -1 && !visited[j])
            {
                visited[j] = true;
                q.push(j);
            }
        }
    }
    cout << endl;
}

void UndirectedGraph::DFS(int start) const
{
    int i = findIndex(start);
    if (i == -1)
    {
        cout << "Vertex not found!\n";
        return;
    }
    vector<bool> visited(vertices.size(), false);
    cout << "DFS Traversal: ";
    DFSHelper(i, visited);
    cout << endl;
}

void UndirectedGraph::checkConnectivity() const
{
    if (vertices.empty())
    {
        cout << "Graph is empty!\n";
        return;
    }
    vector<bool> visited(vertices.size(), false);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        for (int x : adj[index])
        {
            int j = findIndex(x);
            if (j != -1 && !visited[j])
            {
                visited[j] = true;
                q.push(j);
            }
        }
    }
    for (bool x : visited)
    {
        if (!x)
        {
            cout << "Graph is disconnected!\n";
            return;
        }
    }
    cout << "Graph is connected!\n";
}

void UndirectedGraph::findPath(int start, int end) const
{
    int s = findIndex(start);
    int e = findIndex(end);
    if (s == -1 || e == -1)
    {
        cout << "Vertex not found!\n";
        return;
    }
    vector<bool> visited(vertices.size(), false);
    vector<int> parent(vertices.size(), -1);
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int index = q.front();
        q.pop();

        if (index == e)
            break;

        for (int x : adj[index])
        {
            int j = findIndex(x);

            if (j != -1 && !visited[j])
            {
                visited[j] = true;
                parent[j] = index;
                q.push(j);
            }
        }
    }
    if (!visited[e])
    {
        cout << "No path exists!\n";
        return;
    }

    vector<int> path;
    int current = e;
    while (current != -1)
    {
        path.push_back(vertices[current]);
        current = parent[current];
    }
    cout << "Path: ";
    for (int i = (int)path.size() - 1; i >= 0; i--)
    {
        cout << path[i];

        if (i != 0)
            cout << " -> ";
    }
    cout << endl;
}
