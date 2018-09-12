#include <iostream>
using namespace std;
const int MAXL = 10;

int a[MAXL]={0,1,8,6,4,3,2,5,7,9},ss[MAXL]={0};
int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int x)
{
    while(i<=MAXL)
    {
        ss[i]+=x;
        i+=lowbit(i);
    }
}
int query(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=ss[i];
        i-=lowbit(i);
    }
    return sum;
}

int main()
{
    for(int i=1;i<MAXL;++i)
    {
        add(i,a[i]);
    }
    // for(int i=1;i<MAXL;++i)
    // {
    //     cout<<ss[i]<<" ";
    // }
    cout<<query(5)-query(1);
    cout<<endl;
    return 0;
}
