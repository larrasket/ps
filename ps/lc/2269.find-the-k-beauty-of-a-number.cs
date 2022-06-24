public class Solution {
public int DivisorSubstrings(int num, int k) {

        int count = 0, i = 0;
        string numText = num.ToString();

        while(i + k <= numText.Length)
        {
            int divisor = int.Parse(numText.Substring(i, k));

            if(divisor > 0 && num % divisor == 0)
                count++;

            i++;
        }

        return count;
    }

}
