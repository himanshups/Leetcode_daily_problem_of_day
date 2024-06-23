class Solution {
public:
    typedef pair<int, int> ElementIndexPair;

    int longestSubarray(vector<int>& nums, int limit) {
        int arraySize = nums.size(); // Get the size of the input array
        priority_queue<ElementIndexPair> maxHeap; // Max-heap to track the maximum element in the current window
        priority_queue<ElementIndexPair, vector<ElementIndexPair>, greater<ElementIndexPair>> minHeap; // Min-heap to track the minimum element in the current window

        int leftPointer = 0; // Left boundary of the current window
        int rightPointer = 0; // Right boundary of the current window
        int longestLength = 0; // Variable to store the length of the longest valid subarray

        // Iterate through the array using the right pointer
        while (rightPointer < arraySize) {
            // Add the current element and its index to both heaps
            maxHeap.push({nums[rightPointer], rightPointer});
            minHeap.push({nums[rightPointer], rightPointer});

            // Check if the current window is valid
            while (maxHeap.top().first - minHeap.top().first > limit) {
                // If not valid, move the left pointer to the right of the smaller index of the top elements of the heaps
                leftPointer = min(maxHeap.top().second, minHeap.top().second) + 1;

                // Remove elements from the heaps that are out of the bounds of the current window
                while (maxHeap.top().second < leftPointer) {
                    maxHeap.pop();
                }
                while (minHeap.top().second < leftPointer) {
                    minHeap.pop();
                }
            }

            // Update the longest length with the length of the current valid window
            longestLength = max(longestLength, rightPointer - leftPointer + 1);
            rightPointer++; // Move the right pointer to the next element
        }

        return longestLength; // Return the length of the longest valid subarray found
    }
};
