#include<bits/stdc++.h>

using namespace std;
int nodes,edges;

vector<int>graph[1000];
vector<int>weight[1000];



map<string,int>str_to_int;
map<int,string>int_to_str;


int input_graph()
{

    int i=0;
    int node_num=1;

    string u;
    string v;
    int w;
    while(i<edges)
    {

        cin>>u>>v>>w;

        if(str_to_int.find(u)==str_to_int.end())
        {

            str_to_int[u]=node_num;
            int_to_str[node_num]=u;

            node_num++;


        }
         if(str_to_int.find(v)==str_to_int.end())
        {

            str_to_int[v]=node_num;
            int_to_str[node_num]=v;

            node_num++;


        }

        int u_int=str_to_int[u];
        int v_int=str_to_int[v];

        graph[u_int].push_back(v_int);
        graph[v_int].push_back(u_int);

        weight[u_int].push_back(w);
        weight[v_int].push_back(w);


        i++;
    }

    nodes=node_num;


    for(int i=1;i<nodes;i++ )
    {

        cout<<i<<"--->";
        int l=graph[i].size();
        for(int j=0;j<l;j++)
        {
            cout <<graph[i][j]<<"  ";

        }
        cout <<endl;

    }


}





int parent[1000];
int visited[1000];
int dist[1000];

int all_visited()
{
    for(int i=1;i<nodes;i++)
    {
        if(visited[i]==0)
        {
            return false;
        }
    }
    return true;
}





void prims()
{
    for(int i=1;i<nodes;i++)
    {
        parent[i]=-1;
        dist[i]=10000000;
    }

    int s=1;
    dist[s]=0;

   while(all_visited()==false)
   {

        int min_val=10000;
        int u=-1;
       for(int i=1;i<nodes;i++)
       {

           if(visited[i]==0 && dist[i]<min_val)
           {
               min_val=dist[i];
               u=i;
           }


       }

       cout <<int_to_str[u]<<endl;

       visited[u]=1;
       int u_parent=parent[u];
       dist[u]=dist[u]+dist[u_parent];


       int ll=graph[u].size();
       for(int i=0;i<ll;i++)
       {
           int v=graph[u][i];
           if(visited[v]==0 && dist[v]>weight[u][i])
           {
               parent[v]=u;
               dist[v]=weight[u][i];
           }
       }
   }






}

int main()
{

    freopen("k_in.txt","r",stdin);
    cin>>edges;
    input_graph();

    prims();






    return 0;
}
