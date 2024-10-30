// https://www.hackerrank.com/contests/sda-2024-2025-hw03/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) 
{
    if(!llist && position!=0)
    {
        return nullptr;
    }
    else if(!llist && position == 0)
    {
        return new SinglyLinkedListNode(data);
    }
    if(position==0)
    {
        SinglyLinkedListNode* ans=new SinglyLinkedListNode(data);
        ans->next=llist;
        return ans;
    }
    
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* prev = nullptr;
    
    for(int i = 0; i<position; i++)
    {
        if(current)
        {
            prev=current;
            current=current->next;
        }
        else
        {
            return llist;
        }
    }
    
    prev->next=new SinglyLinkedListNode(data);
    prev->next->next=current;
    
    return llist;
}
