#include<bits/stdc++.h>
using namespace std;
const int MAXV=100+1;
int n,s,t,m;
struct node{
	int x,y;
}point[MAXV];

double G[MAXV][MAXV];

double dis(int p1,int p2)
{
	double res;
	res = (point[p1].x-point[p2].x)*(point[p1].x-point[p2].x)+(point[p1].y-point[p2].y)*(point[p1].y-point[p2].y);
	
	return sqrt(res);
}

void add_edge(int u,int v,double w)
{
	G[u][v]=w;
	G[v][u]=w;
}

double d[MAXV]={0};
bool inq[MAXV]={false};
queue <int> q;
void spfa()
{
	for(int i=1;i<=n;i++)d[i]=DBL_MAX;
	d[s]=0;
	
	q.push(s);
	inq[s]=true;
	while(!q.empty())
	{
		int h = q.front();
		q.pop();
		inq[h]=false;
		
		for(int i=1;i<=n;i++)
		{
			if(G[h][i]!=0 && inq[i]==false)
			{
				if(d[h]+G[h][i]<d[i])
				{
					d[i]=d[h]+G[h][i];
					q.push(i);
					inq[i]=true;
				}
			}
			else continue;
		} 
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>point[i].x>>point[i].y;
	}
	cin>>m;
	
	int a,b;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		add_edge(a,b,dis(a,b));
	}
	
	cin>>s>>t;
	
	spfa();
	
	printf("%.2lf",d[t]);
	return 0;
	
} 
/*
5
0 0
2 0
2 2
0 2
3 1
5
1 2
1 3
1 4
2 5
3 5
1 5
*/
