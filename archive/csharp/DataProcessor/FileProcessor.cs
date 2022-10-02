using static System.Console;

// ReSharper disable MemberCanBePrivate.Global

// ReSharper disable CheckNamespace
#pragma warning disable CS8602

namespace DataProcessor;

class FileProcessor
{
    private static string _backUpDir = "Backup";
    private static string _processingDir = "Processing";
    private static string _resultDir = "Result";

    private readonly List<string> _pathsToCreat = new()
    {
        _backUpDir,
        _processingDir,
        _resultDir
    };

    public readonly Dictionary<string, string> UtilityPaths;
    public string InputFilePath { get; }

    public FileProcessor(string filePath)
    {
        InputFilePath = filePath;
        UtilityPaths = new();
    }

    public void Process()
    {
        WriteLine($"Begin process of {InputFilePath}");
        if (!File.Exists(InputFilePath))
            throw new FileNotFoundException("Couldn't find input file at", InputFilePath);
        WriteLine("File is found successfully.");
        var info = new DirectoryInfo(InputFilePath);
        var rootDirectoryPath = (info.Parent.Parent.Exists) ? info.Parent.Parent.FullName : info.Parent.FullName;
        WriteLine("Found root at " + rootDirectoryPath);
        foreach (var ut in _pathsToCreat)
        {
            var newDir = Path.Combine(rootDirectoryPath, ut);
            if (!Directory.Exists(newDir))
            {
                Directory.CreateDirectory(newDir);
                WriteLine(ut + " directory is created");
            }
            else WriteLine(ut + " directory already exists");

            UtilityPaths.Add(ut,
                Path.Combine(newDir, Path.GetFileNameWithoutExtension(InputFilePath) +  "-" +  Guid.NewGuid() + 
                    "." +  ut));
        }

        BackUpFile();
        // Move to process dic
        if (!File.Exists(UtilityPaths[_processingDir]))
            File.Move(InputFilePath, UtilityPaths[_processingDir]);
        else WriteLine("Processing file already exist.");
    }

    private void BackUpFile()
    {
        if (File.Exists(UtilityPaths[_backUpDir])) WriteLine("Updating existing path...");
        WriteLine("Created a new backup at " + UtilityPaths[_backUpDir]);
        File.Copy(InputFilePath, UtilityPaths[_backUpDir], true);
    }
}