public class Solution
{
    private static int swaping(string n)
    {
        var odd = n.Where(x => int.Parse(x.ToString()) % 2 != 0).Select(x =>
        int.Parse(x.ToString())).OrderBy(x => x).ToList(); var even = n.Where(x =>
        int.Parse(x.ToString()) % 2 == 0).Select(x => int.Parse(x.ToString())).OrderBy(x =>
        x).ToList();
        var r = new StringBuilder();
        foreach (var c in n)
        {
            if (int.Parse(c.ToString()) % 2 == 0)
            {
                int i = even.Count - 1;
                r.Append(even[i]);
                even.RemoveAt(i);
            }
            else
            {
                int i = odd.Count - 1;
                r.Append(odd[i]);
                odd.RemoveAt(i);
            }
        }
        return int.Parse(r.ToString());
    }
    public int LargestInteger(int num)
    {
        var s = num.ToString();
        return swaping(s);
    }
}
