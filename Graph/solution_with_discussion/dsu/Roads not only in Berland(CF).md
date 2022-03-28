# Roads not only in Berland [***Problem Link***](https://codeforces.com/contest/25/problem/D)

## problem simplified:
Given an undirected graph, which may be devided into several component. There are exactly n-1 edge (n is the number of node) in the graph. We have to convert the graph into single connected component(will be a tree).


## Solution Idea
- Using dsu we can seperate the connected component and identify the extra edge that are not needed for being connected.
- After that we will find `k` connected component and `k-1` extra edges. (here 0 <= k <= n).
- now we just need to delete these `k-1` edge and create new `k-1` edge to for connecting the `k` disconnected components.  



## **Solution Code(C++)**

```C++

#include<bits/stdc++.h>
using namespace std;
#define sz 1000007
#define ff first
#define ss second

int n;
int par[sz];
int Size[sz];

void init(){
    for(int i=0; i<=n; i++){
        par[i] = i; Size[i] = 1;
    }
}
int Parent(int i){
    if(par[i] == i) return i;
    return par[i] = Parent(par[i]);
}
void Union(int i, int j){
    i = Parent(i); j = Parent(j);
    if(Size[i] < Size[j]) swap(i,j);
    par[j] = i;
    Size[i] += Size[j];
}

int main() {
    cin>>n;
    init();
    vector< pair <int,int> > extraEdge;
    
    for(int i=1; i<n; i++){
        int u, v; cin>>u>>v;
        if(Parent(u) != Parent(v)){
            Union(u, v);
        }
        else {
            extraEdge.push_back({u, v});
        }
    }
    
    vector<int>disconnectedParents;
    map<int, bool> mp;
    for(int i=1; i<=n; i++){
        if(mp[Parent(i)] == false){
            mp[Parent(i)] = true;
            disconnectedParents.push_back(Parent(i));
        }
    }
    cout<<extraEdge.size()<<endl;
    for(int i=0; i<extraEdge.size(); i++){
        cout<<extraEdge[i].ff<<" "<<extraEdge[i].ss<<" ";
        cout<<disconnectedParents[i]<<" "<<disconnectedParents[i+1]<<endl;
    }
}
  
```
