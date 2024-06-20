class Solution {
public:
    bool canPlaceBalls(int distance, vector<int>& positions, int m) {
        int count = 1;
        int last_position = positions[0];

        for (int i = 1; i < positions.size(); ++i) {
            if (positions[i] - last_position >= distance) {
                count++;
                last_position = positions[i];
            }
            if (count == m) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& positions, int m) {
        sort(positions.begin(), positions.end());

        int left = 1;
        int right = positions.back() - positions[0];
        int max_dist = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canPlaceBalls(mid, positions, m)) {
                max_dist = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return max_dist;
    }
};
