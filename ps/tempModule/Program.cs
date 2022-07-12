using System.Text;

public class Solution

{

    public static int MinDistance(string word1, string word2)
    {
        var toDeleteChars = word1.Where(p => word2.All(x => x != p)).Select(r => r.ToString()).ToList();
        var toAddChars = word2.Where(p => word1.All(x => x != p)).Select(r => r.ToString()).ToList();
        int ans = 0, c = 0, l1 = word1.Length, l2 = word2.Length;
        if (toDeleteChars.Count != 0)
            while (l1 > l2)
            { // removing
                word1 = word1.ReplaceFirst(toDeleteChars[c], string.Empty);
                c++;
                l1--;
            }
        else
        {
            return l1 - l2 + toAddChars.Count;
        }
        for (int i = 0; i < toAddChars.Count; i++)
        {
            word1 = word1.ReplaceFirst(toDeleteChars[c].ToString(), toAddChars[i]);
            c++;
        }
        ans += c;
        if (word1 == word2) return ans;
        int t = 0;
        for (int i = 0; i < word2.Length; i++)
        {
            if (word1[i] == word2[i]) t++;
        }
        ans += (word2.Length - 1 - t);
        return ans;
    }

    public int[] Intersection(int[] nums1, int[] nums2)
    {
        return nums1.Where(x => nums2.Any(s => s == x)).Distinct().ToArray();
    }



    public static string SortSentence(string s)
    {
        var ss = s.Split(' ').OrderBy(x => x[^1]).Select(x => x.Replace(x[^1].ToString(), string.Empty));
        return string.Join(" ", ss.ToArray());
    }

    public char FindTheDifference(string s, string t)
    {
        var nt = String.Concat(t.OrderBy(x => x));
        var indx = nt.IndexOf(s);
        return t.Remove(indx, s.Length).First();
    }

    public string FirstPalindrome(string[] words)
    {
        var i = words.FirstOrDefault(x => new string(x.Reverse().ToArray()) == x);
        if (i is null) return "";
        return i;
    }



    public int DivisorSubstrings(int num, int k)
    {
        StringBuilder bldr = new();
        var snums = num.ToString();
        int n = snums.Length, s = 0; for (int l = 0, r = 0; r < n; r++)
        {
            bldr.Append(snums[r]);

        }
        return 0;
    }















    public static void Main()
    {
        SortSentence("is2 sentence4 This1 a3");
    }

}


public static class StringExtensionMethods
{
    public static string ReplaceFirst(this string text, string search, string replace)
    {
        int pos = text.IndexOf(search);
        if (pos < 0)
        {
            return text;
        }
        return text.Substring(0, pos) + replace + text.Substring(pos + search.Length);
    }
}
