using System.ComponentModel.DataAnnotations;

namespace Books;

public class Book
{
    [Key] public int Id { get; set; }
    public string Title { get; set; }
    public string Description { get; set; }
    public DateTime PublishedOn { get; set; }
    public Decimal Price { get; set; }

    public string ImageUrl { get; set; }

    // relationships 
    public ICollection<Review> Reviews { get; set; }
    public ICollection<Tag> Tags { get; set; }
    public Author BookAuthor { get; set; }

    public int? fo { get; set; }
}