struct edge_node{


    int u;
    int v;
    int p;
    int w;
    bool operator<(const edge_node& p)const
    {
        return w<p.w;
    }



};


int main()
{
    return 0;
}
