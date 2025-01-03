public class Solution
{
    public bool ContainsDuplicate(int[] nums)
    {
        var d = new Dictionary<int, bool>();
        foreach (int i in nums)
        {
            var o = false;
            d.TryGetValue(i, out o);
            if (o)
                return o;
            d.Add(i, true);
        }
        return false;
    }
}
