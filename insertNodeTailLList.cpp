/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    if (!head) {
        head = new Node;
        head->data = data;
        head->next = 0;
        return head;
    }
    else {
        Node *temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = new Node;
        temp->next->data = data;
        temp->next->next = 0;
        return head;
    }
}