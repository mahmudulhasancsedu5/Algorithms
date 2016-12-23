#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<cstring>




using namespace std;

#define cout_vector(vec) for(int i=0;i<vec.size();i++){for(int j=0;j<vec[i].size();j++){ cout << vec[i][j]<<" ";} cout<<endl;}

map<int,int>node_mp;
map<int,int>inv_node_mp;
vector<int>Graph[1000];
int nodes,edges;

int Graph_input_adjacency_mode_maped(int V,int E)
{
    cout <<"Graph_input_adjacency_mode get = "<<V<<E<<endl;

    int i=0;
    int new_node_num=0;
    while(i++<E)
    {
        int u,v;

        cin>>u>>v;
        if(node_mp.find(u)==node_mp.end())
        {
            node_mp[u]=new_node_num++;
            inv_node_mp[new_node_num-1]=u;
            //cout<<u<<"   "<<node_mp[u]<<endl;

        }
        if(node_mp.find(v)==node_mp.end())
        {

            node_mp[v]=new_node_num++;
            inv_node_mp[new_node_num-1]=v;
            //cout<<v<<"   "<<node_mp[v]<<endl;

        }
        Graph[node_mp[u]].push_back(node_mp[v]);
        //Graph[node_mp[v]].push_back(node_mp[u]);

    }

    //print mapped
    for(int i=0; i<new_node_num; i++)
    {
        int size_vec=Graph[i].size();
        cout<<i<<"--->";
        for(int j=0; j<size_vec; j++)
        {
            cout<<Graph[i][j]<<" ";

        }
        cout << endl;
    }
//    //print real
//    for(int i=0;i<new_node_num;i++)
//    {
//        int size_vec=Graph[i].size();
//        cout<<inv_node_mp[i]<<"--->";
//        for(int j=0;j<size_vec;j++)
//        {
//            cout<< inv_node_mp[Graph[i][j]]<<" ";
//
//        }
//        cout << endl;
//    }


}
int visited[1000];
void bfs(int source)
{
    vector<int>v1;
    v1.push_back(source);
    visited[source]=1;
    while(v1.empty()==false)
    {
        vector<int>v2;
        for(int i=0;i<v1.size();i++)
        {
            int u=v1[i];
            cout <<u<<" ("<<inv_node_mp[u]<<") ";

            visited[u]=1;

            for(int j=0;j<Graph[u].size();j++)
            {
                int v=Graph[u][j];
                if(visited[v]==0)
                    v2.push_back(v);
                    visited[v]=1;

            }

        }
        cout<<endl;
        v1=v2;

    }

}

int level[1000];
int parent[1000];

void BFS(vector<int>graph[],int source,int Nodes)
{
    memset(level,-1,sizeof(level));
    queue<int>q;
    q.push(source);
    level[source]=0;
    parent[source]=-1;
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {

            int v=graph[u][i];

            if(level[v]==-1)
                level[v]=level[u]+1;
                parent[v]=u;
                q.push(v);

        }

    }
    for(int i=0;i<Nodes;i++)
    {
        cout <<inv_node_mp[i] <<" level = "<<level[i]<<endl;
    }

}

int main()
{

    cout <<"Graph"<<endl;
    cin>>nodes>>edges;
    Graph_input_adjacency_mode_maped(nodes,edges);
    //bfs(0);

    BFS(Graph,0,nodes);

    return 0;
}
