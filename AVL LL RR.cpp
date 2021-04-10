#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

class imp
{
	node *root;
	node *temp;
	node *temp1;
	node *n;

	int d;
public:
	imp()
	{
		root = NULL;
		temp = root;
	}

	node* insert(node *temp, int data)
	{

		if (root == NULL)
		{

			n = new node;
			root = n;
			root->data = data;
			root->left = NULL;
			root->right = NULL;
			temp = root;
			return root;
		}

		if (temp->data == data)
		{
			cout << "Dublicate: " << data << endl;
			return temp;
		}


		if (temp->data > data)
		{
			if (temp->left == NULL)
			{
				temp->left = new node;
				temp->left->data = data;
				temp->left->left = NULL;
				temp->left->right = NULL;
				return temp;
			}
			else
			{
				return	insert(temp->left, data);
			}
		}
		if (temp->data < data)
		{
			if (temp->right == NULL)
			{
				temp->right = new node;
				temp->right->data = data;
				temp->right->left = NULL;
				temp->right->right = NULL;
				return temp;
			}
			else
			{
				return	insert(temp->right, data);
			}
		}
	}

	void preorder(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			cout << temp->data;
			preorder(temp->left);
			preorder(temp->right);

		}
	}

	void del(node *temp, int data)
	{

		if (root->data == data)
		{
			return;
		}
		if (temp->data > data)
		{

			if (temp->left != NULL)
			{

				if (temp->left->data == data && (temp->left->left == NULL) && (temp->left->right == NULL))
				{
					temp1 = temp->left;
					temp->left = NULL;
					delete temp1;
					return;
				}
				if (temp->left->data == data && (temp->left->right == NULL) && (temp->left->left != NULL))
				{
					temp1 = temp->left;
					temp->left = temp->left->left;
					delete temp1;
					return;
				}
				if (temp->left->data == data && (temp->left->right != NULL) && (temp->left->left == NULL))
				{
					temp->left = temp->left->right;
					temp1 = temp->left;
					delete temp1;
					return;
				}

				if (temp->left->data == data && (temp->left->right != NULL) && (temp->left->left != NULL))
				{
					min_left(temp->left->left);
					temp->left->data = d;
					return;
				}

				else
				{

					return del(temp->left, data);
				}
			}
		}

		if (temp->data < data)
		{

			if (temp->right != NULL)
			{

				if (temp->right->data == data && (temp->right->left == NULL) && (temp->right->right == NULL))
				{
					temp1 = temp->right;
					temp->right = NULL;
					delete temp1;
					return;
				}

				if (temp->right->data == data && (temp->right->right == NULL) && (temp->right->left != NULL))
				{
					temp1 = temp->right;
					delete temp1;
					temp->right = temp->right->left;
					return;
				}
				if (temp->right->data == data && (temp->right->right != NULL) && (temp->right->left == NULL))
				{
					temp->right = temp->right->right;
					temp1 = temp->right;
					delete temp1;
					return;
				}

				if (temp->right->data == data && (temp->right->right != NULL) && (temp->right->left != NULL))
				{
					min_right(temp->right->right);
					temp->right->data = d;
					return;

				}
				else
				{
					return del(temp->right, data);
				}


			}
		}
	}

	void min_right(node *temp)
	{
		if (temp->left == NULL)
		{

			d = temp->data;
			del(root, temp->data);
			return;
		}
		else
		{
			min_right(temp->left);
		}
	}

	void min_left(node *temp)
	{
		if (temp->right == NULL)
		{

			d = temp->data;
			del(root, temp->data);
			return;
		}
		else
		{
			min_left(temp->right);
		}
	}

	void inorder(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			inorder(temp->left);
			cout << temp->data << " ";
			inorder(temp->right);
		}
	}

	void postorder(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			postorder(temp->right);
			cout << temp->data << " ";
			postorder(temp->left);
		}
	}

	void search(node *temp, int data)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			if (temp->data == data)
			{
				cout << "Search found" << endl;
				return;
			}
			else
			{
				search(temp->left, data);
				search(temp->right, data);
			}
		}

	}

	int height(node *temp)
	{
		if (temp == NULL)
		{
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

	node* check(node *temp,int data)
	{
		if (temp == NULL)
		{
			return temp;
		}
		else
		{
			check(temp->left,data);
			
			int h = height(temp->left);
			h = h + 1;
			int h2 = height(temp->right);
			h2 = h2 + 1;
			h = h - h2;
			if (h==2)
			{
				if (temp->data > data&&temp->left->data > data)
				{
					temp = LL(temp);
					return temp;
				}

				

			}
			if (h == -2)
			{
				temp =	RR(temp);
				return temp;
			}

			else
			{
				return temp;
			}



		}

	}

	node* LL(node *t)
	{

		
		if (t->left->right!=NULL)
		{
			
			n = new node;
			n->left = NULL;
			n->right = NULL;
			n->data = t->data;
			int b = t->left->right->data;
			temp1 = t->left->right;
			t->left->right = NULL;
			delete temp1;
			
			int a = t->right->data;
			t->data = t->left->data;

			t->left->data = t->left->left->data;
			t->left->left->data = t->left->left->left->data;
			temp1 = t->left->left->left;
			t->left->left->left = NULL;
			delete temp1;
			
			t->right->data = n->data;
			n = new node;
			n->right = n->left = NULL;
			n->data = a;
			t->right->right = n;
			n = new node;
			n->left = n->right = NULL;
			n->data = b;
			t->right->left = n;
			
			return t;

		}

		else{
			n = new node;
			n->left = NULL;
			n->right = NULL;
			n->data = t->data;
			t->data = t->left->data;
			t->left->data = t->left->left->data;
			temp1 = t->left->left;
			t->left->left = NULL;
			t->right = n;
			return t;
			delete temp1;
		}

	}

	node* RR(node *t)
	{


		if (t->right->left != NULL)
		{

			n = new node;
			n->left = NULL;
			n->right = NULL;
			n->data = t->data;
			int b = t->right->left->data;
			temp1 = t->right->left;
			t->right->left = NULL;
			delete temp1;

			int a = t->left->data;
			t->data = t->right->data;

			t->right->data = t->right->right->data;
			t->right->right->data = t->right->right->right->data;
			temp1 = t->right->right->right;
			t->right->right->right = NULL;
			delete temp1;

			t->left->data = n->data;
			n = new node;
			n->left = n->right = NULL;
			n->data = a;
			t->left->left = n;
			n = new node;
			n->left = n->right = NULL;
			n->data = b;
			t->left->right = n;

			return t;

		}

		else{
			n = new node;
			n->left = NULL;
			n->right = NULL;
			n->data = t->data;
			t->data = t->right->data;
			t->right->data = t->right->right->data;
			temp1 = t->right->right;
			t->right->right = NULL;
			t->left = n;
			return t;
			delete temp1;
		}

	}


};


void main()
{
	imp bst;
	node *r = NULL;
	node *print;



	r = bst.insert(r, 2);
	r = bst.check(r,2);
	bst.insert(r, 1);
	r = bst.check(r,1);
	bst.insert(r, 4);
	r = bst.check(r,4);
	bst.insert(r, 5);
	r = bst.check(r,5);
	bst.insert(r, 3);
	r = bst.check(r, 3);
	bst.insert(r, 6);
	r = bst.check(r, 6);
	bst.postorder(r);
	






}