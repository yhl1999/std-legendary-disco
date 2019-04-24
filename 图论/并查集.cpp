int par[MAXN];   //根 
int renk[MAXN];  //树的高度  rank取名会报错 


void init_union_find(int V)
{
     for(int i=1;i<=V;i++)
     {
             par[i]=i;
             renk[i]=0;
     } 
}

//查询树的根
int find(int x)
{
    if(par[x]==x)
    {
        return x;         
    }
    else
    {
        return par[x] = find(par[x]);
    }
}

//合并x与y所属集合
void unite(int x,int y)
{
     x=find(x);
     y=find(y);
     
     if(x==y)return;
     
     if(renk[x]<renk[y])
     {
         par[x]=y;
     }
     else {
         par[y]=x;
         if(renk[x]==renk[y])renk[x]++;
     }
} 

// 判断x与y是否属于同一个集合 
bool same(int x,int y)
{
     return find(x) == find(y);
} 