#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct node
{
  int info;
  node *left,*right;
};
class bin_search_tree
{
   private :
	    node *temp;
   public  :
	    node *root;
	    int number;
	    bin_search_tree();
	    void options();
	    void b_search_tree(node *);
	    void in_order(node *);
	    void check()
	    {
	    	int minl = power(2, height(root)-1);
	    	int maxl = power(2, height(root));
	    	int x = leaves(root);
	    	if(x >= minl && x <= maxl)
	    	{
	    		bool flag = 0;
	    		traversal(root, flag);
	    		cout<<"yes cbt"<<endl;
	    		return;
			}
			else
			{
					cout<<"not cbt"<<endl;
	    			return;
			}
		}
	    int power(int x, int n)
	    {
	    	if(n == 0)
	    	{
	    		return 1;
			}
			int sum = 1;
			for(int i=0; i<n; i++)
			{
				sum *= x;
			}
			return sum;
		}
	    void traversal(node *temp, bool flag)
	    {
	    	if(temp == NULL)
	    	{
	    		return;
			}
			if (flag == 1)
			{
				cout<<"not cbt "<<endl;
				exit(0);
			}
			if(temp -> left == NULL && temp -> right != NULL)
			{
				flag = 1;
			}
			if(temp -> left != NULL && temp -> right != NULL)
			{
				if(temp -> left -> left != NULL && temp -> left -> right == NULL && temp -> right -> left != NULL)
				{
					flag = 1;
					
				}
			}
			if(temp -> left != NULL)
			{
				traversal(temp->left, flag);
			}
			if(temp->right != NULL)
			{
				traversal(temp -> right, flag);
			}
			return;
			
		}
	    int leaves(node *temp)
	    {
	    	static int i = 0;
	    	if(temp == NULL)
	    	{
	    		return 0;
			}
			if(temp -> right == NULL && temp -> left == NULL)
			{
				i++;
				return i;
			}
			if(temp -> left != NULL)
			{
				leaves(temp -> left);
			}
			if(temp -> right != NULL)
			{
				leaves(temp -> right);
			}
			return i;
		}
	    int height(node *temp)
	    {
	    	if(temp == NULL)
	    	{
	    		return -1;
			}
			int L = height(temp -> left);
			int R = height( temp -> right);
			if(L>R)
			{
				return (L +1);
			}
			else
			{
				return(R+1);
			}
		}
	    
};
int main()
{
  system("cls");
  char ch;
  bin_search_tree obj;
  while( 4 )
  {
  	
    obj.options();
    ch=getch();
    switch(ch)
     {
       case '1':
		system("cls");
		cout<<"\n Enter number to add in a tree... \n";
		cin>>obj.number;
		obj.b_search_tree( obj.root );
		break;
		case '2':
		system("cls");
		obj.in_order(obj.root);
		break;
		case '3':
		system("cls");
		obj.check();
       case '4':
		exit(0);
		break;
       default :
		exit(0);
		break;
     } // end of switch.
  } // end of while.
}//-----------------------------------------------
bin_search_tree :: bin_search_tree()
{
  root=temp=NULL;
}
//--------------------------------------------------------
void bin_search_tree :: b_search_tree(node *temp)
{
  if( root==NULL )
   {
     temp=new node;
     temp->info = number;
     temp->left=NULL;
     temp->right=NULL;
     root=temp;
     return;
   }

  if( temp->info==number )
   {
      cout<<" \n Given number is already present in tree.\n";
      return;
    }
if(temp->info > number)
   {
      if( temp->left!=NULL )
       {
		 b_search_tree(temp->left);
		 return;
       }
      else
       {
	 temp->left=new node;
	 temp->left->info = number;
	 temp->left->left=NULL;
	 temp->left->right=NULL;
	 return;
       }
   }
  if(temp->info < number)
   {
      if( temp->right!=NULL )
       {
		 b_search_tree( temp->right );
		 return;
       }
      else
       {
	 temp->right=new node;
	 temp->right->info = number;
	 temp->right->left=NULL;
	 temp->right->right=NULL;
	 return;
       }
   }
}
void bin_search_tree :: options()
{
 cout<<"\n\n ************** Select Option *****************.\n";
 cout<<"\n Enter any of choices.\n";
 cout<<"\n 1 : Adding (inserting) node in BST.\n";
 cout<<"\n 2 : Print the whole BST .\n";
 cout<<"\n 3 : CHECK CBT.\n";
 cout<<"\n 4 : QUIT PROGRAM. \n";
}//--------------------------------------------------------------
void bin_search_tree :: in_order(node *temp)
{
  if(root==NULL)
    {
	cout<<" Tree is empty.\n";
	return;
    }
  if( temp->left!=NULL )
    		 in_order(temp->left);
  cout<<temp->info<<"  ";
  if( temp->right!=NULL )
		 in_order(temp->right);
  return;
}//----------------------------  
