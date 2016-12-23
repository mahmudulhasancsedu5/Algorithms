#include<bits/stdc++.h>
using namespace std;

#define white 0
#define gray 1
#define black 2

int nodes;
int edges;
vector<int>graph[1000];
int level[1000];
int visited[1000];
int parent[1000];


map<string,int>node_to_int;
map<int,string>int_to_node;


void graph_input(int V,int E)
{

    string u,v;

    int node_no=1;
    while(E--)
    {
        cin>>u>>v;
        if(node_to_int.find(u)==node_to_int.end())
        {
            node_to_int[u]=node_no;
            int_to_node[node_no]=u;
            node_no++;
        }
        if(node_to_int.find(v)==node_to_int.end())
        {
            node_to_int[v]=node_no;
            int_to_node[node_no]=v;
            node_no++;
        }
        int u_int=node_to_int[u];
        int v_int=node_to_int[v];
        graph[u_int].push_back(v_int);
        graph[v_int].push_back(u_int);

    }

    nodes=node_no;

    for(int i=1; i<nodes; i++)
    {
        int adj_len=graph[i].size();
        cout << int_to_node[i]<< "-----> ";

        for(int j=0; j<adj_len; j++)
        {
            cout<<int_to_node[graph[i][j]]<<" ";
        }

        cout << endl;
    }

}

void print_a_path(int dst)
{
    int parent_dst=parent[dst];
    if(parent_dst==-1) return;
    print_a_path(parent_dst);
    cout<<int_to_node[parent_dst]<<"-->"<<int_to_node[dst]<<endl;
}
void print_all_path(int nodes)
{
    for(int i=1;i<nodes;i++)
    {
        cout <<"path to node = "<<int_to_node[i]<<endl;
        print_a_path(i);

    }
}

void dfs(int source)
{

    int adj_len=graph[source].size();
    for(int i=0;i<adj_len;i++)
    {
        int v=graph[source][i];
        if(visited[v]==0)
        {
            visited[v]=1;
            parent[v]=source;
            cout <<int_to_node[source]<<" "<<int_to_node[v]<<endl;
            dfs(v);

        }

    }
    return;
}


int main()
{
    freopen("in.txt","r",stdin);
    cin>>nodes>>edges;

    graph_input(nodes,edges);

    int source=node_to_int["a"];

    memset(visited,0,sizeof(visited));

    visited[source]=1;
    parent[source]=-1;

    dfs(source);
    print_all_path(nodes);





    return 0;
}

