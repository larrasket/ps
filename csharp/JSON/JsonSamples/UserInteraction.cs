using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JsonSamples
{
    public class UserInteraction
    {
        static List<string> courses = new List<string>() { "Solr", "Spark", "Python" };
        static Random randomGenerator = new Random();

        public string ip { get; set; }
        public string cookie { get; set; }
        public string userAgent { get; set; }
        public string acceptLanguage { get; set; }
        public CourseView courseView { get; set; }
        public StringBuilder privateImportantData { get; set; }
        public List<string> processedBy { get; set; }
        public bool reviewed { get; set; }
        public DateTime reviewedDate { get; set; }


        public void GenerateFakeLog()
        {
            ip = "192.168.1.1";
            cookie = "__ar_v4=4YCMENXFKFBQLNQCLOV3GS%3A20141026%3A2%7CNPTOMQSYYZABNNUIQDRAKL%3A20141026%3A2%7CBFLWHRV7W5FLTIZIQ4OSO6%3A20141026%3A2";
            userAgent = "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.89 Safari/537.36";
            acceptLanguage = "en-US,en;q=0.8,es;q=0.6";

            int generatedId = randomGenerator.Next(0, 10000);
            courseView = new CourseView()
            {
                userId = generatedId,
                user = "user_" + generatedId,
                course = courses[randomGenerator.Next(courses.Count())],
                watchedDate = new DateTime(2015, 07, randomGenerator.Next(1, 28)),
                secondsWatched = randomGenerator.Next(0, 1000)
            };

            privateImportantData = new StringBuilder();
            for (int i = 0; i < 1000; i++)
            {
                privateImportantData.Append((char)randomGenerator.Next(65, 90));
            }
        }
    }
}
