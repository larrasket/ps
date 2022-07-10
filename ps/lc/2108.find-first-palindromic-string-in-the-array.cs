public class Solution

{
    public string FirstPalindrome(string[] words)
    {
        va r i = words.FirstOrDefault(x => new string(x.Reverse().ToArray()) == x);
        if (i is null) return "";
        return i;
    }
}
