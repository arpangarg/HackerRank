/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
    
    Node *temp = head;
    
    if (position == 0) {
        temp = new Node;
        temp->data = data;
        temp->next = head;
        return temp;
    }

    for (int i = 0; i < position - 1; i++)
        temp = temp->next;

    Node *temp2 = temp->next;
    temp->next = new Node;
    temp->next->data = data;
    temp->next->next = temp2;
    return head;    
}