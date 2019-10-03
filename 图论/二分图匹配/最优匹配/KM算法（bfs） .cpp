/*==================================================*\
  |  ����ͼƥ�䣨�������㷨BFS ʵ�֣�
  |  INIT: graph[][]�ڽӾ���;
  |  CALL: res =  bfsHungarian ();
  |  �ŵ㣺������ϡ�����ͼ���߽��٣�����·�϶̡�
  |  �������㷨�����۸��Ӷ���O(VE)
  \*==================================================*/
#include<iostream> 
#include<memory.h> 
using namespace std; 
   
#define MAXN 10 
int graph[MAXN][MAXN]; 
//��bfs�У�����·����������һ��һ��չ���ģ����Ա���ͨ��prevX����¼��һ��Ķ��� 
//chkY���ڱ��ĳ��Y�����Ƿ�Ŀǰ��X������ʳ��Թ��� 
int matchX[MAXN], matchY[MAXN], prevX[MAXN], chkY[MAXN]; 
int queue[MAXN]; 
int nx, ny; 
   
int bfsHungarian() 
{ 
    int res = 0; 
    int qs, qe; 
    memset( matchX, -1, sizeof(matchX) ); 
    memset( matchY, -1, sizeof(matchY) ); 
    memset( chkY, -1, sizeof(chkY) ); 
   
    for( int i=0; i<nx; i++ ) 
    { 
        if( matchX[i] == -1 )   //�����X����δ�ҵ�ƥ��㣬���������С� 
        { 
            qs = qe = 0; 
            queue[qe++] = i; 
            prevX[i] = -1;  //���ұ�ǣ�����·������� 
            bool flag = 0; 
   
            while( qs<qe && !flag ) 
            { 
                int u = queue[qs]; 
                for( int v=0; v<ny&&!flag; v++ ) 
                { 
                    if( graph[u][v] && chkY[v]!=i ) //����ýڵ���u�б���δ�����ʹ� 
                    { 
                        chkY[v] = i;    //����ҽ�����ǰһ�������������У�Ҳ�����´ο��ܳ���������㿴�ܷ�Ϊ���ҵ��µĽڵ� 
                        queue[qe++] = matchY[v]; 
                        if( matchY[v] >= 0 ) 
                            prevX[matchY[v]] = u; 
                        else    //����������·�������һվ 
                        { 
                            flag = 1; 
                            int d=u, e=v; 
                            while( d!=-1 )  //һ·ͨ��prevX�ҵ�·������� 
                            { 
                                int t = matchX[d]; 
                                matchX[d] = e; 
                                matchY[e] = d; 
                                d = prevX[d]; 
                                e = t; 
                            } 
                        } 
                    } 
                } 
                qs++; 
            } 
            if( matchX[i] != -1 ) 
                res++; 
        } 
    } 
    return res; 
}