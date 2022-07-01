public class Solution {
    public string SortSentence(string s) {
                var ss = s.Split(' ').OrderBy(x => x[^1]).Select(x => x.Replace(x[^1].ToString(), string.Empty));
        return string.Join(" ", ss.ToArray());

    }
}
