#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <limits.h>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }
    void addEdge(int u, int v, int wt, bool undir = true)
    {
        l[u].push_back({wt, v});
        if (undir)
        {
            l[v].push_back({wt, u});
        }
    }
    int dijkstra(int src, int dest)
    {
        // Data structures
        vector<int> dist(V, INT_MAX);
        // pair<distance,source>
        set<pair<int, int>> s;

        // l,Init
        dist[src] = 0;
        s.insert({0, src});
        while (!s.empty())
        {
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it);
            // iterate over the neighbors of node
            for (auto nbrPair : l[node])
            {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if (distTillNow + currentEdge < dist[nbr])
                {
                    // remove if nbr already exist in the set

                    auto f = s.find({dist[nbr], nbr});
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    // insert the updated value with the new distance
                    dist[nbr] = distTillNow + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        // single source shortest dist to all other nodes
        for (int i = 0; i < V; i++)
        {
            cout << "Node i " << i << " Dist " << dist[i] << endl;
        }
        return dist[dest];
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);

    cout << g.dijkstra(0, 4);
    return 0;
}