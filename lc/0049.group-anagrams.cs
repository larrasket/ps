public class Solution
{
    public List<List<string>> GroupAnagrams(string[] strs)
    {
        Dictionary<int[], List<string>> d = new();
        foreach (var s in strs)
        {
            var c = new int[26];
            for (int i = 0; i < s.Length; i++)
            {
                c[s[i] - 'a']++;
            }
            if (!d.ContainsKey(c))
            {
                d.Add(c, new List<string>());
            }
            d[c].Add(s);
        }
        return d.Values.ToList();
    }
}
