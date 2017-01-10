//undirected graph
#include<bits/stdc++.h>

using namespace std;


vector<int>graph[1000];
map<string,int>str_to_int;
map<int,string>int_to_str;

int nodes;
int edges;


int input_graph(int edges)
{

    int i=0;
    string u,v;
    int node_num=1;
    while(i<edges)
    {
        cin>>u>>v;

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


        i++;
    }

    nodes=node_num-1;





    return 0;

}


int visited[1000];
int d[1000];
int f[1000];
int low[1000];
int parent[1000];
vector<int>arti_point;
int timestamp=0;


void DFS_VISIT(int u);
void DFS()
{
    memset(visited,0,sizeof(visited));
    memset(d,0,sizeof(d));
    memset(f,0,sizeof(f));
    memset(low,0,sizeof(low));

    for(int u=1; u<=nodes; u++)
    {
        if(visited[u]==0)
        {
            DFS_VISIT(u);
        }

    }

    return;

}

void DFS_VISIT(int u)
{
    timestamp++;
    d[u]=timestamp;
    visited[u]=1;


    int adj_len=graph[u].size();



    low[u]=d[u];
    for(int i=0; i<adj_len; i++)
    {
        int v=graph[u][i];
        //cout <<int_to_str[u]<<"  "<<int_to_str[v]<<endl;

        if(visited[v]==0)
        {

            parent[v]=u;
            DFS_VISIT(v);
            low[u]=min(low[u],low[v]);

            if(d[u]<low[v])
            {
                cout <<"a bridge = "<<int_to_str[u]<<"-->"<<int_to_str[v]<<endl;
            }


        }
        else
        {
            if(v!=parent[u])
            {
                low[u]=min(low[u],d[v]);

            }

        }


    }


    timestamp++;
    f[u]=timestamp;



    return;

}


int main()
{


    freopen("in_arti.txt","r",stdin);
    cin>>edges;
    input_graph(edges);
    DFS();

    for(int i=1;i<=nodes;i++)
    {
        cout <<i<< " str = " <<int_to_str[i]<<" d/f = "<<d[i]<<"/"<<f[i]<<"  low = "<<low[i]<<endl;
    }


    return 0;
}
