/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    
    if (head == 0) {
        head = new Node;
        head->data = data;
        head->prev = head->next = 0;
        return head;
    }

    Node *temp = head;
    Node *toIns = new Node;
    toIns->data = data;
    
    while (temp->next != 0) {
        if (data <= temp->next->data) {
            toIns->prev = temp;
            toIns->next = temp->next;
            temp->next->prev = toIns;
            temp->next = toIns;
            return head;
        }
        else
            temp = temp->next;
    }
    
    if (temp->data > data) {
        toIns->prev = 0;
        toIns->next = temp;
        temp->prev = toIns;
        if (head->next == 0)
            head = toIns;
    }
    else {
        toIns->prev = temp;
        temp->next = toIns;
        toIns->next = 0;
    }
    return head;    
}