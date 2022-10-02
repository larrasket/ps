using System.ComponentModel.DataAnnotations;

namespace dummycommerce.Models
{
    public class Employee
    {
        [Key] public int Id { get; set; }
        public string Name { get; set; }
        public string Job { get; set; }
        public bool Active { get; set; }
    }
}