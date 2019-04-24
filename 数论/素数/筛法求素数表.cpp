const int N = 15000000;
bool isPrime[N + 5];
int prime[N/10];
int num_prime = 0;
void genPrime() 
{
        memset(isPrime,1,sizeof(isPrime)); 
        for(long i = 2 ; i < N ; i++)        
        {             
            if(isPrime[i]){ 
                prime[num_prime ++]=i; 
            }                      
                 
            for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++) 
            {                
                isPrime[i * prime[j]] = 0;   
                if( !(i % prime[j] ) )                   
                    break;            
            }         
        }   
} 