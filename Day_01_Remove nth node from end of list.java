/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode fast_pointer = head;
        ListNode slow_pointer = head;

        //move fast pointer n nodes ahead
        for(int i = 0;i<n;i++)
            fast_pointer = fast_pointer.next;

        // if we delete first node , head is shifted to secnodn node
        if(fast_pointer == null) return head.next;

        //move fast pointer to the end of list and slow pointer just before the node we need to delete
        while(fast_pointer.next!=null){
            fast_pointer = fast_pointer.next;
            slow_pointer = slow_pointer.next;
        }
        ListNode delete_Node = slow_pointer.next;
        //storing next next node infromation in this list as next node is deleted
        slow_pointer.next = slow_pointer.next.next;
        delete_Node = null;
        return head;



    }
}
