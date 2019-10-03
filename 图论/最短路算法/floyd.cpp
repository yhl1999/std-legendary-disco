dist[MAXV][MAXV]={0};

for(int k=0;k<n;++k)
    for(int i=0;i<n;++i)
       for(int j=0;j<n;++j)
          dist[i][j]= min(dist[i][j],dist[i][k]+dist[k][j]);