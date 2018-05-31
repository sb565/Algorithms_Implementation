#include<iostream>
using namespace std;

bool max(int a, int b) { return (a > b); }

int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   int L[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0,L[i][w]=0;
           else if (wt[i-1] <= w)
           	 if(max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]))
                 K[i][w] = val[i-1] + K[i-1][w-wt[i-1]] , L[i][w]=1;
                 else
                 K[i][w] = K[i-1][w] , L[i][w]=L[i][w-1];
           else
                 K[i][w] = K[i-1][w] , L[i][w]=L[i][w-1];
       }
   }
   w=W;
   for(int i=n;i>0;i--)
   {
   	if(L[i][w]==1)
   	{
   		cout<<i<<' ';
   		w=w-wt[i-1];
   	}
   }
   cout<<endl;
 
   return K[n][W];
}
 
int main()
{
    int val[] = {60, 100, 120, 10};
    int wt[] = {10, 20, 30, 10};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<"Max Profit :"<<knapSack(W, wt, val, n)<<endl;
    return 0;
}
