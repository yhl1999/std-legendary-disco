int lowbit(int x)
{return x&(-x);}

//向第i个位置添加x
void add(int i,int x)
{
    while(i<=n)
    {
        c[i]+=x;
        i+=lowbit(i);
    }
}

//返回前x项的和
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

//返回l到r区间内的最大值（树状数组存储的是最值时使用）
int find_max(int l,int r)
{
    int res=0,len=r-l+1;
    while(len&&r)
    {
        if(len<lowbit(r))
        {
            res=max(res,a[r]);
            r--;len--;
        }
        else {
            res=max(res,h[r]);
            len-=lowbit(r);
            r-=lowbit(r);
        }
    }
    return res;
}

//树状数组求逆序数，(i<j && a[i]>a[j])

int inv(int a[],int n){
    int b[n+1]; //存储a数组中第i大的数字的位置
    int res[n+1]={0}; //存储每一位的逆序数
    pair<int,int> p[n+1];
    for(int i=1;i<=n;++i){
        p[i].first=a[i];
        p[i].second=i;
    }
    sort(p+1,p+n+1);
    for(ll i=1;i<=n;++i){
        b[i]=p[n-i+1].second;   
    }

    int ans=0;
    for(int i=1;i<=n;++i){      //把数组a中的数，按照从大到小的顺序插入，用树状数组来统计，第i大的数插入后，在b[i]前有多少个数已经出现
        add(b[i],1);
        res[i]=sum(i-1);
        ans+=res[i];
    }
    return ans;
}