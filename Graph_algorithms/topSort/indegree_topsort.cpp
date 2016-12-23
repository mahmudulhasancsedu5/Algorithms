#include<bits/stdc++.h>

#define MAX_NODE 100000


using namespace std;

map<string,int>str_to_int;

map<int,string>int_to_str;


int graph[10000][10000];

int indegree[MAX_NODE];
vector<string>task_scheduled;

int edges,nodes;


int input_graph(int edges)
{

    string u,v;
    int node_num=1;
    int i=0;
    while(i<edges)
    {
        cin>>u>>v;
        cout<<u<<" "<<v<<endl;
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

        nodes=node_num-1;

        graph[str_to_int[u]][str_to_int[v]]=1;

        indegree[str_to_int[v]]++;

        i++;
    }


}

int hasZero(int nodes)
{
    for(int i=1; i<=nodes; i++)
    {
        if(indegree[i]==0)
        {
            indegree[i]=-1;
            return i;
        }
    }
    return 0;
}

void topology_sort(int nodes)
{
    for(int i=1; i<=nodes; i++)
        cout<<indegree[i]<<" ";
    cout <<endl;

    int i;
    while(i=hasZero(nodes))
    {

        cout<<i<<endl;


        task_scheduled.push_back(int_to_str[i]);

        for(int j=1; j<=nodes; j++)
        {
            if(graph[i][j]==1)
            {
                indegree[j]--;

            }
        }
    }

    int ll=task_scheduled.size();
    for(int i=0; i<ll; i++)
        cout<<task_scheduled[i]<<" ";
    cout <<endl;

    return;
}




int main()
{

    freopen("indegree_gra.txt","r",stdin);
    cin>>edges;
    input_graph(edges);
    topology_sort(nodes);








    return 0;
}
