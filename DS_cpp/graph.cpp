#include<iostream>
#include<list>
#include <queue>
#include<limits.h>
#include<set>
using namespace std;
class Graph{
    int V;
    list <int> *l;
    public:
    Graph(int v) {
        V = v;
        l = new list<int>[v];
    }
    void addEdge(int i,int j,bool undir = true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }
    void printAdjList(){
        for(int i = 0;i<V;i++) {
            cout<<i<<"-->";
            for(auto node:l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }
    void bfs(int source) {
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int f = q.front();
            cout<< f<< endl;
            q.pop();

            for(auto nbr: l[f]){
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    void dfsHelper(int node,bool *visited){
        visited[node] = true;
        cout<<node<<",";
        //make a dfs call on it's unvisited neighbor
        for(int nbr : l[node]){
            if(!visited[nbr]){
                dfsHelper(nbr,visited);
            }
        }
        return;
    }
    void dfs(int source) {
        bool *visited = new bool[V]{0};
        dfsHelper(source,visited);
    }
    int dijkstra(int src, int dest) {
        //Data structures 
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> s;

        //l,Init
        dist[src] = 0;
        s.insert({0,src});
        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            int nodeDist = it->first;
            s.erase(it);
            //iterate over the neighbors of node
            for (auto nbrPair : l[node]){
                
            }
        }

    }
};
int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.printAdjList();

    g.bfs(1);
    cout<<"dfs"<<"\n";
    g.dfs(1);
    return 0;
}