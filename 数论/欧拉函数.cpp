//计算x的欧拉函数值 
long long phi(long long x)		
{
    int res = x,a = x;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            res = res/i*(i-1);//res -= res/i;
            while(a%i==0)a/=i;
        }
    }
    if(a>1)res =res/a*(a-1);//res -= res/a;
    return res;
}


//欧拉筛法,快速筛出1-100万的欧拉函数值
const int maxn = 1000000;
int phi[maxn+1];
bool isPrime[maxn+1];
void Eular()
{
    for(int i=1;i<=maxn;i++) phi[i]=i;
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    phi[1]=0;
    for(int i=2;i<=maxn;i++)
    {
        if(isPrime[i])
        {
            for(int j=i;j<=maxn;j+=i)
            {
                isPrime[j]=false;
                phi[j] -= phi[j]/i;
            }
        }
    }
}
