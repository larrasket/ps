using System;
using System.Linq;
class Solution
{
    public string ReverseWords(string s)
    {
        return String.Join(" ", s.Split(" ").Reverse().Where(x => !string.IsNullOrEmpty(x)));
    }
}
