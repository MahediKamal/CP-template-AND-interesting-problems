# 821 - Page Hopping [***Problem Link***](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=10&page=show_problem&problem=762)

## problem simplified:
Given a directed weighted graph in which all nodes can be reached from any starting point. We have to find the
average minimam distance for each pair of nodes.<br>
This is a simple problem of `floyd warshall` algorithm. 


## Solution Idea
- We will use `floyd warshall` to calculate all-pair shortest path.
- Then we simply iterate over all pairs, and count the average distance.



## **Solution Code(C++)**

```C++

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mx 200 // mx is the number of nodes
#define inf 1<<30 // inf + inf > int, so we should use long here



lli d[mx][mx]; // graph
int v_nm, e_nm;

void init(){
    for(int i=0; i<mx-1; i++){
        for(int j=0; j<mx-1; j++){
            d[i][j] = inf;
        }
    }
}

void floyd_warshall(){ // all pair shortest path, 0 based operation
    for (int k = 0; k < v_nm; ++k) {
        for (int i = 0; i < v_nm; ++i) {
            for (int j = 0; j < v_nm; ++j) {
                if (d[i][k] < inf && d[k][j] < inf){ // needed for negative edge
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // normal
                }
            }
        }
    }
}
int main() {
    v_nm = 106;
    int cs = 0;
    while(++cs){
        int a, b; cin>>a>>b;
        if(a==0 && b==0) break;
        init();
        d[a-1][b-1] = 1;

        while(true){
            cin>>a>>b;
            if(a==0 && b==0) break;
            d[a-1][b-1] = 1;
        }
        
        floyd_warshall();



        long double sum = 0, e = 0;
        for(int i=0; i<=100; i++){
            for(int j=0; j<=100; j++){
                if(i!=j && d[i][j]!=inf){
                    sum += d[i][j]; e++;
                }
            }
        }
        long double ans = sum*1.0 / e*1.0;
        cout << fixed << setprecision(3);
        cout<<"Case "<<cs<<": average length between pages = "<<ans<<" clicks"<<endl;
        
    }
}
    
```
