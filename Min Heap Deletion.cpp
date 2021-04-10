

#include<iostream>
#include<math.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

class Completebinarytree
{
public:
	node *root, *temp, *n;
	int maxnode, countnode, depth, level, hight, number;
	int lastnodedata = 0;
	bool flag;
	Completebinarytree()
	{
		root = temp = NULL;
		maxnode = countnode = depth = level = hight = 0;
	}

	void insert(node* temp)
	{

		if (root == NULL)
		{
			root = new node;
			root->data = number;
			root->left = NULL;
			root->right = NULL;
			return;

		}

		if (temp->left != NULL&&depth<level)
		{
			depth++;
			insert(temp->left);
			depth--;
			if (temp->data > temp->left->data)
			{
				minheap(temp, temp->left);
			}
		}

		if (flag == true)
		{
			if (temp->left == NULL&&temp->right == NULL)
			{
				temp->left = new node;
				temp->left->data = number;
				temp->left->left = NULL;
				temp->left->right = NULL;
				flag = false;


				if (temp->data > temp->left->data)
				{
					minheap(temp, temp->left);
				}



				return;
			}

			else if (temp->left != NULL&&temp->right == NULL)
			{
				temp->right = new node;
				temp->right->data = number;
				temp->right->left = temp->right->right = NULL;
				flag = false;


				if (temp->data > temp->right->data)
				{
					minheap(temp, temp->right);
				}


				return;
			}
		}
		else
		{
			return;
		}

		if (temp->right != NULL&&depth < level)
		{
			depth++;
			insert(temp->right);
			depth--;
			if (temp->data > temp->right->data)
			{
				minheap(temp, temp->right);
			}
		}
	}

	int height(node *temp)
	{
		if (temp == NULL)
		{
			return 0;
		}
		else
		{
			int LD = height(temp->left);
			int RD = height(temp->right);

			if (LD > RD)
			{
				return (LD + 1);
			}

			else
			{
				return (RD + 1);
			}
		}
	}

	int levelfunction()
	{
		maxnode = pow(2, height(root)) - 1;
		if (countnode == maxnode)
		{
			return level = height(root);
		}
		else
		{
			return level = height(root) - 1;
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




	void minheap(node* parent, node * child)
	{
		int t = parent->data;
		parent->data = child->data;
		child->data = t;
		return;




	}

	int level_(node *temp)
	{
		int count = 0;

		{
			while (temp->left != NULL)
			{
				temp = temp->left;
				count++;
			}
			return count;
		}
	}
	int fun_2(node *temp)
	{
		while (temp) {
			int left_level = level_(temp);
			int right_level = 0;
			if (temp->right != NULL)
				right_level = level_(temp->right) + 1;

			int factor = left_level - right_level;
			if (factor == 0 && left_level == 1 && right_level == 1)
			{
				lastnodedata = temp->right->data;

				node* temp_1 = temp->right;
				temp->right = NULL;
				delete temp_1;
				return lastnodedata;
			}
			if (factor == 1)
			{
				if (temp->right == NULL)
				{
					lastnodedata = temp->left->data;
					node* temp_1 = temp->left;
					temp->left = NULL;
					delete temp_1;
					return lastnodedata;

				}
			}
			if (left_level == right_level)
				temp = temp->right;
			else if (left_level > right_level)
				temp = temp->left;
		}
	}

	void delheap(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{

			if (temp != NULL&&temp->left != NULL)
			{
				if (temp->data > temp->left->data)
				{
					minheap(temp, temp->left);
				}
			}
			

			delheap(temp->left);

			if (temp != NULL&&temp->right != NULL)
			{
				if (temp->data > temp->right->data)
				{
					
					minheap(temp, temp->right);
				}
			}

			
			delheap(temp->right);

			
		}

	}


};


void main()
{


	Completebinarytree c;

	cout << "1-insert" << endl;
	cout << "2-Show Min Heap" << endl;
	cout << "3-Delete Min Heap" << endl;
	cout << "4-Exit" << endl;

	while (1)
	{
		cout << "Enter the Key: ";
		int key;
		cin >> key;
		if (key == 1)
		{
			cout << "Enter the insertion data: ";
			cin >> c.number;
			c.depth = 1;
			c.flag = true;
			c.countnode++;
			c.insert(c.root);
			c.levelfunction();
			

		}
		if (key == 2)
		{
			c.inorder(c.root);
			cout << endl;
		}
		if (key == 3)
		{
			c.fun_2(c.root);
			c.countnode--;
			c.levelfunction();
			cout << "Deleted Heap Data: " << c.root->data << endl;
			c.root->data = c.lastnodedata;
			c.delheap(c.root);
		}

		if (key == 4)
		{
			break;
		}

	}
	

	









}