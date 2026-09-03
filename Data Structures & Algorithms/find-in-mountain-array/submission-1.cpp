/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length() - 1;

        int x = 0;

        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (mountainArr.get(m) > mountainArr.get(m - 1) && mountainArr.get(m) < mountainArr.get(m + 1)) {
                l = m + 1;
            } else if (mountainArr.get(m) < mountainArr.get(m - 1) && mountainArr.get(m) > mountainArr.get(m + 1)) {
                r = m - 1;
            } else if (mountainArr.get(m) > mountainArr.get(m - 1) && mountainArr.get(m) > mountainArr.get(m + 1)) {
                x = m;
                break;
            }
        }

        l = 0; r = x;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (mountainArr.get(m) > target) {
                r = m - 1;
            } else if (mountainArr.get(m) < target) {
                l = m + 1;
            } else if (mountainArr.get(m) == target){
                return m;
            }
        }

        l = x; r = mountainArr.length() - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (mountainArr.get(m) < target) {
                r = m - 1;
            } else if (mountainArr.get(m) > target) {
                l = m + 1;
            } else if (mountainArr.get(m) == target) {
                return m;
            }
        }

        return -1;
    }
};