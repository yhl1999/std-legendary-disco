/*==================================================*\
 |  ����ͼƥ�䣨�������㷨DFS ʵ�֣�
 |  INIT: graph[][]�ڽӾ���;
 |  CALL: res =  dfsHungarian ();
 |  �ŵ㣺ʵ�ּ��������⣬�����ڳ���ͼ��DFS ������·�졣
 |  ��һ������·�ĸ��Ӷ�ΪO(E)�������V������·����ʱ�临�Ӷ�ΪO(VE)
 |  �㷨������
 |  �Ӷ���ͼ���ҳ�һ��·��������·���������յ㶼�ǻ�û��ƥ����ĵ㣬
 |  ����·��������������һ��û��ƥ�䡢һ���Ѿ�ƥ���������һ����ûƥ����������س��֡�
 |  �ҵ�������·������Ȼ·����û��ƥ������߱��Ѿ�ƥ���˵����߶�һ����
 |  �����޸�ƥ��ͼ����·��������ƥ���������ȥ��ƥ���ϵ����û��ƥ������߱��ƥ��ġ�
 |  ����ƥ�����ͱ�ԭ����1��������ִ������������ֱ���Ҳ���������·��Ϊֹ��
 \*==================================================*/
#include<iostream> 
#include<memory.h> 
using namespace std; 
   
#define MAXN 10 
int graph[MAXN][MAXN]; 
int match[MAXN]; 
int visitX[MAXN], visitY[MAXN]; 
int nx, ny; 
   
bool findPath( int u ) 
{ 
    visitX[u] = 1; 
    for( int v=0; v<ny; v++ ) 
    { 
        if( !visitY[v] && graph[u][v] ) 
        { 
            visitY[v] = 1; 
            if( match[v] == -1 //��һ��,�õ��˶�·���㣬����findPath(-1)�������
                    || findPath(match[v]) )//����ͱ�ʾ������ȱ��� ��ײ��ɽͷ���� �����ƺ��Ĳ���
            { 
                match[v] = u; 
                return true; 
            } 
        } 
    } 
    return false; 
} 
   
int dfsHungarian() 
{ 
    int res = 0; 
    memset( match, -1, sizeof(match) ); 
    for( int i=0; i<nx; i++ ) 
    { 
        memset( visitX, 0, sizeof(visitX) ); 
        memset( visitY, 0, sizeof(visitY) ); 
        if( findPath(i) ) 
            res++; 
    } 
    return res; 
}