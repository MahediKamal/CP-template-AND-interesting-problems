# 315 Network Links [***Problem Link***](https://onlinejudge.org/external/3/315.pdf)

## problem simplified:
This is a simple problem; direct use of `finding critical point` algorithm. Given a graph, you have to find all the critical point(articulation point).

## Solution Idea
- You just need to use the Finding critical point template.


## **Solution Code(C++)**

```C++

#include <bits/stdc++.h>
using namespace std;
#define mx 1000005
 
vector<int>grp[mx];
int low[mx], dsc[mx], t;
bool ctp[mx];
bool vst[mx];
int res = 0;
void Bridge(int u, int v) {
    // cout<<u<<"-->"<<v<<" "<<"is a bridge"<<endl;
}
void Cutpoint(int u) {
    if(ctp[u] == false){
        // cout<<u<<" is a cutpoint"<<endl;
        res++;
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
 
 
 
int main() {
    int n;
    while (cin >> n and n) {
 
        int sr;
        cin.ignore();
        vector<int>v;
        while (true) {
            string str;
            getline(cin, str);
 
            if (str[0] == '0') break;
            stringstream s(str);
            string word;
            while (s >> word)
            {
                v.emplace_back(stoi(word));
            }
 
            if (v[0] == 0) break;
            for (int i = 1; i < v.size(); i++) {
                grp[v[0]].push_back(v[i]);
                grp[v[i]].push_back(v[0]);
                sr = v[i];
            }v.clear();
        }
 
       res = 0;
       dfs(sr, -1);
       cout << res << endl;
       for(int i=0; i<=n; i++){
           low[i] = dsc[i] = 0;
           ctp[i] = vst[i] = false;
           grp[i].clear();
       }t = 0;
    }
}

```
