#include <vector>
using namespace std;

bool belongsTo(int n, vector<int> interval) {
    return n >= interval[0] && n <= interval[1];
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) { // Time: O(n^2) | Space: (n)
    vector<vector<int>> ans;
    bool merged;

    for(int i = 0; i < intervals.size(); i++) {
        merged = false;
        for(int j = i + 1; j < intervals.size(); j++) {
            if (belongsTo(intervals[i][0], intervals[j]) && belongsTo(intervals[i][1], intervals[j])) {
                merged = true;
                break;
            }
            
            if (belongsTo(intervals[i][0], intervals[j])) {
                merged = true;
                intervals[j][1] = intervals[i][1];
                break;
            }
            
            if (belongsTo(intervals[i][1], intervals[j])) {
                merged = true;
                intervals[j][0] = intervals[i][0];
                break;
            }
        }
        if (!merged) {
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}
