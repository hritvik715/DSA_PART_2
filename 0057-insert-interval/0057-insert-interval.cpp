class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
          std::vector<std::vector<int>> result;
        int i = 0;
        const int n = intervals.size();

        // Phase 1: Add all intervals that end before the newInterval starts.
        // These intervals do not overlap and are placed first.
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Phase 2: Merge overlapping intervals.
        // An interval overlaps if it starts before the newInterval ends.
        // We expand newInterval to encompass all such overlapping intervals.
        while (i < n && intervals[i][0] <= newInterval[1]) {
            // Merge by taking the minimum start and maximum end.
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        // After the loop, newInterval is the fully merged interval. Add it.
        result.push_back(newInterval);

        // Phase 3: Add all remaining intervals.
        // These intervals start after the newInterval ends and do not overlap.
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};