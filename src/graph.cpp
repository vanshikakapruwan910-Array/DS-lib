#include<iostream>
#include "graph.h"
using namespace std;

// Constructor
UndirectedGraph::UndirectedGraph()
{
    vertices.clear();
    adj.clear();
}

// Find index of a vertex
int UndirectedGraph::findIndex(int v) const
{
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] == v)
            return i;
    }
    return -1;
}

// Check whether edge exists
bool UndirectedGraph::edgeExists(int u, int v) const
{
    int i = findIndex(u);

    if (i == -1)
        return false;

    return find(adj[i].begin(), adj[i].end(), v) != adj[i].end();
}

// DFS helper function
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

// 1. CREATE GRAPH
void UndirectedGraph::createGraph()
{
    vertices.clear();
    adj.clear();
    weightedEdges.clear();

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

// 2. ADD VERTEX
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

// 3. ADD EDGE
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

// 4. DELETE VERTEX
void UndirectedGraph::deleteVertex(int v)
{
    int index = findIndex(v);

    if (index == -1)
    {
        cout << "Vertex not found!\n";
        return;
    }

    weightedEdges.erase(
    remove_if(weightedEdges.begin(), weightedEdges.end(),
        [v](const tuple<int, int, int>& edge)
        {
            return get<0>(edge) == v || get<1>(edge) == v;
        }),
    weightedEdges.end()
);


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

// 5. DELETE EDGE
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

weightedEdges.erase(
    remove_if(weightedEdges.begin(), weightedEdges.end(),
        [u, v](const tuple<int, int, int>& edge)
        {
            return
                (get<0>(edge) == u && get<1>(edge) == v) ||
                (get<0>(edge) == v && get<1>(edge) == u);
        }),
    weightedEdges.end()
);
    
    cout << "Edge deleted successfully!\n";
}

// 6. DISPLAY GRAPH
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

// 7. SEARCH VERTEX
void UndirectedGraph::searchVertex(int v) const
{
    if (findIndex(v) != -1)
        cout << "Vertex found!\n";
    else
        cout << "Vertex not found!\n";
}

// 8. FIND DEGREE
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

// 9. BFS
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

// 10. DFS
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

// 11. CHECK CONNECTIVITY
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

// 12. FIND PATH
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


void UndirectedGraph::addWeightedEdge(int u, int v, int weight)
{
    if (findIndex(u) == -1 || findIndex(v) == -1)
    {
        cout << "Vertex does not exist!\n";
        return;
    }

    if (u == v || edgeExists(u, v))
    {
        cout << "Invalid or duplicate edge!\n";
        return;
    }

    addEdge(u, v);

    weightedEdges.push_back({u, v, weight});
}


vector<tuple<int, int, int>>
UndirectedGraph::minimumSpanningTree() const
{
    vector<tuple<int, int, int>> edges = weightedEdges;

    sort(edges.begin(), edges.end(),
         [](const auto& a, const auto& b)
         {
             return get<2>(a) < get<2>(b);
         });

    int n = vertices.size();

    vector<int> parent(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    auto findParent = [&](auto&& self, int x) -> int
    {
        if (parent[x] == x)
            return x;

        return parent[x] = self(self, parent[x]);
    };

    vector<tuple<int, int, int>> mst;

    for (auto edge : edges)
    {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int weight = get<2>(edge);

        int i = findIndex(u);
        int j = findIndex(v);

        int p1 = findParent(findParent, i);
        int p2 = findParent(findParent, j);

        if (p1 != p2)
        {
            mst.push_back({u, v, weight});
            parent[p1] = p2;
        }

        if (mst.size() == n - 1)
            break;
    }

    return mst;
}

vector<int> UndirectedGraph::getVertices() const
{
    return vertices;
}
