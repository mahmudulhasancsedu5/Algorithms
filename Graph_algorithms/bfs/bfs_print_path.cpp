#include<bits/stdc++.h>
using namespace std;


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

    int assignment=1;
    while(E--)
    {
        cin>>u>>v;
        if(node_to_int.find(u)==node_to_int.end())
        {
            node_to_int[u]=assignment;
            int_to_node[assignment]=u;
            assignment++;
        }
        if(node_to_int.find(v)==node_to_int.end())
        {
            node_to_int[v]=assignment;
            int_to_node[assignment]=v;
            assignment++;
        }
        int u_int=node_to_int[u];
        int v_int=node_to_int[v];
        graph[u_int].push_back(v_int);
        graph[v_int].push_back(u_int);

    }
    nodes=assignment;
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
void print_paths(int nodes)
{
    for(int i=1;i<nodes;i++)
    {
        cout <<"path to node = "<<int_to_node[i]<<endl;
        print_a_path(i);

    }
}
void bfs(int source)
{
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    memset(visited,0,sizeof(visited));
    queue<int>q;

    level[source]=0;
    visited[source]=1;
    q.push(source);

    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();

        int adj_len=graph[u].size();
        for(int i=0;i<adj_len;i++)
        {
            int v=graph[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                level[v]=level[u]+1;
                parent[v]=u;
                q.push(v);
            }

        }
    }


}
int main()
{
    freopen("in.txt","r",stdin);
    cin>>nodes>>edges;

    graph_input(nodes,edges);
    bfs(1);
    print_paths(nodes);




    return 0;
}
