#include<iostream>
//#include "Heapsort.cpp"

using namespace std;

const int nv = 4, e = 5;


void heapify(int root, int E[e][3], int n)
{
	int large = root;
	int left = 2*root +1;
	int right = 2*root+2;
	
	if(left<n && right<n)
	{
		if(E[right][2] < E[left][2])
			large = right;
		else
			large = left;
    }
    
	if(E[large][2] > E[root][2])
		large = root;		
		
	if(large != root)
	{
		for (int i = 0; i < 3; ++i)
		{
			int t = E[large][i];
			E[large][i] = E[root][i];
			E[root][i] = t;
		}
		heapify(large,E,n);
	}
}


void createHeap(int E[e][3], int n)
{
	int k =n/2-1;
	while(k != -1)
	{
		heapify(k,E,n);
		k--;
	}
}



int Find(int i, int P[nv])
{
	while(P[i] > -1)
		i = P[i];

	return i;
}

void Union(int i, int j, int P[])
{
	P[i] = j;
}

int Kruskal(int E[e][3],  int t[nv][3])
{
	int m, i, u, v, c, P[nv], k ,j, mincost = 0, n;
	createHeap(E, e);

	cout<<"Src\tDest\tCost\n";
	for(m = 0; m < e ; m++)
	{
		cout<<E[m][0]<<"\t"<<E[m][1]<<"\t"<<E[m][2]<<endl;
	}
	cout<<"___________________________"<<endl;

	// for (i = 0; i < 4; ++i);
	// {
	// 	P[i] = -1;
	//     cout<<P[i]<<"*"<<i;
	// }

	for (int l = 0; l < nv; ++l)
	{
		P[l] = -1;
		//cout<<P[l];
	}
	cout<<endl;

	m = 0, i = 0, n = 0; 

	while( (i < nv-1) && (n < e ))
	{
		u = E[0][0];
		v = E[0][1];
		c = E[0][2];
		
		for (m = 0; m < 3; ++m)
			E[0][m] = E[e - i - 1][m];

		heapify(0, E, e - 1 - i );

				
		j = Find(u, P); 
		k = Find(v, P);


		if(j != k)
		{
			t[i][0] = u;
			t[i][1] = v;
			t[i][2] = c;
			mincost += c;
			i++;
			Union(j, k, P);
		}

		n++;
	}

	if(i != nv-1)
	{
		cout<<"\nNo spanning tree";
		return 0;
	}


	cout<<"SPANNING TREE IS: \n";
	cout<<"Src\t"<<"Dest\t\n";
	for(int j = 0; j < nv - 1 ; j++)
	{
		cout<<t[j][0]<<"\t"<< t[j][1]<<endl;
	}

	cout<<"___________________________"<<endl;

	return mincost;
}

int main()
{
	int E[e][3] = { {0, 1, 10},
					{0, 2, 6},
					{0, 3, 5},
					{1, 3, 15},
					{2, 3, 4}
				};
	int t[nv][3];

	cout<<"\nMINIMUN COST IS "<<Kruskal(E, t)<<"\n";

}
