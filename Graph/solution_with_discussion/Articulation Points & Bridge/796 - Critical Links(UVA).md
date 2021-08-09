# 796 - Critical Links [***Problem Link***](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737)

## problem simplified:
This is a simple problem; direct use of `finding Bridge` algorithm. Given a graph, you have to find all the bridge.

## Solution Idea
- You just need to use the Finding Bridges template(the offline one).


## **Solution Code(C++)**

```C++


#include <bits/stdc++.h>
using namespace std;
#define mx 1000005

vector<int>grp[mx];
int low[mx], dsc[mx], t;
bool vst[mx];

vector< pair<int,int> >res;
void Bridge(int u,int v){
    // cout<<u<<"-->"<<v<<" "<<"is a bridge"<<endl;
    res.push_back({min(u,v),max(u,v)});
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

int main() {
        int n;
        while(scanf("%d",&n) != EOF){
        for(int i=0; i<n; i++){
            int u, a; scanf("%d (%d) ",&u,&a);
            while(a--){
                int v; cin>>v;
                grp[u].push_back(v);
                grp[v].push_back(u);
            } 
        }
        for(int i=0; i<n; i++){
            if(vst[i] == false) dfs(i,-1);
        }
        sort(res.begin(), res.end());
        cout<<res.size()<<" critical links"<<endl;
        for(int i=0; i<res.size(); i++){
            cout<<res[i].first<<" - "<<res[i].second<<endl;
        }
        cout<<endl;
        for(int i=0; i<=n; i++){
            grp[i].clear(); low[i] = 0; dsc[i] = 0; vst[i] = false;
        }res.clear();
    }
}


```
