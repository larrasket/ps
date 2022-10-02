using System.ComponentModel.DataAnnotations;

namespace Books;

public class Author
{
    [Key] public int _id { get; set; }
    public string Name { get; set; }
    public string Url { get; set; }
}