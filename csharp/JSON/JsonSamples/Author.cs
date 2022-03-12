using System;
using System.Collections.Generic;
using Newtonsoft.Json;

// ReSharper disable InconsistentNaming

namespace JsonSamples
{
    [JsonObject(IsReference = true)]
    public class Author
    {
        public string name { get; set; }
        public List<string> courses = new List<string> {"12", "315"};
        public DateTime since { get; set; }
        public bool happy { get; set; }
        public object issues { get; set; }
        public Car car { get; set; }
        public List<Author> favoriteAuthors { get; set; }
        public AuthorRelationship authorRelationship { get; set; }
    }

    public enum AuthorRelationship
    {
        EmployeeAuthor,
        IndependentAuthor
    }
}