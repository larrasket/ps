﻿#define DEBUG
using System;
using System.Diagnostics;

public class Myclass
{
    [Conditional("DEBUG")]

    public static void Message(string msg)
    {
        Console.WriteLine(msg);
    }
}
class Test
{
    static void function1()
    {
        Myclass.Message("In Function 1.");
        function2();
    }
    static void function2()
    {
        Myclass.Message("In Function 2.");
    }
    public static void Main()
    {
        string[] words = new string[] { "Hello", "Wonderful", "Linq", "Beatiful", "World" };
        var shortWords =
            from word in words
            where word.Length <= 5
            select word;
        foreach (var word in shortWords) Console.WriteLine(word);
    }
}
