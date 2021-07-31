```C++
struct node{
    int vrtx;
    int wght;
    node(int _vrtx,int _wght){
        vrtx=_vrtx;
        wght=_wght;
    }
    bool operator < (const node& p) const {   return wght >p.wght;}
};
int vertxnum;
int edgenum;

int dist[100000];
void Dijaxtra(int src,vector< pair<int,int> >graph[]){
    bool visit[100000];
    for(int i=1;i<=vertxnum;i++){
        dist[i]=inf;
        visit[i]=false;
    }

    priority_queue< node >prq;
    prq.push(node(src,0));
    dist[src]=0;
    while(!prq.empty()){
        node tp=prq.top();
        prq.pop();
        int W=tp.wght;
        int V=tp.vrtx;
        if(visit[V]==true) continue;
        visit[V]=true;
        for(int i=0;i<graph[V].size();i++){
            pair<int,int> pr=graph[V][i];
            int u=pr.first;
            int w=pr.second;
            if(dist[u]>W+w){
                dist[u]=w+W;
                prq.push(node(u,w+W));
            }
        }
    }
}
