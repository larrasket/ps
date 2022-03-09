using System.ComponentModel.DataAnnotations;

namespace Books;

public class Tag
{
    [Key] public string tag;
    public ICollection<Book> books;
}