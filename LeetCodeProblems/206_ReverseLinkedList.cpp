/* 
206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

    ListNode* reverseList(ListNode* head) 
    {
        ListNode *prev, *current, *next;
        current = head;
        prev = nullptr;

        //when we reach the last element
        while (current != nullptr)
        {
            next = current->next;
            current-> next = prev;       
            prev = current;
            current = next;        //goes to next node
        }

        head = prev;

        return head;
    }

    //using recursion
    ListNode* reverseList(ListNode* head) 
    {
        //if the list is empty (head == nullptr) or we reached the last node (head->next == nullptr)
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *newHead = reverseList(head->next);       //unfold back when it reaches last element
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
