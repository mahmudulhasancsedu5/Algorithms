#include<bits/stdc++.h>

using namespace std;

struct node
{



    int endMark;
    int counts;
    node* next[26];

    node()
    {
        endMark=0;
        counts=0;
        for(int i=0; i<26; i++) next[i]=NULL;

    }





};

node* root;


void insert_trie(node* curr,string str,int poss)
{

    if(poss==str.size()) return;

    cout <<str[poss]<<"-->";

    int ch_ind=str[poss]-'a';

    node* nextNode;
    if(curr->next[ch_ind]==NULL)
    {
        cout<<"NULL"<<endl;
        node* newNode=new node();
        curr->next[ch_ind]=newNode;

    }
    else
    {
        cout<<"NOT NULL"<<endl;
    }
    curr->counts++;
    if(poss+1==str.size())
    {
        curr->endMark=1;
    }
    insert_trie(curr->next[ch_ind],str,poss+1);

}

bool search_word(node* curr,string str,int poss)
{



    if(poss+1==str.size())
    {
        cout <<str[poss]<<endl;
        if(curr->endMark==1) return true;
        else
        {
            return false;
        }
    }

    int ch_ind=str[poss]-'a';
    if(curr->next[ch_ind]==NULL) return false;

    return search_word(curr->next[ch_ind],str,poss+1);


}
void print_word_suff(node* curr,string prefix)
{
    if(curr==NULL) return;
    if(curr->endMark==1)
    {
        cout<<prefix<<endl;
    }
    for(int i=0;i<26;i++)
    {

        print_word_suff(curr->next[i],prefix+(char)('a'+i));


    }
    return;

}
bool search_prefix(node* curr,string prefix,int poss)
{
    if(poss+1==prefix.size())
    {
        cout<<"Wprds start with prefix : "<<prefix<<endl;
        int char_ind=prefix[poss]-'a';
        print_word_suff(curr->next[char_ind],prefix);

        return true;
    }


    int char_ind=prefix[poss]-'a';

    if(curr->next[char_ind]==NULL) return false;

    return search_prefix(curr->next[char_ind],prefix,poss+1);
}
int main()
{

    freopen("trie.txt","r",stdin);
    root=new node();
    string str;

    while(cin>>str)
    {

        cout<<str<<endl;
        insert_trie(root,str,0);
        cout<<"--------------------"<<endl;

    }

    bool f=search_word(root,"tomatos",0);
    if(f) cout<<"Found"<<endl;
    else
    {
        cout<<"Not Found"<<endl;
    }

    //delete(root);

    search_prefix(root,"ap",0);


    return 0;
}
