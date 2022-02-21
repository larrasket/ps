using System;
using System.Reflection;

namespace Lists
{
    internal class Program
    {
        public static void Main(string[] args)
        {
        Console.WriteLine("Assembly Metadata");
        var assembly = Assembly.GetEntryAssembly();
        Console.WriteLine("Location" + assembly.Location);
        }
    }
}