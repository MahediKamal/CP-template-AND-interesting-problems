## ## Finding bridges Algorithm (Offline solution) and Finding critical points
- Given an undirected graph
- To find all bridges and critical points in the given graph
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
bool ctp[mx];

void Bridge(int u, int v) {
    cout<<u<<"-->"<<v<<" "<<"is a bridge"<<endl;
}
void Cutpoint(int u) {
    if(ctp[u] == false){
        cout<<u<<" is a cutpoint"<<endl;
    }
    ctp[u] = true;
}
void dfs(int sr, int p = -1) {
    vst[sr] = true;
    t++; low[sr] = dsc[sr] = t;
    int ch = 0;
    for (int i = 0; i < grp[sr].size(); i++) {
        int v = grp[sr][i];
        if (v == p) continue;
        if (vst[v] == true) {
            low[sr] = min(low[sr], dsc[v]);
        } else {
            dfs(v, sr);
            low[sr] = min(low[sr], low[v]);
            if (low[v] > dsc[sr]) Bridge(sr, v);
            if (low[v] >= dsc[sr] && p != -1) Cutpoint(sr);
            ch++;
        }
    }
    if (p == -1 && ch > 1) Cutpoint(sr);
}

```
