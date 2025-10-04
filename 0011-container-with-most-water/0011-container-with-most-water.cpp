class Solution {
public:
    int maxArea(vector<int>& height) {
         int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int current_area = std::min(height[left], height[right]) * (right - left);
            max_area = std::max(max_area, current_area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};