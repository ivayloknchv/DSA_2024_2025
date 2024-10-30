
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
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* node1, SinglyLinkedListNode* node2) {
    if (!node1 && !node2)
    {
        return nullptr;
    }
    else if (!node1)
    {
        return node2;
    }
    else if (!node2)
    {
        return node1;
    }

    SinglyLinkedListNode* ans = nullptr;
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* current = nullptr;

    while (node1 && node2)
    {
        if (node1->data <= node2->data)
        {
            current = new SinglyLinkedListNode(node1->data);
            node1=node1->next;
        }
        else
        {
            current = new SinglyLinkedListNode(node2->data);
            node2 = node2->next;
        }

        if (!ans)
        {
            ans = current;
            prev = current;
        }
        else
        {
            prev->next = current;
            prev = prev->next;
        }
    }

    while (node1)
    {
        current = new SinglyLinkedListNode(node1->data);
        node1=node1->next;

        prev->next = current;
        prev = prev->next;
    }

    while (node2)
    {
        current = new SinglyLinkedListNode(node2->data);
        node2=node2->next;

        prev->next = current;
        prev = prev->next;
    }
    return ans;

}
