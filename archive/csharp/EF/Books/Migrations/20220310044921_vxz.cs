using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Books.Migrations
{
    public partial class vxz : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "fo",
                table: "Books",
                type: "integer",
                nullable: true);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "fo",
                table: "Books");
        }
    }
}
