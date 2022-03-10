namespace Books;

public static class Program
{
    public static string RandomString(int length)
    {
        const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        var random = new Random();
        return new string(Enumerable.Repeat(chars, length)
            .Select(s => s[random.Next(s.Length)]).ToArray());
    }

    private static void Main()
    {
        var x = new AppContext();
        Author kh = new Author()
        {
            Url = RandomString(4),
            Name = RandomString(4),
        };


        Tag thistag = new Tag()
        {
            tag = RandomString(4),
        };


        Review r = new Review()
        {
            WriterName = RandomString(9),
            ReviewText = RandomString(34)
        };

        Random rnd = new Random();
        Book o = new Book
        {
            Title = RandomString(4),
            Description = RandomString(4),
            PublishedOn = DateTime.UtcNow,
            Price = rnd.Next(1, 3),
            ImageUrl = RandomString(13),
            Reviews = new List<Review> {r},
            Tags = new List<Tag> {thistag},
            BookAuthor = kh,
        };
        thistag.books = new List<Book> {o};
        // x.Database.EnsureDeleted();
        // x.Database.EnsureCreated();
        x.Add(o);
        x.SaveChanges();
    }
}