#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    
    int getSize()
    {
        if(!head)
        {
            return 0;
        }
        
        int size=0;
        
        Node* iter=head;
        
        while(iter)
        {
            size++;
            iter=iter->next;
        }
        
        return size;
    }
    void reverse(int from, int to) 
    {
        
        if(!head)
        {
            return;
        }
        
        int size=getSize();
        
        if(from>size)
        {
            return;
        }
        
        to=min(size, to);
        
        vector<int> vals;
        
        Node* iter=head; 
        int counter=1;
        
        while(iter)
        {
            if(counter>=from && counter<=to)
            {
                vals.push_back(iter->data);
            }
            counter++;
            iter=iter->next;
        }
        
        
        for(int i = 0; i < vals.size()/2; i++)
        {
            swap(vals[i], vals[vals.size()-i-1]);
        }
        
        iter=head;
        counter=1;
        int vals_iter=0;
        
        while(iter)
        {
            if(counter>=from && counter<=to)
            {
                iter->data=vals[vals_iter++];
            }
            counter++;
            iter=iter->next;
        }
    }

    void print() {
        Node* temp = head;
    
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    
        cout << endl;
    }

    ~List() {
        Node* curr = head;
        
        while(curr) {
            Node* prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;
        }
        
        delete curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    List testList;

    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {
        
        string op;
        cin >> op;
        
        if (op == "add") {
            int num;
            cin >> num;
            testList.add(num);
        }
            
        if (op == "print") {
            testList.print();
        }
            
        if (op == "reverse") {
            int from, to;
            cin >> from >> to;
            testList.reverse(from, to);
        }
    }
    
    return 0;
}
