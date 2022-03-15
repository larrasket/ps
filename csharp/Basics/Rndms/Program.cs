namespace delegates
{
    public delegate void IPChanged((string, string) l);
}


namespace net
{
    public class ip
    {
        public string address;
        public event delegates.IPChanged? OnChange;
        public ip() => address = "";
        public ip(params int[] s) => address = String.Join(".", s);

        public (string, string) ChengeIP(params int[] NewIP)
        {
            string temp = address;
            address = String.Join(".", NewIP);
            var change = (temp, address);
            if (OnChange != null) OnChange(change);
            return change;
        }
    }
}

namespace MainClass
{
    internal class Program
    {
        public static void Main()
        {
            var ThisUser = new net.ip(11, 2, 3, 41, 55);
            int i = 10;
            ThisUser.OnChange += AlertChange;
            ThisUser.OnChange += HereAnotherFunction;
            ThisUser.ChengeIP(11, 22, 44, 15, 16);
            Console.WriteLine("All is done!");
            int b = i;
        }

        private static void HereAnotherFunction((string, string) l)
        {
            Console.WriteLine("Events are nice!");
        }

        static void AlertChange((string, string) Changes)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("IMPORTANT!!");
            Console.WriteLine("IP IS CHANGED");
            Console.WriteLine("------------------");
            Console.WriteLine($"OLD IP : {Changes.Item1}");
            Console.WriteLine($"NEW IP : {Changes.Item2}");
            Console.ForegroundColor = ConsoleColor.White;
        }

        public static void HereAnotherFunction()
        {
            Console.WriteLine("Events are nice!");
        }

        struct ko
        {
            public int i;
            private int k;
        };
    }
}