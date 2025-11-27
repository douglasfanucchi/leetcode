#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) { // Time: O(nlogn) | Space: (n)
    vector<vector<int>> ans;
    bool merged;

    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    });

    for(int i = 0; i < intervals.size(); i++) {
        if (i < intervals.size() - 1 && intervals[i][1] >= intervals[i + 1][0]) {
            intervals[i + 1][0] = intervals[i][0];
            intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
        } else {
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}
