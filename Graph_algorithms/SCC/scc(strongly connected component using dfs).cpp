#include<bits/stdc++.h>

using namespace std;
int nodes,edges;
vector<int>graph[1000];
vector<int>trans[1000];
map<string,int>str_to_int;
map<int,string>int_to_str;
stack<int>topology;


void DFS_VISIT(int u,vector<int>graph[],int flag);

void input_graph(int nodes,int edges)
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
        trans[v_int].push_back(u_int);

        i++;
    }
    nodes=node_num-1;

    for(int i=1; i<=nodes; i++)
    {
        cout <<i<<"--->";
        int l=graph[i].size();
        for(int j=0; j<l; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout <<endl;
    }


    return ;

}

int visited[1000];
int d[1000];
int f[1000];
int topSorted[1000];
int timestamp=0;
int component_id=1;
int scc_nodes[1000];
void DFS(vector<int>g[],int flag)
{
    memset(visited,0,sizeof(visited));
    memset(d,0,sizeof(d));
    memset(f,0,sizeof(f));


    if(flag==0)
    {


        for(int i=1; i<=nodes; i++)
        {

            if(visited[i]==0)
            {
                DFS_VISIT(i,g,flag);
            }

        }
    }
    else
    {
        while(topology.empty()==false)
        {
            int u=topology.top();
            topology.pop();

            if(visited[u]==0)
            {
                 cout<<endl<<"{";
                DFS_VISIT(u,g,1);
                component_id++;
                cout<<"}"<<endl;

            }

        }

    }

}

void DFS_VISIT(int u,vector<int>graph[],int flag)
{

    timestamp++;
    d[u]=timestamp;
    visited[u]=1;
    int adj_len=graph[u].size();
    for(int i=0; i<adj_len; i++)
    {
        int v=graph[u][i];
        if(visited[v]==0)
        {
            DFS_VISIT(v,graph,flag);
        }
    }

    timestamp++;
    f[u]=timestamp;

    if(flag==0)
    {

        topology.push(u);

    }
    else
    {
        scc_nodes[u]=component_id;
        cout <<int_to_str[u]<<"  ";
    }

    return;
}

void print_topology(stack<int>a)
{
    while(a.empty()==false)
    {
        cout<< int_to_str[a.top()]<<" ";

        a.pop();




    }


    return ;
}

void transpose()
{

    return ;
}

int main()
{

    freopen("in.txt","r",stdin);
    cin>>nodes>>edges;
    input_graph(nodes,edges);
    DFS(graph,0);
    //print_topology(topology);





    DFS(trans,1);

    //get connected component

    vector<int>scc_com[1000];
    for(int i=1;i<=nodes;i++)
    {
        scc_com[scc_nodes[i]].push_back(i);

    }

    for(int i=1;i<component_id;i++)
    {
        int l=scc_com[i].size();


        for(int j=0;j<l;j++)
        {
            cout <<i<< " component "<<int_to_str[scc_com[i][j]]<<endl;
        }
    }


    return 0;
}
