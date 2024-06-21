class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
            int n = customers.size();
    int currentUnsatisfied = 0;

    // Calculate initial unsatisfied customers in the first 'minutes' window
    for (int i = 0; i < minutes; i++) {
        currentUnsatisfied += customers[i] * grumpy[i];
    }

    int maxUnsatisfied = currentUnsatisfied;

    // Use sliding window technique to find the maximum unsatisfied customers in any 'minutes' window
    for (int start = 0, end = minutes; end < n; start++, end++) {
        currentUnsatisfied += customers[end] * grumpy[end];   // Include the new element in the window
        currentUnsatisfied -= customers[start] * grumpy[start]; // Exclude the old element from the window
        
        maxUnsatisfied = max(maxUnsatisfied, currentUnsatisfied); // Update maxUnsatisfied if current window has more unsatisfied customers
    }

    int totalSatisfiedCustomers = 0;

    // Calculate total satisfied customers without any special technique
    for (int i = 0; i < n; i++) {
        totalSatisfiedCustomers += customers[i] * (1 - grumpy[i]);
    }

    // Add the maximum unsatisfied customers that can be converted to satisfied by using the special technique
    totalSatisfiedCustomers += maxUnsatisfied;

    return totalSatisfiedCustomers;
    }
};
