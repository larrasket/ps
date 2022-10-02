using System.ComponentModel.DataAnnotations;

namespace Books;

public class Student
{
    [Key] public int Id { get; set; }
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public string Gender { get; set; }
}