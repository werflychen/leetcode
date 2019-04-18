/*
 * 经典的二分搜索的变种问题：在一个有序数组中，找最后一个小于等于X的数。参考二分搜索变种的总结问题和算法(参考github路径：algorithm/search/binary_search.cpp)
 * 
 */
class Solution {
public:
    
    int BinarySearch(int x) {
        int left = 1;
        int right = x;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
            
        }
        
        return right;
    }
    
    int mySqrt(int x) {
        if (0 == x) {
            return 0;
        }
        
        int target = BinarySearch(x); 
        return target;
    }
};
