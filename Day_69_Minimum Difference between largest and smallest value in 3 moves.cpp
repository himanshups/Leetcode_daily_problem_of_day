class Solution {
public:
    int minDifference(vector<int>& elements) {
        sort(elements.begin(), elements.end());
        int size = elements.size();
        if (size <= 4) {
            return 0;
        }
        int minimumDifference = INT_MAX;
        minimumDifference = min(minimumDifference, elements[size - 4] - elements[0]);
        minimumDifference = min(minimumDifference, elements[size - 1] - elements[3]);
        minimumDifference = min(minimumDifference, elements[size - 3] - elements[1]);
        minimumDifference = min(minimumDifference, elements[size - 2] - elements[2]);

        return minimumDifference;
    }
};
