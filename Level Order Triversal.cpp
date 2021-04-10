void levelorder(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			queue<node*> Q;
			Q.push(temp);
			while (!Q.empty())
			{
				node *current = Q.front();
				cout << current->data << " ";
				if (current->left != NULL)
				{
					Q.push(current->left);
				}
				if (current->right != NULL)
				{
					Q.push(current->right);
				}
				Q.pop();
			}

		}
	}