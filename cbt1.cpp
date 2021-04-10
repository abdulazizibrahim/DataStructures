#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left;
    node *right;
    int level;
};
class cbt
{
    private:
        node *root;
        node *temp;
        node *temp1;
    public:
        cbt()
        {
            root = NULL;
            temp = NULL;
            temp1 = NULL;
        }
        int paste()
        {
            print(root);
            cout<<"height of tree is "<<height(root)<<endl;
            return 0;
        }
        int print(node *temp)
        {
            if(temp == NULL)
            {
                cout<<"tree does not exist"<<endl;
                return 0;
            }
            if(temp -> left != NULL)
            {
                print(temp->left);
            }
            cout<<temp->info<<" ";
            if(temp -> right != NULL)
            {
                print(temp->right);
            }
            return 0;
        }
        int pow(int x, int n)
        {
            if( n == 0)
            {
                return 1;
            }
            else
            {
                int sum = 1;
                

                for(int i =0; i<n; i++)
                {
                    sum *= x;
                }
                return sum;
            }
        }
        int insert_level(node *temp)
        {
            if(temp -> left == NULL && temp -> right == NULL)
            {
                node *new1 = new node;
                cout<<"enter value yu want to insert"<<endl;
                cin>>new1->info;
                new1 -> left = NULL;
                new1 -> right = NULL;
                temp -> left = new1;
                temp -> left -> level = height(root);
                new1 = NULL;
                return 0;
            }
            else
            {
                insert_level(temp->left);
            }
            return 0;
        }
        int traversal(node *temp)
        {
            static int h = 0;
            int depth = height(root);
            if(temp == NULL)
            {
                return 0;
            }
            if(temp -> left != NULL && temp -> right == NULL)
            {
                if(temp -> left -> level == depth)
                {
                    node *new1 = new node;
                    cout<<"enter the value you want to insert "<<endl;
                    cin>>new1->info;
                    new1->level = depth;
                    new1 ->left = NULL;
                    new1 -> right = NULL;
                    temp->right = new1;
                    new1 = NULL;
                    return 0;
                }
            }
            if (temp -> left == NULL && temp -> right == NULL)
            {
                if( temp == root)
                {
                    if(temp -> level == depth)
                    {
                        node *new1 = new node;
                        cout<<"enter the value you want to insert "<<endl;
                        cin>>new1->info;
                        new1 ->left = NULL;
                        new1 -> right = NULL;
                        temp -> left = new1;
                        depth = height(root);
                        temp->left -> level = depth;
                        new1 = NULL;
                        return 0;
                    }
                    //insert
                }
                if(temp -> level < depth)
                {
                    node *new1 = new node;
                    cout<<"enter the value you want to insert "<<endl;
                    cin>>new1->info;
                    new1->level = depth;
                    new1 ->left = NULL;
                    new1 -> right = NULL;
                    temp -> left = new1;
                    new1 = NULL;
                    return 0;
                }
                else
                {
                    h++;
                    if(pow(2,height(root)) == h)
                    {
                        insert_level(root);
                        return 0;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            if(temp -> left != NULL)
            {
                traversal(temp -> left);
                //traversal(temp->right);
                return 0;
            }
            //
            if(temp -> right != NULL)
            {
                traversal(temp -> right);
            }
            return 0;
        }
        int height(node *temp)
        {
            if (temp == NULL)
            {
                //cout << "temp is null" << endl;
                return -1;
            }
            else
            {
                

                int LD = height(temp->left);
                int RD = height(temp->right);
                

                if (LD>RD)
                {
                    return (LD + 1);
                }
                

                else
                {
                    return (RD + 1);
                }
            }
        }
            int insert()
            {
                if(root == NULL)
                {
                    cout<<"tree does not exist hence lets make one"<<endl;
                    root = new node;
                    cout<<"enter value you want to insert"<<endl;
                    cin>>root->info;
                    root->left = NULL;
                    root->right = NULL;
                    root->level = 0;
                    return 0;
                }
                else
                {
                    traversal(root);
                    return 0;
                }
            }
            

};
int main()
{
    cbt t;
    for(int i =0; i<8; i++)
    {
        t.insert();
    }
    t.paste();
    

}
