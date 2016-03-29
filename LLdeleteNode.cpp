/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    
    Node *temp;
    
    if (position == 0) {
        temp = head->next;
        delete head;
        return temp;
    }
    
    temp = head;
    for (int i = 0; i < position - 1; i++)
        temp = temp->next;
    
    Node *temp2 = temp->next->next;
    delete temp->next;
    temp->next = temp2;
    return head;
    
}