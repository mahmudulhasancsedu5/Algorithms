#include<iostream>
#include<cstdio>
#include<map>
#include<vector>



using namespace std;

map<int,int>node_mp;
vector< vector<int> >Graph;
int nodes,edges;

int Graph_input_adjacency_mode(int V,int E){
    cout <<"Graph_input_adjacency_mode get = "<<V<<E<<endl;

    int i=0;
    int new_node_num=0;
    while(i<E)
    {
        int u,v;

        cin>>u>>v;
        if(node_mp.find(u)!=node_mp.end()){

                node_mp[u]==new_node_num++;

        }
        if(node_mp.find(v)!=node_mp.end()){

                node_mp[u]==new_node_num++;

        }
        Graph[node_mp[u]].insert(node_mp[v]);

    }
    int vectors_num=Graph.size();
    for(int i=0;i<vectors_num;i++)

}

int main(){

    cout <<"Graph"<<endl;
    cin>>nodes>>edges;
    Graph_input_adjacency_mode(nodes,edges);
    return 0;
}
