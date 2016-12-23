#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

#define print_graph(V,E,Graph) for(int i=0;i<V;i++){for(int j=0;j<V;j++) cout<<Graph[i][j]<<" ";cout<<endl;}
#define set_arr(arr,row,clm,val) for(int i=0;i<row;i++){for(int j=0;j<clm;j++) arr[i][j]=0;}


map<int,int>node_mp;
int Graph[1000][1000];
int nodes,edges;
int Graph_input_adjacency_matrix_mode(int V,int E){
    cout <<"Graph_input_adjacency_mode get = "<<V<<E<<endl;

    memset(Graph,0,sizeof(Graph));

    int i=0;
    int new_node_num=0;
    while(i++<E)
    {
        int u,v;
        cin>>u>>v;

        Graph[node_mp[u]][node_mp[v]]=1;
        Graph[node_mp[v]][node_mp[u]]=1;
    }

    print_graph(V,E,Graph);


}
int Graph_input_adjacency_matrix_mode_maped(int V,int E){
    cout <<"Graph_input_adjacency_mode get = "<<V<<E<<endl;

    memset(Graph,0,sizeof(Graph));


    int i=0;
    int new_node_num=0;
    while(i++<E)
    {
        int u,v;

        cin>>u>>v;
        if(node_mp.find(u)==node_mp.end())
                node_mp[u]=new_node_num++;
        if(node_mp.find(v)==node_mp.end())
            node_mp[v]=new_node_num++;


        Graph[node_mp[u]][node_mp[v]]=1;
        Graph[node_mp[v]][node_mp[u]]=1;


    }
    print_graph(V,E,Graph);


}

int main(){

    cout <<"Graph"<<endl;
    cin>>nodes>>edges;
    Graph_input_adjacency_matrix_mode(nodes,edges);
    return 0;
}

