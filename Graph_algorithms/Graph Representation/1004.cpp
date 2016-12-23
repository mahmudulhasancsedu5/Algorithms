#include<bits/stdc++.h>
using namespace std;
int nodes;
int edges;
int graph[201][201];
int level[201];
int source;

int Graph_input(int n,int e)
{

    memset(graph,0,sizeof(graph));
    int i=1;
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        if(i)
        {
            source=u;
            i=0;
        }

        graph[u][v]=1;
        graph[v][u]=1;
    }

//    for(int i=0;i<nodes;i++)
//    {
//        for(int j=0;j<nodes;j++)
//            cout <<graph[i][j]<<" ";
//        cout << endl;
//    }


}


int color[201];


void bfs(int source)
{
    memset(color,-1,sizeof(color));

    color[source]=0;
    queue<int>q;
    q.push(source);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();

        for(int v=0; v<nodes; v++)
        {
            if(graph[u][v])
            {
                if(color[v]==-1)
                {
                    color[v]=abs(color[u]-1);
                    q.push(v);


                }
                else
                {
                    if(color[v]!=abs(color[u]-1))
                    {
                        cout<<"NOT BICOLORABLE"<<endl;
                        return;
                    }
                }

            }
        }
    }

    cout <<"BICOLORABLE"<<endl;

    return;

}



int main()
{


    while(true)
    {

        cin>>nodes;
        if(nodes==0) break;
        cin>>edges;

        Graph_input(nodes,edges);

        bfs(source);

    }





    return 0;
}
