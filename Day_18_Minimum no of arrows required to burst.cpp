class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int arrows = 1;
        int end = points[0][1];
        for(int i=0; i<points.size(); i++){
            if(points[i][0]>end){
                arrows++;
                end = points[i][1];
            }
        }
        return arrows;
    }
};
