#include<bits/stdc++.h>
using namespace std;

const int MAX_E=1000005;        //边数
const int MAX_V=1000005;        //节点数
int in[MAX_V],A[MAX_V],dep[MAX_V];
int dp[100][MAX_V];
struct edge {
	int v;
	int next;           //next数组用于存上一条边的序号
} E[MAX_E+1];
int head[MAX_V+1];  //head[i]表示与序号为i的点相连的最后一条边的 序号
int e=1;            //记录边的序号
void add_edge(int u,int v) {
	E[e].v=v;
	E[e].next=head[u];
	head[u]=e;
	e++;
}
int cnt=1;
int read() {
	int x=0,flag=0;
	char ch=getchar();
	if(ch=='-') flag=1;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x*=10,x+=ch-'0',ch=getchar();
	if(flag) return -x;
	return x;
}

inline void dfs(int s) {
	in[s]=cnt;
	A[cnt++]=s;
	for(int i=head[s]; i; i=E[i].next) {
		int to = E[i].v;
		if(!in[to]) {
			dep[to]=dep[s]+1;
			dfs(to);
			A[cnt++]=s;
		}
	}
}


inline void ST(int n) {
	for(register int i=1; i<=n; ++i)dp[0][i]=A[i];

	int a,b;
	for(register int j=1; j<=log(n)/log(2);++j) {
		for(register int i=1; i<=n-(1<<j)+1;++i) {
			a=dp[j-1][i];
			b=dp[j-1][i+(1<<(j-1))];
			dp[j][i]=dep[a]<dep[b]?a:b;
		}
	}
}

int RMQ(int l, int rr) {
	if(l>rr) swap(l,rr);
	int k = 0;
	while ((1 << (k + 1)) <= rr - l + 1) k++;
	int a=dp[k][l];
	int b=dp[k][rr - (1 << k) + 1];

	return dep[a]<dep[b]?a:b;
}

int main() {
	int n,m,s;
	cin>>n>>m>>s;

	int x,y;
	for(register int i=1; i<n; ++i) {
		x=read();
		y=read();

		add_edge(x,y);
		add_edge(y,x);
	}
	dfs(s);
	ST(cnt-1);
	int a,b;
	for(register int i=1; i<=m; ++i) {
		a=read();
		b=read();
		printf("%d\n",RMQ(in[a],in[b]));
	}
}

