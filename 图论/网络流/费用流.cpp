struct edge
{
    int to,cap,cost,rev;
};
const int MAX_V = 1e5+7;

int V;          //顶点数
vector<edge> G[MAX_V];  //图的临接表表示
int dist[MAX_V];        //最短距离
int prevv[MAX_V],preve[MAX_V];  //最短路中的前驱节点和对应边

//向图中增加一条从from到to容量为cap费用为cost的边
void add_edge(int from,int to,int cap,int cost){
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}

//求解从s到t流量为f的最小费用流
//如果不能再增广则返回-1
int min_cost_flow(int s,int t,int f){
    int res=0;
    while(f>0){
        //利用Bellman-Ford算法求s到t的最短路
        fill(dist,dist+V,INF);
        dist[s]=0;
        bool update = true;
        while(update){
            update=false;
            for(int v=0;v<V;v++){
                if(dist[v]==INF)continue;
                for(int i=0;i<G[v].size();i++){
                    edge &e=G[v][i];
                    if(e.cap>0&& dist[e.to]>dist[v]+e.cost){
                        dist[e.to]=dist[v]+e.cost;
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        update=true;
                    }
                }
            }
        }

        if(dist[t]==INF){
            //不能再增光
            return -1;
        }

        //沿s到t的最短路尽量增广
        int d = f;
        for(int v = t;v!=s;v=prevv[v]){
            d=min(d,G[prevv[v]][preve[v]].cap);
        }

        f-=d;
        res += d*dist[t];
        for(int v=t;v!=s;v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -=d;
            G[v][e.rev].cap +=d;
        }
    }
    return res;
}


