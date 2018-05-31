#include<iostream>
#define INF 2e5

using namespace std;

const int n=4;
int l[n][n][n];

int warshall(int DO[n][n]){
	int DN[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
			if(DO[j][i]+DO[i][k]<DO[j][k])
				DN[j][k]=DO[j][i]+DO[i][k],l[i][j][k]=1;
			else
				DN[j][k]=DO[j][k], l[i][j][k]=0;
	
		for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
			DO[j][k]=DN[j][k];
	}
}

void Backtrack(int i,int j)
{
	for(int t=n-1;t>=0;t--)
	{
		if(l[t][i][j]==1)
		{
			Backtrack(i,t);
			cout<<t<<' ';
			Backtrack(t,j);
			break;
		}
	}
}

int main()
{
	 int graph[n][n] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
        warshall(graph);
        cout<<1<<' ';
        Backtrack(1,3);
        cout<<3;
}











