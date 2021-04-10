	void insert(node *temp)
		{
			if (root == NULL)
			{
				cout << "Empty\n";
				node *temp1 = new node;
				cout<<"enter value"<<endl;
				cin >> temp1->info;
				temp1->right = temp1->left = NULL;
				root = temp1;
				return;
			}
			if (temp->right == NULL && temp->left == NULL)
			{
				if (flag == false)
				{
					node *temp1 = new node;
					cout<<"enter value"<<endl;
					temp->left = temp1;
					cin >> temp1->info;
					temp1->right = temp1->left = NULL;
					count++;
				}
				if (flag == true)
				{
					temp->right = new node;
					cout<<"enter value"<<endl;
					cin >> temp->right->info;
					temp->right->right = temp->right->left = NULL;
					count++;
				}
				if (count == 2)
				{
					if (flag == true && count == 2)
					{
						flag = false;
						count = 0;	
					}
					if (flag == false && count == 2)
					{
						flag = true;
						count = 0;	
					}
					cout << flag << endl;
				}
				return;
			}
			if (temp->right != NULL)
			{
				insert(temp->right);
			}
			if (temp->left != NULL)
			{
				insert(temp->left);
			}
		}
