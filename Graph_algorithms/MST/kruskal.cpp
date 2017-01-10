#include<bits/stdc++.h>


using namespace std;
struct edge_node{


    int u;
    int v;
    int w;
    bool operator<(const edge_node& p)const
    {
        return p.w<w;
    }



};


int nodes,edges;
int parent[1000];



priority_queue<edge_node>pq_edge;
vector<int>graph[1000];

map<string,int>str_to_int;
map<int,string>int_to_str;





void input_graph(int edges)
{

    int i=0;

    string u,v;
    int w;
    int node_num=1;
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



        edge_node node;
        node.u=str_to_int[u];
        node.v=str_to_int[v];
        node.w=w;
        pq_edge.push(node);


        i++;
    }
    nodes=node_num-1;



    return ;

}

void make_set()
{


    for(int i=1;i<=nodes;i++)
    {
        parent[i]=i;
    }
}
int find_set(int x)
{

    if(x!=parent[x])
    {
        return find_set(parent[x]);

    }
    else
    {
        return parent[x];
    }

}

void union_set(int x,int y)
{
    int x_parent=find_set(x);
    int y_parent=find_set(y);

    if(x_parent<y_parent)
    {
        parent[y_parent]=x_parent;
    }
    else
    {
        parent[x_parent]=y_parent;
    }

}

queue<edge_node>mst_edge;
void mst_kruskal()
{
    make_set();

    cout<<pq_edge.size()<<endl;
    while(pq_edge.empty()==false)
    {
        edge_node edge=pq_edge.top();
        pq_edge.pop();

        int u=edge.u;
        int v=edge.v;

        //cout <<int_to_str[u]<<"-->"<<int_to_str[v]<<"("<<edge.w<<")"<<endl;

        int p1=find_set(u);
        int p2=find_set(v);
        //cout<<p1<<" parents "<<p2;
        if(p1!=p2)
        {
            cout <<int_to_str[u]<<"-->"<<int_to_str[v]<<"("<<edge.w<<")    added"<<endl;
            mst_edge.push(edge);
            union_set(u,v);
        }
    }

}
int main()
{

    freopen("k_in.txt","r",stdin);
    cin>>edges;
    input_graph(edges);
    mst_kruskal();







    return 0;
}
