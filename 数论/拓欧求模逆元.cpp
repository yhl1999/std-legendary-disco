typedef long long ll;
const ll MOD=; //Ä£Êý 

 void ex_gcd(ll a,ll b,ll &x,ll &y){
 	if(!b){ x=1,y=0; return ; }
 	ex_gcd(b,a%b,x,y);
 	ll t=x; x=y,y=t-(a/b)*y;
 }

 inline ll inv(ll a){
 	ll inv_a,y;
 	ex_gcd(a,MOD,inv_a,y);
 	return inv_a;
 }

