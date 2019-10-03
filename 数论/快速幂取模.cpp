 typedef long long ll;

ll mod_pow(ll x,ll n,ll mod) 
{
    ll res=1;
	x%=mod;
    while(n>0)
    {
        if(n&1)res= res * x%mod; 
        
        x=x*x%mod;    
        
        n>>=1;      
    }
    
    return res;
}
