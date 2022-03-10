using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata;

namespace Reversing
{
    public partial class booksContext : DbContext
    {
        public booksContext()
        {
        }

        public booksContext(DbContextOptions<booksContext> options)
            : base(options)
        {
        }

        public virtual DbSet<Author> Authors { get; set; } = null!;
        public virtual DbSet<Book> Books { get; set; } = null!;
        public virtual DbSet<Review> Reviews { get; set; } = null!;
        public virtual DbSet<Tag> Tags { get; set; } = null!;

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see http://go.microsoft.com/fwlink/?LinkId=723263.
                optionsBuilder.UseNpgsql("Server=localhost; Port=5432; Database=books; Username=postgres;");
            }
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Author>(entity =>
            {
                entity.Property(e => e.Id).HasColumnName("_id");
            });

            modelBuilder.Entity<Book>(entity =>
            {
                entity.HasIndex(e => e.BookAuthorId, "IX_Books_BookAuthor_id");

                entity.Property(e => e.BookAuthorId).HasColumnName("BookAuthor_id");

                entity.Property(e => e.Fo).HasColumnName("fo");

                entity.HasOne(d => d.BookAuthor)
                    .WithMany(p => p.Books)
                    .HasForeignKey(d => d.BookAuthorId);
            });

            modelBuilder.Entity<Review>(entity =>
            {
                entity.HasIndex(e => e.BookId, "IX_Reviews_BookId");

                entity.HasOne(d => d.Book)
                    .WithMany(p => p.Reviews)
                    .HasForeignKey(d => d.BookId);
            });

            modelBuilder.Entity<Tag>(entity =>
            {
                entity.HasKey(e => e.Tag1);

                entity.Property(e => e.Tag1).HasColumnName("tag");

                entity.HasMany(d => d.Books)
                    .WithMany(p => p.Tagstags)
                    .UsingEntity<Dictionary<string, object>>(
                        "BookTag",
                        l => l.HasOne<Book>().WithMany().HasForeignKey("BooksId"),
                        r => r.HasOne<Tag>().WithMany().HasForeignKey("Tagstag"),
                        j =>
                        {
                            j.HasKey("Tagstag", "BooksId");

                            j.ToTable("BookTag");

                            j.HasIndex(new[] { "BooksId" }, "IX_BookTag_booksId");

                            j.IndexerProperty<int>("BooksId").HasColumnName("booksId");
                        });
            });

            OnModelCreatingPartial(modelBuilder);
        }

        partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
    }
}
