public bool IsPalindrome(int x)
{
    if (0 > x) return false;
    return new string(x.ToString().Reverse().ToArray()) == x.ToString();
}
