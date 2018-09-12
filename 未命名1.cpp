#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 2*1e7;
bool h[MAXN+5] = {0};  //Æ½·½Êý 

int main()
{
	int n;
	cin>>n;
	
	for(int i=2;i<=n;i++)
	{
		if(h[i]==true)continue;
		for(int j=1;j*i*i<=MAXN;j++)
		{
			h[j] = true;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		
	}
} 
