namespace Books;

public static class Program
{
    private static void Main()
    {
        var x = new AppContext();
        Author kh = new Author()
        {
            Url = "WQW",
            Name = "Khaled"
        };
        Book o = new Book
        {
            BookAuthor = kh,
            Title = "Book tt",
            Description = "Sblanga",
            PublishedOn = DateTime.UtcNow
        };
        Tag thistag = new Tag()
        {
            tag = "Mathematics",
            books = new List<Book> {o}
        };


        x.Database.EnsureDeleted();
        x.Database.EnsureCreated();
        x.Add(o);
        x.SaveChanges();
    }
}