
struct nod{
    long long l,r,sum,lazy;
}t[800002];
long long n,q,a[200002];
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
    t[root].sum=t[ch].sum+t[ch+1].sum;
    return;
}
void changes(long long l,long long r,long long root,long long num)
{
    long long x=(t[root].l+t[root].r)/2,ch=root*2;
    if(t[root].l==l && t[root].r==r)
    {
        t[root].lazy+=num;
        return;
    }
    if(r<=x)changes(l,r,ch,num);
    if(l>x)changes(l,r,ch+1,num);
    if(l<=x && r>x)
    {
        changes(l,x,ch,num);
        changes(x+1,r,ch+1,num);
    }
    t[root].sum+=(r-l+1)*num;
}
long long finds(long long l,long long r,long long root)
{
    long long x=(t[root].l+t[root].r)/2,ch=root*2;
    if(t[root].lazy)
    {
        t[root].sum+=(t[root].r-t[root].l+1)*t[root].lazy;
        if(t[root].l!=t[root].r)
        {
            t[ch].lazy+=t[root].lazy;
            t[ch+1].lazy+=t[root].lazy;
        }
        t[root].lazy=0;
    }
    if(t[root].l==l && t[root].r==r)return t[root].sum;
    if(r<=x)return finds(l,r,ch);
    if(l>x)return finds(l,r,ch+1);
    if(l<=x && r>x)return finds(l,x,ch)+finds(x+1,r,ch+1);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    buildtree(1,n,1);
    changes(1,5,1,10);
    for(int i=1;i<=n;++i)
    {
        cout<<finds(i,i,1)<<" ";
    }
    return 0;
}
