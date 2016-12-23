#include<bits/stdc++.h>
using namespace std;


int edges;
int nodes;
int graph[31][31];


map<int,int>node_mp;


void Graph_input(int e)
{

    memset(graph,0,sizeof(graph));
    node_mp.clear();
    int ass=1;//mymap[1000]=0
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        if(node_mp.find(u)==node_mp.end()) node_mp[u]=ass++;
        if(node_mp.find(v)==node_mp.end()) node_mp[v]=ass++;

        nodes=ass;

        graph[node_mp[u]][node_mp[v]]=1;
        graph[node_mp[v]][node_mp[u]]=1;


    }
//    cout <<nodes<<endl;
//    for(int i=1; i<nodes; i++)
//    {
//        for(int j=1; j<nodes; j++)
//        {
//            cout <<graph[i][j] <<" ";
//        }
//        cout << endl;
//    }

    return ;
}

int visited[31];
int level[31];
int bfs(int source,int ttl)
{

    memset(visited,0,sizeof(visited));
    memset(level,-1,sizeof(level));

    visited[source]=1;
    level[source]=0;
    queue<int>q;
    q.push(source);


    int count_visited_node=0;
    count_visited_node++;


    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();


        //cout <<"ttl = "<<ttl<<endl;


        for(int i=1; i<nodes; i++)
        {
            int v=i;
            if(graph[u][v]==1)
            {
                if(visited[v]==0)
                {
                    //cout <<v<<endl;
                    count_visited_node++;
                    level[v]=level[u]+1;
                    visited[v]=1;
                    q.push(v);
                }

            }
        }



    }
    int cc=0;
    for(int i=1;i<nodes;i++)
    {
        if(level[i]<=ttl && level[i]>-1) cc++;

    }

    return cc;


}


int main()
{


    int cases=1;
    while(true)
    {
        cin>>edges;
        if (edges==0)
        {
            break;
        }
        Graph_input(edges);
        int source,ttl;
        while(true)
        {
            cin>>source>>ttl;
            if(source==0 && ttl==0)
                break;

            int can_visit=0;
            if(node_mp.find(source)!=node_mp.end())
                can_visit=bfs(node_mp[source],ttl);
            //cout << can_visit<<endl;
            cout <<"Case "<<cases<<": "<<nodes-1-can_visit<<" nodes not reachable from node "<<source<<" with TTL = "<<ttl<<"."<<endl;
            cases++;
        }

    }
    return 0;
}
