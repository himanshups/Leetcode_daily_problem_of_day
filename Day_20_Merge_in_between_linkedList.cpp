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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode *prevA = nullptr, *cur1 = list1, *cur2 = list2;
        int count{};
        
        // Get the prev node to the ath node
        while(count < a)
        {
            prevA = cur1;
            cur1 = cur1->next;
            count++;
            
        }
        
        // Get the next node to the bth node
        // Remove list1 nodes from ath to bth
        while(count <= b)
        {
            ListNode *temp = cur1;
            cur1 = cur1->next;
            count++;
            delete temp;
        }
        
        // Get the end on list2
        while(cur2 && cur2->next)
            cur2 = cur2->next;
        
        // Merge the two lists
        prevA->next = list2;
        cur2->next = cur1;
        
        return list1;
    }
};
