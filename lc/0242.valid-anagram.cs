public class Solution
{
    public bool IsAnagram(string s, string t)
    {
        if (s.Length != t.Length)
            return false;
        var d = new Dictionary<Char, int>();

        for (int i = 0; i < s.Length; i++)
        {
            d.TryAdd(s[i], 0);
            d.TryAdd(t[i], 0);
            d[s[i]]++;
            d[t[i]]--;
        }
        foreach ((_, int i) in d)
        {
            if (i != 0)
            {
                return false;
            }
        }
        return true;
    }
}
