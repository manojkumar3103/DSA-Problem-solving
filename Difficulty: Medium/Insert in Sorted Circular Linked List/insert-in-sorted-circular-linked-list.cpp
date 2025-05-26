/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        
        Node* new_node= new Node(data);
        if(!head)  
        {
            new_node->next=new_node;
            return new_node;
        }
        
        Node* curr=head;
        if (data < head->data) {
            while (curr->next != head)
                curr = curr->next;

            curr->next = new_node;
            new_node->next = head;
            return new_node;  
        }
        
        while(curr->next!=head && curr->next->data<data)
        {
            curr=curr->next;
        }
        
        new_node->next=curr->next;
        curr->next=new_node;
            
        return head;
    }
};