#include<iostream>
using namespace std;
 
#define N 8
#define INF 2e9

int shortestDist(int graph[N][N]) {
    int dist[N],path[N];
    path[N-1]=-1;
    dist[N-1] = 0;

    for (int i = N-2 ; i >= 0 ; i--)
    {
        dist[i] = INF;
        path[i] = -1;
        for (int j = i ; j < N ; j++)
        {
            if (graph[i][j] == INF)
                continue;

            if(dist[i]>graph[i][j] + dist[j])
            	dist[i] = graph[i][j] + dist[j], path[i] = j;
        }
    }
    
    cout<<"Path :";
    
    for(int i=0;path[i]!=-1;i=path[i])
    {
        cout<<path[i]<<' ';
    }
    cout<<endl;
    return dist[0];
}
 
int main()
{
    int graph[N][N] =
      {{INF, 1, 2, 5, INF, INF, INF, INF},
       {INF, INF, INF, INF, 4, 11, INF, INF},
       {INF, INF, INF, INF, 9, 5, 16, INF},
       {INF, INF, INF, INF, INF, INF, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, 18},
       {INF, INF, INF, INF, INF, INF, INF, 13},
       {INF, INF, INF, INF, INF, INF, INF, 2}};
 
    cout <<"Shortest Distance :"<< shortestDist(graph)<<endl;
    return 0;
}
