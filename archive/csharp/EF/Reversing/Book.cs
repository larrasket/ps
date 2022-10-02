namespace Reversing
{
    public partial class Book
    {
        public Book()
        {
            Reviews = new HashSet<Review>();
            Tagstags = new HashSet<Tag>();
        }

        public int Id { get; set; }
        public string Title { get; set; } = null!;
        public string Description { get; set; } = null!;
        public DateTime PublishedOn { get; set; }
        public decimal Price { get; set; }
        public string ImageUrl { get; set; } = null!;
        public int BookAuthorId { get; set; }
        public int? Fo { get; set; }

        public virtual Author BookAuthor { get; set; } = null!;
        public virtual ICollection<Review> Reviews { get; set; }

        public virtual ICollection<Tag> Tagstags { get; set; }
    }
}
