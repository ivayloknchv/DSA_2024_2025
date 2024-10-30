// https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) 
{
    if(!head)
    {
        return false;
    }
    
    SinglyLinkedListNode* slow=head;
    SinglyLinkedListNode* fast=head;
    
    while(slow && fast && fast->next)
    {       
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast)
        {
            return true;
        }     
    }
    
    return false;
}
