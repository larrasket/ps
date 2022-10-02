namespace Reversing
{
    public partial class Review
    {
        public int ReviewId { get; set; }
        public string WriterName { get; set; } = null!;
        public string ReviewText { get; set; } = null!;
        public int? BookId { get; set; }

        public virtual Book? Book { get; set; }
    }
}
