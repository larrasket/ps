using Microsoft.EntityFrameworkCore;

namespace Books;

public class AppContext : DbContext
{
    public DbSet<Book> Books { get; set; }
    public DbSet<Author> Authors { get; set; }
    public DbSet<Review> Reviews { get; set; }
    public DbSet<Tag> Tags { get; set; }

protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        const string v = "Server=localhost; Port=5432; Database=books; Username=postgres;";
        optionsBuilder.UseNpgsql(v);
    }
}