
//https://www.hackerrank.com/contests/sda-2024-2025-hw03/challenges/merge-two-sorted-linked-lists/problem

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    if (!head1 && !head2)
    {
        return nullptr;
    }
    else if (!head1)
    {
        return head2;
    }
    else if (!head2)
    {
        return head1;
    }

    SinglyLinkedListNode* ans = nullptr;
    SinglyLinkedListNode* current = nullptr;
    SinglyLinkedListNode* next = nullptr;

    if (head1->data <= head2->data)
    {
        ans = new SinglyLinkedListNode(head1->data);
        ans->next=nullptr;
        head1 = head1->next;
    }
    else
    {
        ans = new SinglyLinkedListNode({ head2->data});
        ans->next=nullptr;
        head2 = head2->next;
    }

    current = ans;

    while (head1 && head2)
    {
        next = nullptr;
        if (head1->data <= head2->data)
        {
            next = new SinglyLinkedListNode(head1->data);
            next->next=nullptr;
            head1 = head1->next;
        }
        else
        {
            next = new SinglyLinkedListNode(head2->data);
            next->next=nullptr;
            head2 = head2->next;
        }
        current->next = next;

        if (next)
        {
            current = current->next;
        }
        
    }

    while (head1)
    {
        next = new SinglyLinkedListNode(head1->data);
        next->next=nullptr;
        head1 = head1->next;

        current->next = next;

        if (next)
        {
            current = current->next;
        }
        
    }

    while (head2)
    {
        next = new SinglyLinkedListNode(head2->data);
        next->next=nullptr;
        head2 = head2->next;

        current->next = next;

        if (next)
        {
            current = current->next;
        }
    }

    return ans;
}
