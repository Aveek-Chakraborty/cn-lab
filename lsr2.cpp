#include <bits/stdc++.h>
using namespace std;

#define INF 999
#define MAX 100

vector<vector<int>> cost(MAX, vector<int>(MAX, 0));
vector<int> dist(MAX, 0);
vector<int> visited(MAX, 0);
vector<int> parent(MAX, 0);
int source;
int n;

void init()
{
    visited[source] = 1;
    parent[source] = source;
    for (int i = 0; i < n; ++i)
    {
        dist[i] = cost[source][i];
        if (cost[source][i] != INF)
            parent[i] = source;
    }
}

int getMin()
{
    int minIdx = -1;
    int minDist = INF;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && minDist >= dist[i])
        {
            minIdx = i;
            minDist = dist[i];
        }
    }
    return minIdx;
}

void updateTable(int node)
{
    for (int i = 0; i < n; ++i)
    {
        if (cost[node][i] != INF &&
            dist[i] > dist[node] + cost[node][i])
        {
            dist[i] = dist[node] + cost[node][i];
            parent[i] = node;
        }
    }
}

void display()
{
    int node;
    cout << "\nNode \t Distance from Source \t Path \n";
    for (int i = 0; i < n; ++i)
    {
        cout << i << "\t\t" << dist[i] << "\t\t";
        node = i;
        cout << node;
        while (node != source)
        {
            cout << " <- " << parent[node];
            node = parent[node];
        }
        cout << "\n";
    }
}

int main()
{
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter source node: ";
    cin >> source;

    cout << "Enter the cost matrix: ";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cost[i][j];

    init();

    for (int i = 0; i < n - 1; ++i)
    {
        int node = getMin();
        visited[node] = 1;
        updateTable(node);
    }
    display();
    return 0;
}