struct Matrix{
	int a[10][10];  //从a[1][1]开始存
	int x,y;      //矩阵的行数和列数 
	Matrix operator* (Matrix b)   //矩阵乘法左矩阵的列数等于右矩阵的行数	
	{
		Matrix ans;
		memset(ans.a,0,sizeof(ans.a));
		ans.x=x;
		ans.y=b.y;
		for(int i=0;i<=ans.x;i++)
			for(int j=0;j<=ans.y;j++)
				for(int k=0;k<=y;k++)
					ans.a[i][j]=(ans.a[i][j]+a[i][k]*b.a[k][j])%mod;
		return ans;
	}
};
 
Matrix Mpow(Matrix a,int b)
{
	Matrix ans;
	memset(ans.a,0,sizeof(ans.a));
	for (int i=1;i<=a.x;i++) ans.a[i][i]=1;
	ans.x=a.x;
	ans.y=a.y;
	while (b)
	{
		if (b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	} 
	return ans;  //ans=a^b;
}