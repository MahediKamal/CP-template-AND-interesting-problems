## ## Finding bridges Algorithm (Offline solution)
- Given an undirected graph
- To find all bridges in the given graph
- The time complexity of this algorithm is  `O(V + E)`.

### About this template
- `low` array will save the lowest `ancestor`. `dsc` will save the `discovery time`.

```C++

#include <bits/stdc++.h>
using namespace std;
#define mx 1000005

vector<int>grp[mx];
int low[mx], dsc[mx], t;
bool vst[mx];

void Bridge(int u,int v){
    cout<<u<<"-->"<<v<<" "<<"is a bridge"<<endl;
}
void dfs(int sr,int p = -1){
    vst[sr] = true;
    t++; low[sr] = dsc[sr] = t; 
    for(int i=0; i<grp[sr].size(); i++){
        int v = grp[sr][i];
        if(v == p) continue;
        if(vst[v] == true){
            low[sr] = min(low[sr], dsc[v]);
        }else{
            dfs(v, sr);
            low[sr] = min(low[sr], low[v]);
            if(low[v] > dsc[sr]) Bridge(sr,v);
        }
    }
}

```
