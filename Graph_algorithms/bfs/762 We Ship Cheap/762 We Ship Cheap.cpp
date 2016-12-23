#include<bits/stdc++.h>

using namespace std;

int nodes;
map<string,int>city_name_to_id;
map<int,string>city_id_to_name;

int parent[1000];
int visited[1000];
void print_path(int dst)
{
    if(parent[dst]==-1) return;
    print_path(parent[dst]);
    cout<<city_id_to_name[parent[dst]]<<" "<<city_id_to_name[dst]<<endl;

}
void bfs(vector<int>graph[],int s,int d)
{

    memset(visited,0,sizeof(visited));
    memset(parent,0,sizeof(parent));
    parent[s]=-1;
    visited[s]=1;
    queue<int>q;
    q.push(s);

    int route=0;
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();

        int adj_len=graph[u].size();
        int flag=0;
        for(int i=0;i<adj_len;i++)
        {
            int v=graph[u][i];

            if(visited[v]==0)
            {
                parent[v]=u;
                visited[v]=1;
                q.push(v);

                if(v==d)
                {
                    route=1;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    if(route==1)
    {

        print_path(d);

    }
    else{

        cout<<"No route"<<endl;
    }



}


int main()
{

    freopen("in.txt","r",stdin);

    int edges;
    int cc=1;
    while(scanf("%d",&edges)!=EOF)
    {
        vector<int>graph[1000];
        int i=0;
        cout <<edges<<endl;
        int node_num=1;
        while(i<edges)
        {

            string u,v;
            cin>>u>>v;
            cout <<u <<"  "<<v<<endl;

            if(city_name_to_id.find(u)==city_name_to_id.end())
            {
                city_name_to_id[u]=node_num++;
                city_id_to_name[node_num-1]=u;

            }
            if(city_name_to_id.find(v)==city_name_to_id.end())
            {
                city_name_to_id[v]=node_num++;
                city_id_to_name[node_num-1]=v;
            }
            nodes=node_num;

            int u_1=city_name_to_id[u];
            int v_1=city_name_to_id[v];

            graph[u_1].push_back(v_1);
            graph[v_1].push_back(u_1);

            i++;
        }

        string source,dest;
        cin>>source>>dest;
        cout <<source<<"  "<<dest<<endl;
        int s=city_name_to_id[source];
        int d=city_name_to_id[dest];

        if(cc==1)
        {
            cc=0;
        }
        else
        {
            cout << endl;
        }
        bfs(graph,s,d);



    }


    return 0;
}
