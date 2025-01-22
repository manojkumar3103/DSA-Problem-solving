//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head)
    {
        if(!head || !head->next) return head;
        
        Node* prev=NULL;
        while(head)
        {
            Node* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        Node* rev_num1=reverse(num1);
        Node* rev_num2=reverse(num2);
        
        Node* new_head=NULL;
        int carry=0;
        Node* curr=NULL;
        while (rev_num1 || rev_num2 || carry) {
            int sum = carry;
            if (rev_num1) {
                sum += rev_num1->data;
                rev_num1 = rev_num1->next;
            }
            if (rev_num2) {
                sum += rev_num2->data;
                rev_num2 = rev_num2->next;
            }
    
            Node* new_node = new Node(sum % 10);
            carry = sum / 10;
    
             if (!new_head) {
            new_head = new_node;
            } else {
                curr->next = new_node;
            }
            curr = new_node;  // Move to the next node
        }
        Node* head= reverse(new_head);
        while(head->data==0)
        {
            head=head->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends