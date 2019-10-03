const int N = 15000000;
bool isPrime[N + 5];		
vector <int> prime;			//存储素数 
int num_prime = 0;			//素数个数 
void getPrime() 			//线性筛求N以内素数表 
{
        memset(isPrime,1,sizeof(isPrime)); 
        for(long i = 2 ; i < N ; i++)        
        {             
            if(isPrime[i]){ 
                prime.push_back(i);
				num_prime++; 
            }                      
                 
            for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++) 
            {                
                isPrime[i * prime[j]] = 0;   
                if( !(i % prime[j] ) )                   
                    break;            
            }         
        }   
}

vector<int> solve(int n)	//分解n的质因数 
{
	if(!num_prime)getPrime();	//需先打印素数表
	
	vector <int> res;
	for(int i=0;i<num_prime;i++)
	{
		if(n==1)return res;
		
		if(isPrime[n])
		{
			res.push_back(n);
			return res;
		}
		
		if(n%prime[i]==0)
		{
			res.push_back(prime[i]);
			while(n%prime[i]==0)n/=prime[i];
		}
	}
	return res;
} 
