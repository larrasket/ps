using System;
using System.Collections.Generic;

namespace Reversing
{
    public partial class Tag
    {
        public Tag()
        {
            Books = new HashSet<Book>();
        }

        public string Tag1 { get; set; } = null!;

        public virtual ICollection<Book> Books { get; set; }
    }
}
