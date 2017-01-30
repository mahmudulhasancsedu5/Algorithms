#include<bits/stdc++.h>



using namespace std;

struct node{


    int n;
    int d;

    bool operator<(const node& p)const
    {
        return d<p.d;
    }



};
vector<int>graph[1000];
vector<int>cost[1000];
int nodes,edges;


map<string,int>str_to_int;
map<int,string>int_to_str;

void input_graph(int edges){

    int node_num=1;

    string u,v;
    int w;

    int i=0;
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

        graph[u_int].push_back(w);
        graph[v_int].push_back(w);

        i++;
    }
    nodes=node_num;

}

int d[1000];
int visited[1000];
void dijkstra(int s)
{
    memset(visited,0,sizeof(visited));
    for(int i=0;i<=nodes;i++)
    {
        d[s]=100000000;

    }
    d[s]=0;
    node tmp;
    tmp.n=s;
    tmp.d=d[s];
    priority_queue<node>pq.
    pq.push();

    while(pq.empty()==false)
    {
        node temp=pq.pop();
        int u=temp.n;
        visited[u]=1;
        int d=temp.d;

        int adj_len=graph[u].size();

        for(int i=0;i<adj_len;i++)
        {
            int v=graph[u][i];
            int w=cost[u][i];
            if(visited[v]==0)
            {
                if(d[u]+w<d[v])
                {
                    d[v]=d[u]+w;

                    node p;
                    p.n=v;
                    p.d=d[v];
                    pq.push(p);
                }

            }
        }


    }



}
int main()
{

    cin>>edges;
    input_graph(edges);



    return 0;
}
