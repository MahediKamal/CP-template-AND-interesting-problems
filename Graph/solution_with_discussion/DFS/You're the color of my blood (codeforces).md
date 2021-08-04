# You're the color of my blood [***Problem Link***](https://codeforces.com/gym/306738/problem/C)

## problem simplified:
Given undirected graph. There are no self-loops or multiple edges between same vertex. </br>
We have to give direction for each edge in such a way that no adjacent edge has the same direction.


## observations
- If there is a cycle with odd length, then It will not be possible to maintain the condition.(adjacent edge with reverse direction)
- To check the odd cycle, and giving the direction we will use the **bipartite graph theory** (https://www.geeksforgeeks.org/check-graphs-cycle-odd-length/)
- Main point is: we will try to colour all the edge in such a way that no adjacent edge has the same color.



## **Solution Code(C++)**

```C++

    #include <bits/stdc++.h>
    using namespace std;
    #define ff first
    #define ss second

    int v_nm, e_nm; // vertex and edge number
    vector<int>graph[200005]; 

    // Trying to give direction to the edge in such a way that, direction of two adjacent edge are reverse.
    // We are using DFS for this purpose.
    // If it is no possible then we will simply print "No"

    map < pair<int,int>, int> direction;
    bool visited[200005];

    bool dfs(int src, int drctn) {
        if(visited[src] == true) return true; // we can't put this visited condition inside the for loop, as we have to visit all the edges
        visited[src] = true;
        drctn = drctn^1; // drctn^1 ="revesreing the direction" (reversing for child)
        bool flg = true;
        for(auto& adj : graph[src]){
            if(drctn == 1){
                if(direction[{adj, src}] == 1) return false; //  if already exist a reverse direction then result is false
                direction[{src,adj}] = 1; // src --> adj
            }else{
                if(direction[{src,adj}] == 1) return false;
                direction[{adj,src}] = 1; // src <-- adj
            }
            flg *= dfs(adj, drctn); // false * true = false. so if a state return false, then result will be false
        }
        return flg;
    }

    int main() {
        cin>>v_nm >>e_nm;

        vector< pair<int,int> > edges;
        for(int i=1; i<=e_nm; i++){
            int u, v; cin>>u >>v;
            graph[u].push_back(v);
            graph[v].push_back(u); // as undirected graph
            edges.push_back({u,v});
        }
        if( dfs(1, 0) == false ){ // dfs calling with source = 1, and direction = 0
            cout<<"NO";
            return 0;
        }
        cout<<"YES"<<endl;
        for(auto& e : edges){
            pair<int,int> pr = e;
            if(direction[pr] == 1 ){
                cout<<1;
            }else if(direction[{pr.ss, pr.ff}] == 1){
                cout<<0;
            }
        }
    }

```
