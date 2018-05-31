#include<iostream>

using namespace std;

void SSSP(int n, int cost[9][9], int v)
{
	int distance[n], u, min;  //s maintains flag
	bool  s[n];

	for (int i = 0; i < n; ++i)
	{
		distance[i] = cost[v][i];
		s[i] = false;
	//	cout<<s[i];
	}

	cout<<endl;

	s[v] = true;

	for (int i = 1; i < n; ++i)
	{
		min = 1000;
		for (int j = 1; j < n; ++j)
		{
			if(s[j] == false)
			{
	//			cout<<j<<" j ";
				if( ( min > distance[j]) && (distance[j] != 0) )
				{ 
					u = j;
					min = distance[j];
				}
			}
		}


		s[u] = true;
	//	cout<<"\nu "<<u<<s[u]<<endl;
	//	cout<<"________________________"<<endl;

		for (int w = 0; w < n ; ++w)
		{
			if( (cost[u][w] > 0) && (s[w] == false) )
			{

	//			cout<<u<<w<<" "<<distance[w]<<endl;
				
					if( (distance[w] > (distance[u] + cost[u][w]) ) || (distance[w] == 0) && (w != v) )
					{ 
						distance[w] = distance[u] + cost[u][w];
	//					cout<<u<<w<<" "<<distance[w]<<endl;
					}
				
			}
		}

	//	cout<<"+++++++++++++++++++++++++++++"<<endl;
	}


	for (int i = 0; i < n; ++i)
	{
		cout<<" "<<distance[i];
	}

	cout<<"\n\n";
}

int main()
{
	const int n = 9;
	//cin>>n;
	int cost[n][n] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
	

	SSSP(n, cost, 2);

}