#include<iostream>

using namespace std;

const int n = 5;

int Prims(int cost[n][n], int t[n][2])
{
	int min = 1000, k = -1 ,l = -1, j;
	int near[n], mincost = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if( (min > cost[i][j]) && (cost[i][j] != 0) )
			{
				min = cost[i][j];
				k = i;
				l = j;
			}

		}
	}

	for (int i = 0; i < n; ++i)
	{
		

		if( (cost[i][l] < cost[i][k]) || (cost[i][k] == 0) )
		{
			near[i] = l;
			
		}

		else
		{
			near[i] = k;
			
		}
	}

	near[k] = near[l] = -1;

	t[0][0] = k;
	t[0][1] = l;
	mincost = cost[k][l];



	for (int i = 1; i < n-1; ++i)
	{
		min = 1000;
		for (int m = 0; m < n; ++m)
		{
			if( (near[m] != -1))
			{
				
				if(min > cost[m][near[m]] && cost[m][near[m]]!=0)
				{
					min = cost[m][near[m]];
					cout<<m<<' '<<near[m]<<' '<<min<<endl;
					j  = m;
				}

			}
		}

		t[i][0] = j;
		t[i][1] = near[j];


		mincost += cost[j][near[j]];

		near[j] = -1;
	
	   	for (int k = 0; k < n; ++k)
		{
			if ((near[k] != -1) && ( cost[k][near[k]] > cost[k][j]) && cost[k][j] != 0)
			{
				near[k] = j;
			}
		}

	}


	cout<<"\nMINIMUM SPANNING TREE: \n";
	for (int i = 0; i < n-1; ++i)
	{
		cout<<t[i][0]<<" - "<<t[i][1]<<endl;
	}

	return mincost;
}

int main()
{
	   
	   int graph[n][n] = {{0, 2, 0, 6, 0},
                      	      {2, 0, 3, 8, 0},
                      	      {0, 3, 0, 0, 7},
                      	      {6, 8, 0, 0, 9},
                      	      {0, 0, 7, 9, 0}               
                      	     };


       int t[n][2];
	cout<<"\nMincost: "<<Prims(graph, t)<<endl;
}
