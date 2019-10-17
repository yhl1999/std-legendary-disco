#include <bits/stdc++.h>
using namespace std;
const long long MAXN=200002;
const long long MAXE=MAXN;
long long mod;

long long tot,g[MAXN];
struct edge{
    long long to,next;
}e[MAXE];
void adde(long long frm,long long to)
{
    ++tot;
    e[tot].to=to;
    e[tot].next=g[frm];
    g[frm]=tot;
}

long long fa[MAXN],dep[MAXN],siz[MAXN],son[MAXN],top[MAXN],dfn[MAXN],rnk[MAXN],cnt,a[MAXN],at[MAXN];
void dfs1(long long o,long long deep) {
  son[o] = -1;
  siz[o] = 1;
  dep[o]=deep;
  for (long long j = g[o]; j; j = e[j].next)
    if (!dep[e[j].to]) {
      fa[e[j].to] = o;
      dfs1(e[j].to,deep+1);
      siz[o] += siz[e[j].to];
      if (son[o] == -1 || siz[e[j].to] > siz[son[o]]) son[o] = e[j].to;
    }
}
void dfs2(long long o, long long t) {
  top[o] = t;
  cnt++;
  a[cnt]=at[o];
  dfn[o] = cnt;
  rnk[cnt] = o;
  if (son[o] == -1) return;
  dfs2(son[o], t);  // 优先对重儿子进行 DFS，可以保证同一条重链上的点 DFS 序连续
  for (long long j = g[o]; j; j = e[j].next)
    if (e[j].to != son[o] && e[j].to != fa[o]) dfs2(e[j].to, e[j].to);
}

struct nod{
    long long l,r,sum,lazy;
}t[800002];
void buildtree(long long l,long long r,long long root)
{
    t[root].l=l;t[root].r=r;
    long long x=(t[root].l+t[root].r)/2,ch=root*2;
    if(t[root].l==t[root].r)
    {
        t[root].sum=a[l];
        return;
    }
    buildtree(l,x,ch);
    buildtree(x+1,r,ch+1);
    t[root].sum=(t[ch].sum+t[ch+1].sum)%mod;
    return;
}
void changes(long long l,long long r,long long root,long long num)
{
    long long x=(t[root].l+t[root].r)/2,ch=root*2;
    if(t[root].l==l && t[root].r==r)
    {
        t[root].lazy=(t[root].lazy+num)%mod;
        return;
    }
    if(r<=x)changes(l,r,ch,num);
    if(l>x)changes(l,r,ch+1,num);
    if(l<=x && r>x)
    {
        changes(l,x,ch,num);
        changes(x+1,r,ch+1,num);
    }
    t[root].sum=(t[root].sum+(r-l+1)*num)%mod;
}
long long finds(long long l,long long r,long long root)
{
    long long x=(t[root].l+t[root].r)/2,ch=root*2;
    if(t[root].lazy)
    {
        t[root].sum=(t[root].sum+(t[root].r-t[root].l+1)*t[root].lazy)%mod;
        if(t[root].l!=t[root].r)
        {
            t[ch].lazy=(t[ch].lazy+t[root].lazy)%mod;
            t[ch+1].lazy=(t[ch+1].lazy+t[root].lazy)%mod;
        }
        t[root].lazy=0;
    }
    if(t[root].l==l && t[root].r==r)return t[root].sum;
    if(r<=x)return finds(l,r,ch);
    if(l>x)return finds(l,r,ch+1);
    return (finds(l,x,ch)+finds(x+1,r,ch+1))%mod;
}

long long tree_path_sum(long long u, long long v){
    long long tot=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]){
            swap(u,v);
        }
        tot=(tot+finds(dfn[top[u]],dfn[u],1))%mod;
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]){
        swap(u,v);
    }
    tot=(tot+finds(dfn[u],dfn[v],1))%mod;
    return tot;
}
void tree_path_update(long long u,long long v,long long num){
    num%=mod;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]){
            swap(u,v);
        }
        changes(dfn[top[u]],dfn[u],1,num);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]){
        swap(u,v);
    }
    changes(dfn[u],dfn[v],1,num);
}

int main(){
    long long n,m,r,p;
    // 点数，操作数，根节点序号，模数
    cin>>n>>m>>r>>p;
    mod=p;
    for(long long i=1;i<=n;++i){
        cin>>at[i];
    }
    long long q,x,y,z;
    for(long long i=1;i<n;++i){
        cin>>x>>y;
        adde(x,y);
        adde(y,x);
    }
    
    /* 预处理 */
    dfs1(r,1);
    dfs2(r,r);
    buildtree(1,n,1);
    /* 结束预处理 */

    for(long long i=1;i<=m;++i){
        cin>>q;
        if(q==1){
            // 将树从x到y结点最短路径上所有节点的值都加上z
            cin>>x>>y>>z;
            tree_path_update(x,y,z);
        }
        if(q==2){
            // 求树从x到y结点最短路径上所有节点的值之和
            cin>>x>>y;
            cout<<tree_path_sum(x,y)<<endl;
        }
        if(q==3){
            // 将以x为根节点的子树内所有节点值都加上z
            cin>>x>>z;
            changes(dfn[x],dfn[x]+siz[x]-1,1,z);
        }
        if(q==4){
            // 以x为根节点的子树内所有节点值之和
            cin>>x;
            cout<<finds(dfn[x],dfn[x]+siz[x]-1,1)<<endl;
        }
    }
    return 0;
}