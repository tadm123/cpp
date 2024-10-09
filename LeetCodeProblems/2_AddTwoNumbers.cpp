/*
Add Two Numbers:
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)     //l1 = 2 4 3 , l2 = 5 6 4
    {
        ListNode* dummy = new ListNode();   
        ListNode* cur = dummy;      //pointer
        int v1,v2, val;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)  //while either l1 or l2 still has a digit, meaning if any of them are not NULL or if carry still has a digit
        {
            if (l1 != nullptr)
                v1 = l1->val;
            else                    //if some digt is null
                v1 = 0;

            if (l2 != nullptr)
                v2 = l2->val;
            else                    //if some digt is null
                v2 = 0;

            // new digit to add into new linked list.
            val = v1 + v2 + carry;

            //If val, which is the sum between two digits ends up being 15
            carry = val / 10;               // 15 / 10 = 1
            val = val % 10;                 // 15 % 10 = 5

            //create a new node with the computed value using 
            cur->next = new ListNode(val);

            //go to next node
            cur = cur->next;

            if (l1 != nullptr)
                l1 = l1->next;

            if (l2 != nullptr)
                l2 = l2->next;
        }
        
        return dummy->next;
    }

};
