class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end());
        int l, r, ans = 0;
        for(int i = 0; i < points.size(); i++) {
        	l = points[i].first;
        	r = points[i].second;
        	ans++;
        	while(i + 1 < points.size() && points[i + 1].first >= l && points[i + 1].first <= r) {
        		i++;
        		l = max(l, points[i].first);
        		r = min(r, points[i].second);
        	}
        }
        return ans;
    }
};