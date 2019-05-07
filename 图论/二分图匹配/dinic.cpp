//dinic求解二分图的最大匹配数
//https://www.luogu.org/problemnew/show/P3386 
/*
	二分图的性质：
	最小边覆盖 = 最大匹配数
	最小点覆盖 = V-最大匹配数
	最大独立集 = V-最大匹配数 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int INF = (unsigned int)(-1)>>1;
const int MAX_V=2005;
struct edge {
	int to,cap,rev;
};

vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];  
void add_edge(int from,int to,int cap) {
	G[from].push_back((edge) {
		to,cap,G[to].size()
	});
	G[to].push_back((edge) {
		from,0,G[from].size()-1
	});
}
void bfs(int s) {
	memset(level,-1,sizeof(level));

	queue<int> que;

	level[s]=0;

	que.push(s);

	while(!que.empty()) {
		int v = que.front();
		que.pop();

		for(int i=0; i<G[v].size(); i++) {
			edge &e = G[v][i];

			if(e.cap > 0 && level[e.to]<0) {
				level[e.to] = level[v] +1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v,int t,int f) {
	if(v == t)return f;

	for(int &i=iter[v]; i<G[v].size(); i++) {
		edge &e = G[v][i];
		if(e.cap > 0 && level[v] < level[e.to]) {
			int d =dfs(e.to,t,min(f,e.cap));

			if(d>0) {
				e.cap -= d;

				G[e.to][e.rev].cap += d;

				return d;
			}
		}
	}

	return 0;
}

int max_flow(int s, int t) {
	int flow = 0;

	for(;;) {
		bfs(s);

		if(level[t]<0)return flow;
		memset(iter,0,sizeof(iter));

		int f;

		while((f= dfs(s,t,INF))>0) {
			flow += f;
		}
	}
}

int main()
{
	int n,m,u,v,e;
	cin>>n>>m>>e;
	int V=n+m;
	int s=0;
	int t=V+1;
	for(int i=1;i<=n;i++)
	{
		add_edge(s,i,1);
	}
	for(int i=1;i<=m;i++)
	{
		add_edge(n+i,t,1);
	}
	for(int i=1;i<=e;i++)
	{
		cin>>u>>v;
		if(u<=n&&v<=m)add_edge(u,n+v,1);
	}
	
	cout<<max_flow(s,t);
} 
