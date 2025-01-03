public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        var d = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++)
        {
            var diff = target - nums[i];
            if (d.ContainsKey(diff))
            {
                return new int[] { i, d[diff] };
            }
            d.TryAdd(nums[i], i);
        }

        return new int[] { 0, 0 };
    }
}
