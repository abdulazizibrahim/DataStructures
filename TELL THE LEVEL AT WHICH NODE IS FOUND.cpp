void nodelevel(node* temp,int data)
	{
		if (temp == NULL)
		{
			return ;
		}
		else
		{
			l++;
			if (temp->data == data)
			{
				nodel = l;
				
			}
			nodelevel(temp->left,data);
			l--;
			l++;
			nodelevel(temp->right,data);
			l--;
		}

	}