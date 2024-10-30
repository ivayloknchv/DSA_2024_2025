// https://www.hackerrank.com/contests/sda-2024-2025-hw03/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem

/*
 * Complete the 'removeDuplicates' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
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

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) 
{
    if(!llist)
    {
        return nullptr;
    }
    
    SinglyLinkedListNode* ans=nullptr;
    SinglyLinkedListNode* prev=nullptr;
    while(llist)
    {
        int currentData=llist->data;
        SinglyLinkedListNode* currentNode= new SinglyLinkedListNode(currentData);
        
        while(llist && llist->data==currentData)
        {
            llist=llist->next;
        }
        
        if(!ans)
        {
            ans=currentNode;
            prev=currentNode;
            continue;
        }
        
        prev->next=currentNode;
        prev=prev->next;
    }
    return ans;
    
}
