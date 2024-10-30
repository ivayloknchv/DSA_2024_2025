// https://www.hackerrank.com/contests/sda-hw-4-2022/challenges/delete-a-node-from-a-linked-list/problem

/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
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

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) 
{
    if(!llist)
    {
        return nullptr;
    }
    if(position==0)
    {
        return llist->next;
    }
    
    SinglyLinkedListNode* prev=nullptr;
    SinglyLinkedListNode* curr=llist;
    
    for(int i = 0; i<position; i++)
    {
        if(curr)
        {
            prev=curr;
            curr=curr->next;
        }
        else
        {
            return llist;
        }
    }
    
    prev->next=curr->next;
    
    return llist;
    
}
