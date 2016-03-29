/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method.

    Node *temp = head;
    
    while (temp) {
        swap(temp->prev, temp->next);
        head = temp;
        temp = temp->prev;
    }
    return head;
}