#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i <b; i++)
#define rep(i,a,b) for(int i=a; i <b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin() , x.begin()
#define prDouble(x) cout<< fixed << setprecision(10) << x
#define triplet pair<11,pait<11,11>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
using namespace std;


template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
vector<int> topoSort(int V, vector<vector<int>> adj)
{
    // code here
    vector<int> ans;
    vector<int> indegree(V,0);
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        for (auto nbr : adj[i])
        {
            indegree[nbr]++;
        }
    }
    queue<int> q;
    for (int i = V -1; i >= 0; i--)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    if (q.empty())
    {
        return {};
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        visited[node] = true;
        ans.push_back(node);
        for (int nbr : adj[node])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0 && !visited[nbr])
                q.push(nbr);
        }
    }

    // for(int i = 0;i < V; i++){
    //      if(!visited[i]) return {};
    //  }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return ans;
}
int main(){
    fast_io;
    int V = 4;
    vector<vector<int>> graph = {
        {},
        {0},
        {0},
        {0}
    };
    vector<int> vec = topoSort(V,graph);
    return 0;
}