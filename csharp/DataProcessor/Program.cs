using static System.Console;
// ReSharper disable UnusedParameter.Local
// ReSharper disable UnusedMember.Local
#pragma warning disable CS8604

// ReSharper disable CheckNamespace
namespace DataProcessor
{
    static class Program
    {
        private const string Value = "Parsing command line options";

        private static void Main(string?[] args)
        {
            WriteLine(Value);
            var command = args[0];
            if (command == "--file")
            {
                var filePath = args[1];
                while (!Path.IsPathFullyQualified(filePath))
                {
                    WriteLine("The path" + filePath + "is not fully qualified, please enter a qualified path.");
                    args[1] = (filePath = ReadLine());
                }

                FileProcessor myProcessor = new FileProcessor(filePath);
                myProcessor.Process();
            }
            else if (command == "--dir")
            {
                var directoryPath = args[1];
                var fileType = args[2];
                WriteLine($"Directory {directoryPath} selected for {fileType} files");
                ProcessDirectory(directoryPath, fileType);
            }
            else
            {
                WriteLine("Invalid command line options");
                WriteLine("Testing in windows....sucks");
            }
        }

        private static void ProcessSingleFile(string filePath)
        {
            var fileProcessor = new FileProcessor(filePath);
            fileProcessor.Process();
        }

        private static void ProcessDirectory(string? directoryPath, string? fileType)
        {
        }
    }
}