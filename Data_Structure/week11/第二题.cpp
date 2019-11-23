
   #include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int cur = 0, num[10];
struct node {
    int num;
    int height;
    node *lc, *rc;
};
int tree_height(node *root)
{
    if(root==NULL)
        return 0;
    else
        return max(tree_height(root->lc), tree_height(root->rc)) + 1;
}
int get_bf(node *root)
{
    if(root==NULL)
        return 0;
    else
        return root->lc->height - root->rc->height;
}
node* r_rotation(node* root) {
    node* temp = root->lc;
    
    root->lc = temp->rc; 
    temp->rc = root; 

    temp->lc->height = max(tree_height(temp->lc), tree_height(temp->rc))+1;
    temp->rc->height = max(tree_height(temp->rc->lc), tree_height(temp->rc->rc))+1;
    
    return temp;
}
node* l_rotation(node* root)
{
    node *temp = root->rc;
    root -> rc = temp->lc;
    temp->lc = root;
    temp->rc->height = max(tree_height(temp->rc), tree_height(temp->rc))+1;
    temp->lc->height = max(tree_height(temp->lc->lc), tree_height(temp->lc->rc))+1;
    return temp;
}
node* Rebalance(node* root) 
{
    int factor = get_bf(root);
    if(factor > 1 && get_bf(root->lc) > 0) 
        return r_rotation(root);
    else if(factor > 1 && get_bf(root->lc) <= 0) 
    { 
        root->lc = l_rotation(root->lc);
        return r_rotation(root);
    } 
    else if(factor < -1 && get_bf(root->rc) <= 0) 
        return l_rotation(root);
    else if((factor < -1 && get_bf(root->rc) > 0)) 
    { 
        root->rc = r_rotation(root->rc);
        return l_rotation(root);
    } 
    else 
        return root;
}
void work(node* root)
{
    if(root==NULL)
        return;
    else 
    {
        int factor = get_bf(root);
        if(abs(factor)>1)
            Rebalance(root);
        work(root->lc);
        work(root->rc);
    }
}
int main()
{
    node *root;
    work(root);
}