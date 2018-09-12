
int tot,dis[MAX],q[MAX],g[MAX],n,m,hd,tl,s;
bool inq[MAX];
struct edge{
    int to,w;
    int next;
}e[MAX];
void adde(int frm,int to,int w)
{
    ++tot;
    e[tot].to=to;
    e[tot].w=w;
    e[tot].next=g[frm];
    g[frm]=tot;
}
void spfa()
{
    for(int i=1;i<=n;++i)
    {
        dis[i]=INF;
        inq[i]=false;
    }
    hd=0;tl=1;q[tl]=s;inq[s]=true;dis[s]=0;
    while(hd!=tl)
    {
        hd=hd%MAX+1;
        int x=q[hd];
        inq[x]=false;
        for(int i=g[x];i;i=e[i].next)
        {
            if(dis[e[i].to]>dis[x]+e[i].w)
            {
                dis[e[i].to]=dis[x]+e[i].w;
                if(!inq[e[i].to])
                {
                    tl=tl%MAX+1;
                    q[tl]=e[i].to;
                    inq[e[i].to]=true;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adde(x,y,z);
        adde(y,x,z);
    }
    s=1;
    spfa();
    for(int i=1;i<=n;++i)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}
