class program
{
    public static string ValidIPAddress(string queryIP)
    {
        if (IsIPV4(queryIP)) return "IPv4";
        if (IsIPV6(queryIP)) return "IPv6";
        return "Neither";
    }

    private static bool IsIPV6(string queryIp)
    {
        var values = queryIp.Split(':');
        if (values.Length != 8) return false;
        foreach (var value in values)
        {
            if (value.Length > 4 || string.IsNullOrEmpty(value)) return false;
            if (value.Any(x => char.IsLetter(x) && (char.ToLower(x) < 97 || char.ToLower(x) > 102)))
                return false;
        }

        return true;
    }

    private static bool IsIPV4(string queryIp)
    {
        var values = queryIp.Split('.');
        if (values.Length != 4) return false;
        foreach (var value in values)
        {
            try
            {
                int i = int.Parse(value);
                if ((value.Length > 1 && value.ElementAt(0) == '0') || i > 255) return false;
            }
            catch (Exception)
            {
                return false;
            }
        }

        return true;
    }

}
