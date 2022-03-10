using System;
using System.Collections.Generic;

namespace Reversing
{
    public partial class Author
    {
        public Author()
        {
            Books = new HashSet<Book>();
        }

        public int Id { get; set; }
        public string Name { get; set; } = null!;
        public string Url { get; set; } = null!;

        public virtual ICollection<Book> Books { get; set; }
    }
}
