#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int MAX_E=500002;        //边数
const int MAX_V=100001;        //节点数
int n,m,s;
long long  d[MAX_V];
int head[MAX_V+1];  //head[i]表示与序号为i的点相连的最后一条边的 序号
int e=1;              //记录边的序号
bool inq[MAX_V+1];


struct edge {
	int v;
	long long w;
	int next;           //next数组用于存上一条边的序号
} E[MAX_E+1];
struct node { //堆节点
    int u,d;
    bool operator <(const node& rhs) const {
        return d>rhs.d;
    }
};
void add_edge(int u,int v,long long w) {
	E[e].v=v;
	E[e].w=w;
	E[e].next=head[u];
	head[u]=e;
	e++;
}

struct cmp{
	bool operator() (int a,int b)
	{
		return d[a]>d[b];
	}
};
priority_queue <node> q; 

void dijkstra() {
	d[s]=0;
	q.push(node{s,0});

	while(!q.empty()) {
		node tmp = q.top();
		int v=tmp.u;
		q.pop();
		if(inq[v])continue;
		inq[v]=true;
		
		for(int i=head[v];i;i=E[i].next)
		{
			if(d[v]+E[i].w<d[E[i].v])
			{
				d[E[i].v]=d[v]+E[i].w;
				if(!inq[E[i].v])q.push(node{E[i].v,d[E[i].v]});
			}
		}

	}
}

int main() {
	cin>>n>>m>>s;
	int F,G;
	long long W;
	for(register int i=1;i<=n;++i)d[i]=INF;
	for(register int i=1; i<=m; ++i) {
		cin>>F>>G>>W;
		add_edge(F,G,W);
	}

	dijkstra();
	for(register int i=1; i<=n; ++i)cout<<d[i]<<" ";
}
