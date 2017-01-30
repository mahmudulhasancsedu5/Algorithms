#include<bits/stdc++.h>
using namespace std;

struct node{


    int key;
    node* p;
    node* left;
    node* right;
    node()
    {
        p=NULL;
        left=NULL;
        right=NULL;
    }




};

node* root=NULL;
void insert_bst(int val)
{
    cout<<val<<endl;
    node* temp=new node();
    temp->key=val;

    if(root==NULL)
    {
        root=temp;
        return;
    }
    node* current=root;
    node* parent=root->p;

    while(current!=NULL)
    {
        parent=current;
        if(val<=current->key)
        {
            current=current->left;

        }
        else current=current->right;
    }

    temp->p = parent;
    if(val<=parent->key)
    {

        parent->left=temp;
    }
    else
    {
        parent->right=temp;
    }


    return;

}


void print_bst(node* rt)
{
    if(rt==NULL) return;


    print_bst(rt->left);
    cout<<rt->key<<" ";
    print_bst(rt->right);

}

node* find_node(int val)
{

    node* current=root;

    while(current!=NULL && current->key!=val)
    {
        if(val<current->key) current=current->left;
        else current=current->right;
    }
    return current;
}

node* successor(int val)
{
    node* search_node=find_node(val);

    if(search_node==NULL) return NULL;


    if(search_node->right!=NULL)
    {
        node* current=search_node->right;
        while(current->left!=NULL)
        {
            current=current->left;
        }
        return current;
    }
    else
    {
        node* current=search_node;

        while(current->p!=NULL && current!=current->p->left)
        {
            current=current->p;
        }
        return current->p;


    }





}

node* predecessor(int val)
{
    node* val_node=find_node(val);

    if(val_node==NULL) return NULL;


    if(val_node->left!=NULL)
    {
        node* current=val_node->left;

        while(current->right!=NULL)
        {
            current=current->right;
        }
        return current;

    }
    else
    {
        node* current=val_node;

        while(current->p!=NULL && current!=current->p->right)
        {

            current=current->p;

        }


        return current->p;
    }
}


void tree_delete(int val)
{
    node* val_node=find_node(val);
    if(val_node==NULL) return ;

    if(val_node->left==NULL && val_node->right==NULL)
    {
        if(val_node==root)
        {
            root=NULL;
        }
        else
        {
            if(val_node==val_node->p->left)
            {
                val_node->p->left=NULL;
            }
            else
            {
                val_node->p->right=NULL;

            }
        }
    }
    else if(val_node->left!=NULL && val_node->right!=NULL)
    {
        node* succ=successor(val);
        val_node->key=succ->key;


        if(succ->right!=NULL)
            succ->right->p=succ->p;

        if(succ==succ->p->left)
        {

            succ->p->left=succ->right;

        }
        else
        {
            succ->p->right=succ->right;

        }
    }
    else if(val_node->left==NULL)
    {
        if(val_node==root)
        {
            root=root->right;
            root->p=NULL;
        }
        else
        {

            if(val_node==val_node->p->left)
            {
                val_node->right->p=val_node->p;
                val_node->p->left=val_node->right;

            }
            else
            {
                val_node->right->p=val_node->p;
                val_node->p->right=val_node->right;
            }
        }

    }
    else if(val_node->right==NULL)
    {
        if(val_node==root)
        {
            root=root->left;
            root->p=NULL;
        }
        else
        {
            if(val_node==val_node->p->left)
            {
                val_node->left->p=val_node->p;
                val_node->p->left=val_node->left;

            }
            else
            {
                val_node->left->p=val_node->p;
                val_node->p->right=val_node->left;

            }
        }

    }

}
int main()
{

    insert_bst(100);
    insert_bst(50);
    insert_bst(200);
    insert_bst(250);
    insert_bst(30);
    insert_bst(70);
    insert_bst(450);
    insert_bst(350);
    insert_bst(550);
    insert_bst(400);
    insert_bst(65);
    print_bst(root);


    int ss=70;
    node* succ=successor(ss);
    if(succ!=NULL) cout<<endl<<"successor of "<<ss<<" is "<<succ->key<<endl;
    node* pre=predecessor(ss);
    if(pre!=NULL) cout<<endl<<"predecessor of "<<ss<<" is "<<pre->key<<endl;



    tree_delete(100);

    print_bst(root);


    return 0;
}
