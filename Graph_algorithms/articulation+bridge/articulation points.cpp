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

    int u_flag=0;
    int node_branchs_visit=0;
    for(int i=0; i<adj_len; i++)
    {
        int v=graph[u][i];
        if(visited[v]==0)
        {
            parent[v]=u;

            node_branchs_visit++;

            DFS_VISIT(v);

            low[u]=min(low[u],low[v]);

            if(d[u]<=low[v] && d[u]!=1)
            {


                if(u_flag==0)
                {
                    cout << u << " is a articulation point."<<endl;
                    arti_point.push_back(u);
                    u_flag=1;
                }



            }

        }
        else
        {

            if(d[v]<low[u] && v!=parent[u])
            {
                low[u]=d[v];
            }


        }

    }


    timestamp++;
    f[u]=timestamp;

    if(d[u]==1)
    {
        if(node_branchs_visit>1)
        {
             cout <<"root "<< u << " has "<<node_branchs_visit <<" branches so root is a articulation point."<<endl;
            arti_point.push_back(u);
        }
    }


    return;

}


int main()
{


    freopen("in_arti.txt","r",stdin);
    cin>>edges;
    input_graph(edges);
    DFS();


    return 0;
}
