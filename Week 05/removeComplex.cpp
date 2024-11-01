#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-test2/challenges/--82/problem

struct Node {
    Node * next;
    int data;
    Node(Node* _next,int _data){
        next = _next;
        data = _data;
    }
};
class LinkedList{
    public:
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        Node* tmp;
        while(head!=NULL){
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void add(int number){
        Node *tmp = new Node(head,number);
        head = tmp;
    }
    void print(){
        Node* curr = head;
        while(curr!=NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    void removeComplex(int devidedBy)
    {  
        if(!head)
        {
            return;
        }
        
        while(head)
        {
            if(head->data % devidedBy == 0)
            {
                Node* toDelete=head;
                head=head->next;
                delete toDelete;
            }
            else
            {
                break;
            }
        }
        
        Node* curr = head;
        Node* prev = nullptr;
        
        while(curr)
        {
            if(curr->data % devidedBy == 0)
            {
                Node* toDelete = curr;
                prev->next=curr->next;
                curr=curr->next;
                delete toDelete;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        
    } // end removeComplex
    private:
    Node* head;
};
int main(){
    LinkedList l;

    int n;
    cin >> n;
    int number;
    for(int i = 0 ; i < n ; i++){
        cin >>number;
        l.add(number);
    }
    int devidedBy;
    cin >> devidedBy;
    l.removeComplex(devidedBy);
    l.print();
}
