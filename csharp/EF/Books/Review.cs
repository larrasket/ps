using System.ComponentModel.DataAnnotations;

namespace Books;

public class Review
{
    [Key] public int ReviewId { get; set; }
    public string WriterName { get; set; }
    public string ReviewText { get; set; }
}