public class Solution {
    public bool IsPalindrome(int x)
    {
        return new string(x.ToString().Reverse().ToArray()) == x.ToString();

    }

}
