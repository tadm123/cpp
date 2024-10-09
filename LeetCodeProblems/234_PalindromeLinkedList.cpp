/* 
Palindrome Linked List:
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    ListNode* fast, *slow;      //using two pointers
    fast = slow = head;     //both will start pointing at head

    /* Find middle (slow pointer) */
    while (fast != nullptr && fast->next != nullptr) //while fast is at the last node or it has reached null
    {
        //Fast pointer shifted twice
        fast = fast->next->next;

        //Slow pointer shifted once
        slow = slow->next;
    }

    /* Reverse second half of the list */
    ListNode* prev = nullptr;

    while (slow != nullptr)
    {
        ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;        //prev is one behind slow, so it'll stop when its at last node, or when slow is at null
        slow = temp;        //next node
    }

    /* Now check if it's Palindrome */
    ListNode *left = head;
    ListNode *right = prev;

    while (right != nullptr)
    {
        if (left->val != right->val)
            return false;

        left = left->next;
        right = right->next;
    }

    return true;
    }
};
