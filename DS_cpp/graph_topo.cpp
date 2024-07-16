#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
class Graph{
    list<int> *l;
    int V;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x,int y){
        //adding directed edge
        l[x].push_back(y);
    }
    //topological sort method
    void topological_sort(){
        vector<int> indegree(V);
        // Iterate over all the edges to find indegree 
        for(int i = 0;i < V;i++){
            for(auto nbr : l[i]){
                indegree[nbr]++;
            }
        }
        //BFS
        queue<int> q;
        for(int i = 0;i < V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        // start poppint 
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            //iterate over the nbrs of this node andn reduce their indegree by 1
            for(auto nbr: l[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }
};
int main(){
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(1,4);
    g.addEdge(1,2);

    g.topological_sort();
    return 0;
}