int lowbit(int x)
{return x&(-x);}
void add(int i,int x)
{
    while(i<=n)
    {
        c[i]+=x;
        i+=lowbit(i);
    }
}
int sum(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
