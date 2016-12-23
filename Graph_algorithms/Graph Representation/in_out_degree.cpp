#include<iostream>
#include<cstdio>
#include<map>
#include<vector>



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
    for(int i=0;i<new_node_num;i++)
    {
        int size_vec=Graph[i].size();
        cout<<i<<"--->";
        for(int j=0;j<size_vec;j++)
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

int out_degree(int node)
{
    node=node_mp[node];
    return Graph[node].size();
}
int in_degree(int node,int V)
{
    node=node_mp[node];
    int out=0;

    for(int i=0;i<V;i++)
    {
        int ll=Graph[i].size();
        for(int j=0;j<ll;j++)
        {
            if(Graph[i][j]==node)
            {
                out++;

            }
        }
    }
    return out;

}
void in_out_degree(int V)
{
    for(int i=0;i<V;i++)
    {
        cout<<inv_node_mp[i]<<endl;
        cout<<"outdegree = "<< out_degree(inv_node_mp[i])<<endl;
        cout<<"inDegree = "<<in_degree(inv_node_mp[i],V) << endl;

    }
}

int main()
{

    cout <<"Graph"<<endl;
    cin>>nodes>>edges;
    Graph_input_adjacency_mode_maped(nodes,edges);
    in_out_degree(nodes);
    return 0;
}
