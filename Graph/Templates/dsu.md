## Disjoint Set Union(dsu)
- Given an undirected graph
- You can find connected componet using it
- you can check if two node are connected(not necessarily rerectly)
- `O(log n)` one average per union operation. So totally `O(n log n)`.

### About this template
- before doing `Union()` operation and finding `Parent()` you have to `init()`, which will initially mark every node itself as the parent. 

```C++
#include<bits/stdc++.h>
using namespace std;
#define sz 1000007

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
```
