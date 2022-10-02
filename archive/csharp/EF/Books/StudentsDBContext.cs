using Microsoft.EntityFrameworkCore;

namespace Books;

public class StudentsDbContext : DbContext
{
    public DbSet<Student> Students { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        const string v = "Server=localhost; Port=5432; Database=students; Username=postgres;";
        optionsBuilder.UseNpgsql(v);
    }
}