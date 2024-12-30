#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node *next;
    int data;
};


class LinkedList{
    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value){
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
    void print(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    
public:
    Node *head, *tail;
};

void solve(LinkedList& num1, LinkedList& num2){
    Node* n1=num1.head;
    Node* n2=num2.head;
    
    vector<int> res;
    
    int carryOne=0;
    
    while(n1 && n2)
    {
        int curr=n1->data + n2->data + carryOne;
        
        int digit = curr%10;
        carryOne=curr/10;
        
        res.push_back(digit);
        n1=n1->next;
        n2=n2->next;
    }
    
    
    while(n1)
    {
        int curr=n1->data + carryOne;
        
        int digit = curr%10;
        carryOne=curr/10;
        
        res.push_back(digit);
        n1=n1->next;
    }
    
     while(n2)
    {
        int curr=n2->data + carryOne;
        
        int digit = curr%10;
        carryOne=curr/10;
        
         res.push_back(digit);
         n2=n2->next;
    }
    
    if(carryOne)
    {
        res.push_back(carryOne);
    }
    
    int n = res.size()-1;
    
    for(int i = n; i>=0; i--)
    {
        cout<<res[i];
    }
}

int main(){
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for(int i = 0 ; i < size1 ; i++){
        int digit;
        cin >> digit;
        num1.add(digit);
    }
    
    cin >> size2;
    for(int i = 0 ; i < size2 ; i++){
        int digit;
        cin >> digit;
        num2.add(digit);
    }
  
    solve(num1, num2);
}
