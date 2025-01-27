//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v)
    {
        key=k;
        value=v;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
  private:
  public:
    // Constructor for initializing the cache capacity with the given value.
    int capacity;
    unordered_map<int,Node*> cacheMap;
    Node* head;
    Node* tail;
    
    LRUCache(int cap) {
        this->capacity=cap;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void add(Node* node)
    {
        Node * temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
    }
    void remove(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    // Function to return value corresponding to the key.
    int get(int key) {
        if(cacheMap.find(key)==cacheMap.end())
            return -1;
            
        //remove the node
        Node* node=cacheMap[key];
        remove(node);
        add(node);
        return node->value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        Node* new_node=new Node(key,value);
        if(cacheMap.find(key)!=cacheMap.end())
        {
            Node* node=cacheMap[key];
            remove(node);
            node->value=value;
            add(node);
        }
        else
        {
            if(cacheMap.size()>=capacity)
            {
                Node* temp=tail->prev;
                remove(temp);
                cacheMap.erase(temp->key);
                delete temp;
            }
            add(new_node);
            cacheMap[key]=new_node;
        }
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends