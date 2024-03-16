//https://leetcode.com/problems/merge-k-sorted-lists/description/
class Solution {

    private static final int MAX_K = 10000 + 7;

    public ListNode mergeKLists(ListNode[] lists) {
        //Initialize variables
        int[] arr = new int[MAX_K];
        int ptr = 0;

        //Go through array
        for (ListNode node: lists) {
            //Flatten list
            while (node != null) {
                arr[ptr++] = node.val;
                node = node.next;
            }
        }

        //Check pointer
        if (ptr == 0) return null;

        //Sort node values
        Arrays.sort(arr, 0, ptr);

        //Initialize objects
        ListNode root = new ListNode(arr[0]), node = root;

        //Create sorted list
        for (int i = 1; i < ptr; i++) {
            node.next = new ListNode(arr[i]);
            node = node.next;
        }

        return root;
    }
}