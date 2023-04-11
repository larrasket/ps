public class Solution

{
   
    public string MinimizeResult(string expression)
    {
        var map = new Dictionary<string, int>();
        string[] exps = expression.Split("+");
       

        for (int i = 0; i < exps[0].Length; i++)
        {
            int aAdd = int.Parse(exps[0].Substring(i));
            string aMultStr = exps[0].Substring(0, i)
           ;
            int aMult = aMultStr.Length == 0 ? 1 : int.Parse(aMultStr);

            for (int j = 1; j <= exps[1].Length; j++)
            {
                int bAdd = int.Parse(exps[1].Substring(0, j));
                string bMultStr = exps[1].Substring(j);
                int bMult = bMultStr.Length == 0 ? 1 : int.Parse(bMultStr);

                string key = aMultStr + "(" + aAdd + "+" + bAdd + ")" + bMultStr;
                map[key] = aAdd + bAdd;
                map[key] *= aMult;
                map[key] *= bMult;
            }
        }

        return map.MinBy(r => r.Value).Key;
    }
}
