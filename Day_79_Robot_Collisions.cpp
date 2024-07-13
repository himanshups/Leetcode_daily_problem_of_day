class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions) {
        int n = positions.size();

        // Create a vector of tuples (position, health, index) for sorting
        vector<tuple<int, int, int>> robots(n);
        for (int i = 0; i < n; ++i) {
            int health = directions[i] == 'L' ? -healths[i] : healths[i];
            robots[i] = make_tuple(positions[i], health, i);
        }

        // Sort robots based on their positions
        sort(robots.begin(), robots.end());

        // Stack to keep track of surviving robots
        stack<pair<int, int>> st; // (health, index)

        for (int i = 0; i < n; ++i) {
            int currHealth = get<1>(robots[i]);
            int currIndex = get<2>(robots[i]);

            while (!st.empty()) {
                int topHealth = st.top().first;
                int topIndex = st.top().second;

                // Check if they are moving in the same direction or one is moving left and the other is moving right
                if ((topHealth > 0 && currHealth > 0) || (topHealth < 0 && currHealth < 0) || (topHealth < 0 && currHealth > 0)) {
                    break;
                }

                if (abs(topHealth) > abs(currHealth)) {
                    st.pop();
                    if (topHealth > 0) {
                        st.push({topHealth - 1, topIndex});
                    } else {
                        st.push({topHealth + 1, topIndex});
                    }
                } else if (abs(topHealth) == abs(currHealth)) {
                    st.pop();
                    currHealth = 0;
                    break;
                } else {
                    st.pop();
                    if (currHealth > 0) {
                        currHealth--;
                    } else {
                        currHealth++;
                    }
                }
            }

            if (currHealth != 0) {
                st.push({currHealth, currIndex});
            }
        }

        // Collect the results
        vector<pair<int, int>> survivedRobots;
        while (!st.empty()) {
            survivedRobots.push_back(st.top());
            st.pop();
        }
        sort(survivedRobots.begin(), survivedRobots.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });

        vector<int> result;
        for (const auto &robot : survivedRobots) {
            result.push_back(abs(robot.first));
        }
        return result;
    }
};
