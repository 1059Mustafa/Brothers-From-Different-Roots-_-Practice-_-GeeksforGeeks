
///  method 1 using set

void inorder(Node* root,set<int>&s)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,s);
    s.insert(root->data);
    inorder(root->right,s);
}



int countPairs(Node* root1, Node* root2, int x)
{
    set<int>s1;
    set<int>s2;
    inorder(root1,s1);
    inorder(root2,s2);
    int sum=0;
    for(auto i:s1)
    {
        if(s2.find(x-i)!=s2.end())
        {
            sum++;
        }
    }
    return sum;
}

////// methos 2 using recursion


bool search(Node* root, int val)
{
    bool flag=false;
    if(root!=NULL)
    {
    if(root->data==val||search(root->left,val)||search(root->right,val))
    flag=true;

    }
    
    return flag;
}


int countPairs(Node* root1, Node* root2, int x)
{
    if(root1==NULL)
    {return 0;
        
    }
    else if(search(root2,x-root1->data))
    {
        return 1+countPairs(root1->left,root2,x)+countPairs( root1->right,root2, x);
    }
    
    else
    {
        return countPairs(root1->left,root2,x)+countPairs( root1->right,root2, x);
    }
    
}
