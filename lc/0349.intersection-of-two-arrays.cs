public class Solution {
    public int[] Intersection(int[] nums1, int[] nums2) {
        return nums1.Where(x => nums2.Any(s => s == x)).Distinct().ToArray();

    }
}
