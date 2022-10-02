using System.Collections.Generic;

namespace dummycommerce.Models
{
    public static class Jobs
    {
        public static List<string> JobsList { get; private set; }

        static Jobs()
        {
            JobsList = new()
            {
                "Translator",
                "Dancer",
                "Doctor"
            };
        }
    }
}