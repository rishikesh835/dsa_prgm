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

int main(){
    fast_io;
    
    return 0;
}