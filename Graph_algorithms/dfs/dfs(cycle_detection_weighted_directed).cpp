#include<bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int nodes;
int edges;
vector<int>graph[1000];

int color[1000];
int parent[1000];

int d[1000],f[1000];
int timestamp=0;


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
        //graph[v_int].push_back(u_int);//for undirected graph

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
    for(int i=1; i<nodes; i++)
    {
        cout <<"path to node = "<<int_to_node[i]<<endl;
        print_a_path(i);

    }
}

void DFS_VISIT(int u)
{
    timestamp++;
    d[u]=timestamp;

    color[u]=GRAY;

    int adj_len=graph[u].size();

    for(int i=0; i<adj_len; i++)
    {
        int v=graph[u][i];
        if(color[v]==WHITE)
        {
            cout <<"Tree Edge = "<<int_to_node[u]<<"-->"<<int_to_node[v]<<endl;

            parent[v]=u;
            DFS_VISIT(v);

        }
        else if(color[v]==GRAY)
        {
            cout <<"Back Edge = "<<int_to_node[u]<<"-->"<<int_to_node[v]<<endl;
            cout << "Cycle exist."<<endl;
        }
        else if(color[v]==BLACK)
        {
            cout<<"Forword Edge or Cross Edge = "<<int_to_node[u]<<"-->"<<int_to_node[v]<<endl;
        }
    }
    color[u]=BLACK;

    timestamp++;
    f[u]=timestamp;



}

void DFS(int nodes)
{
    timestamp=0;
    memset(color,WHITE,sizeof(color));//set all node color as unvisited
    for(int i=1; i<nodes; i++)
    {

        if(color[i]==WHITE)
        {
            parent[i]=-1;

            DFS_VISIT(i);
        }

    }

}


int main()
{
    freopen("in.txt","r",stdin);
    cin>>nodes>>edges;

    graph_input(nodes,edges);

    int source=node_to_int["a"];
    DFS(nodes);
    print_all_path(nodes);








    return 0;
}


