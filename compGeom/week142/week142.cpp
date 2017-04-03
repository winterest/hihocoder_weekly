#include <iostream>

using namespace std;
int Q,N,M;
int verX[1000],verY[1000];

class rec
{	
	public:
	int x1,y1,x2,y2,x3,y3,x4,y4;	
};

class line
{
	public:
	int x1,y1,x2,y2;
	bool vertical()
	{	
		if (x1==x2)
		{
			return false;
		}
		return true;
	}
};

int max(int x,int y)
{
	if (x>=y)
	{
		return x;
	}
	else 
	{
		return y;
	}
}
int min(int x,int y)
{
	if (x<=y)
	{
		return x;
	}
	else 
	{
		return y;
	}
}
	
bool jiao(rec rec1,line line1)
{
	int maxX=max(rec1.x1,max(rec1.x2,rec1.x3));
	int maxY=max(rec1.y1,max(rec1.y2,rec1.y3));
	int minX=min(rec1.x1,min(rec1.x2,rec1.x3));
	int minY=min(rec1.y1,min(rec1.y2,rec1.y3));
	if	((min(line1.x1,line1.x2)>=maxX)||	
		 (min(line1.y1,line1.y2)>=maxY)||	
		 (max(line1.x1,line1.x2)<=minX)||	
		 (max(line1.y1,line1.y2)<=minY))	
	{
		return false;
	}	
	return true;
}

bool success()
{	
	int i,j;
	rec rec0;
	line line0;
	int x1,x2,x3,x4,y1,y2,y3,y4;
	
	for (i=0;i<N;i++)
	{	
		if (i=0)
		{
			x1=verX[N-1];
			y1=verY[N-1];
		}
		else
		{	
			x1=verX[i-1];
			y1=verY[i-1];
		}
		x2=verX[i];
		y2=verY[i];
		x3=verX[(i+1)%N];
		y3=verY[(i+1)%N];
		x4=verX[(i+2)%N];
		y4=verY[(i+2)%N];
		if (x1==x2)
		{
			if (y1<y2)
			{
				if (x2<x3)
				{
					if (y3<y4)
					{	rec0.x1=x2; rec0.y1=y2; rec0.x2=x2; rec0.y2=y2-M;
						rec0.x3=x3+M; rec0.y3=y3; rec0.x4=x3+M; rec0.y4=y3-M;
					}
					else
					{	rec0.x1=x2; rec0.y1=y2; rec0.x2=x2; rec0.y2=y2-M;
						rec0.x3=x3; rec0.y3=y3; rec0.x4=x3; rec0.y4=y3-M;
					}
				}
				else
				{
					if (y3<y4)
					{	rec0.x1=x2+M; rec0.y1=y2; rec0.x2=x2+M; rec0.y2=y2+M;
						rec0.x3=x3; rec0.y3=y3; rec0.x4=x3; rec0.y4=y3+M;
					}
					else
					{	rec0.x1=x2+M; rec0.y1=y2; rec0.x2=x2+M; rec0.y2=y2+M;
						rec0.x3=x3-M; rec0.y3=y3; rec0.x4=x3-M; rec0.y4=y3+M;
					}
				}
					
			}
		}
		else
		{
			
		}
	}
	return true;
}

int main()
{
	cin>>Q;
	for (int i=0;i<Q;i++)
	{
		cin>>N>>M;
		for (int j=0;j<N;j++)
			cin>>verX[j]>>verY[j];
		if (success())
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
