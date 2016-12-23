#include<bits/stdc++.h>

#define MAX_NODE 1000

using namespace std;



int nodes,edges;
vector<int>graph[MAX_NODE];

map<string,int>string_to_int;
map<int,string>int_to_string;



void input_graph(int node,int edges)
{


    int i=0;

    string u,v;
    int node_num=1;
    while(i<edges)
    {
        cin>>u>>v;

        if(string_to_int.find(u)==string_to_int.end())
        {
            string_to_int[u]=node_num;
            int_to_string[node_num]=u;
            node_num++;

        }
        if(string_to_int.find(v)==string_to_int.end())
        {

            string_to_int[v]=node_num;
            int_to_string[node_num]=v;
            node_num++;

        }

        nodes=node_num;

        int u_int=string_to_int[u];
        int v_int=string_to_int[v];

        graph[u_int].push_back(v_int);


        i++;
    }

}


int visited[MAX_NODE];
int parent[MAX_NODE];
int d[MAX_NODE];
int f[MAX_NODE];
int sorted_array[MAX_NODE];
int timestamp=0;


void print_topology(int nodes,int n)
{
    if(n>2*nodes) return;

    print_topology(nodes,n+1);
    if(sorted_array[n])
    {
        cout <<int_to_string[sorted_array[n]]<<endl;
    }
}



void DFS_VISIT(int u)
{

    timestamp++;
    d[u]=timestamp;
    visited[u]=1;


    int adj_u=graph[u].size();

    for(int i=0;i<adj_u;i++)
    {
        int v=graph[u][i];
        if(visited[v]==0)
        {
            parent[v]=u;
            DFS_VISIT(v);
        }
        else
        {
            if(d[u]>d[v])//for Back and cross edge
            {
                if(f[u]==0 && f[v]==0)
                {
                    cout <<"Back Edge Exist (Cycle Exist)"<<endl;
                }
                if(f[v]!=0 && f[u]==0)
                {
                    cout <<"Cross Edge Exist"<<endl;

                }


            }
            else if(d[u]<d[v])//for forward edge
            {
                cout <<"Forward Edge Exist"<<endl;
            }
        }
    }
    timestamp++;
    f[u]=timestamp;
    sorted_array[timestamp]=u;

}

void DFS()
{
    timestamp=0;
    memset(visited,0,sizeof(visited));
    for(int u=1;u<nodes;u++)
    {
        if(visited[u]==0)
        {
            DFS_VISIT(u);

        }

    }
    print_topology(nodes,1);
}




int main()
{
    freopen("in.txt","r",stdin);
    cin>>nodes>>edges;
    input_graph(nodes,edges);
    DFS();








    return 0;
}
