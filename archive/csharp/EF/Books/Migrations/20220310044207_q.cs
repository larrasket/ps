using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace Books.Migrations
{
    public partial class q : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Authors",
                columns: table => new
                {
                    _id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Name = table.Column<string>(type: "text", nullable: false),
                    Url = table.Column<string>(type: "text", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Authors", x => x._id);
                });

            migrationBuilder.CreateTable(
                name: "Tags",
                columns: table => new
                {
                    tag = table.Column<string>(type: "text", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Tags", x => x.tag);
                });

            migrationBuilder.CreateTable(
                name: "Books",
                columns: table => new
                {
                    Id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Title = table.Column<string>(type: "text", nullable: false),
                    Description = table.Column<string>(type: "text", nullable: false),
                    PublishedOn = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    Price = table.Column<decimal>(type: "numeric", nullable: false),
                    ImageUrl = table.Column<string>(type: "text", nullable: false),
                    BookAuthor_id = table.Column<int>(type: "integer", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Books", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Books_Authors_BookAuthor_id",
                        column: x => x.BookAuthor_id,
                        principalTable: "Authors",
                        principalColumn: "_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "BookTag",
                columns: table => new
                {
                    Tagstag = table.Column<string>(type: "text", nullable: false),
                    booksId = table.Column<int>(type: "integer", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_BookTag", x => new { x.Tagstag, x.booksId });
                    table.ForeignKey(
                        name: "FK_BookTag_Books_booksId",
                        column: x => x.booksId,
                        principalTable: "Books",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_BookTag_Tags_Tagstag",
                        column: x => x.Tagstag,
                        principalTable: "Tags",
                        principalColumn: "tag",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Reviews",
                columns: table => new
                {
                    ReviewId = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    WriterName = table.Column<string>(type: "text", nullable: false),
                    ReviewText = table.Column<string>(type: "text", nullable: false),
                    BookId = table.Column<int>(type: "integer", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Reviews", x => x.ReviewId);
                    table.ForeignKey(
                        name: "FK_Reviews_Books_BookId",
                        column: x => x.BookId,
                        principalTable: "Books",
                        principalColumn: "Id");
                });

            migrationBuilder.CreateIndex(
                name: "IX_Books_BookAuthor_id",
                table: "Books",
                column: "BookAuthor_id");

            migrationBuilder.CreateIndex(
                name: "IX_BookTag_booksId",
                table: "BookTag",
                column: "booksId");

            migrationBuilder.CreateIndex(
                name: "IX_Reviews_BookId",
                table: "Reviews",
                column: "BookId");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "BookTag");

            migrationBuilder.DropTable(
                name: "Reviews");

            migrationBuilder.DropTable(
                name: "Tags");

            migrationBuilder.DropTable(
                name: "Books");

            migrationBuilder.DropTable(
                name: "Authors");
        }
    }
}
