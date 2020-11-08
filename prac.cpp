void f1(Node *head)
{
	Node *prev = NULL;
	Node *curr = head;
	while(curr != NULL)
	{
		Node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
}

void f2(Node *head, int k)
{
	
}