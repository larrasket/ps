using System.ComponentModel.DataAnnotations;

namespace Books;

public class Tag
{
    [Key] public string tag { get; set; }
    public ICollection<Book> books { get; set; }
}