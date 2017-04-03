#include <iostream>
#include <cstring>
using namespace std;

int z[51][51][51][4][4][4];

void init()
{
	memset(z,10,sizeof(z));
	cout<<z[10][10][10][3][3][2];
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			z[0][0][0][i][j][0]=0;
		}
	}
	for (int i=1;i<4;i++)
	{
		z[1][0][0][1][0][i]=i;
		z[0][1][0][2][0][i]=i;
		z[0][0][1][3][0][i]=i;
		z[1][1][0][1][2][i]=i+1;
		z[1][1][0][2][1][i]=i+1;
		z[1][0][1][1][3][i]=i+1;
		z[1][0][1][3][1][i]=i+1;
		z[0][1][1][2][3][i]=i+1;
		z[0][1][1][3][2][i]=i+1;
		z[2][0][0][1][1][i]=i+1;
		z[0][2][0][2][2][i]=i+1;
		z[0][0][2][3][3][i]=i+1;
		
	}
	return;
}

void DP()
{	
	for (int i=0;i<51;i++)
	{
		for (int j=0;j<51;j++)
		{
			for (int k=0;k<51;k++)
			{
				for (int x=1;x<4;x++)
				{
					for (int y=1;y<4;j++)
					{
						for (int d=1;d<4;d++)
						{
							if (i+j+k>=2)
							{
								for (int u=1;u<4;u++)
								{
									int fi=i;fj=j;fk=k;
									if (u==1) fi++;
									if (u==2) fj++;
									if (u==3) fk++;
									int fd=3;
									z[fi][fj][fk][u][y][fd]=
										min(z[fi][fj][fk][u][y][fd],z[i][j][k][x][y][d]+max(x,u)+1;
									
									z[fi][fj][fk][u][x][fd]=
								}
							}
						}
					}
				}
			}
		}
	}




}

int f(int n,int m,int k)
{
	int minn=10000;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			for (int u=1;u<4;u++)
			{
				if (z[n][m][k][i][j][u]<min)
				{
					minn = z[n][m][k][i][j][u];
				}
			}
		}
	}
	return minn;
}
int main()
{
	init();
	int Q,N,M,K;
	cin>>Q;
	for (int i=0;i<Q;i++)
	{
		cin>>N>>M>>K;
		cout<<f(N,M,K)<<endl;
	}

	return 0;

}
