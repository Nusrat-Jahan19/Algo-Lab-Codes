#include <bits/stdc++.h>
#define INFINITY 999
#define MAX 100
using namespace std;

int V, src, cost[MAX][MAX];
int dis[MAX];
int parent[MAX];
int visited[MAX] = {0};

void init()
{
    int nearest;
    for (int i = 0; i < V; i++)
    {
        parent[i] = nearest;
        dis[i] = INFINITY;
    }
    dis[src] = 0;
}

int getNearest()
{
    int newnode;
    int minvalue = INFINITY;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dis[i] < minvalue)
        {
            minvalue = dis[i];
            newnode = i;
        }
    }
    return newnode;
}
void dijkstra()
{
    for (int i = 0; i < V-1; i++)
    {
        int nearest = getNearest();
        visited[nearest] = 1;
        for (int adj = 0; adj < V; adj++)
        {
            if (cost[nearest][adj] != INFINITY &&!visited[adj] && cost[nearest][adj]
                && dis[adj] > dis[nearest] + cost[nearest][adj])
            {
                dis[adj] = dis[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}

void display()
{
    cout << "NODE:\t\t\tCOST:\t\t\tPATH\n";
    for (int i = 0; i < V; i++)
        if(i!=src)
    {
        cout << i << "\t\t\t" << dis[i] << "\t\t\t"
             << " ";
        cout << i << " ";
        int j = i;
        while (j!= src)
        {
             j = parent[j];
            cout << "<--" << j << " ";

        }
        cout << endl;
    }
}
int main(void){
    cout<<"Number of vertices:";
     cin>>V;
     cout<<"Enter the adjacency matrix:\n";
     for(int i=0;i<V;i++)
     {
         for(int j=0;j<V;j++)
            cin>>cost[i][j];
     }

   cout<<"Enter the starting node:";
   cin>>src;
   init();
   dijkstra();
   display();

}
