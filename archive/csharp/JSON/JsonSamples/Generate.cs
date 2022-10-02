using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Data;
using System.Dynamic;
using System.IO;
using System.Linq;

namespace JsonSamples
{
    
    public static class Generate
    {

        /// <summary>
        /// Returns a single JSON document for tests
        /// </summary>
        /// <returns></returns>
        public static string SingleJson()
        {
            return File.ReadAllText("AuthorSingle.json");
        }

        public static string SingleJsonError()
        {
            return File.ReadAllText("AuthorSingleError.json");
        }

        public static string ExtendedSingleJson()
        {
            return File.ReadAllText("AuthorExtended.json");
        }

        public static string SmallJson()
        {
            return File.ReadAllText("AuthorSmall.json");
        }

        public static string DatesJson()
        {
            return File.ReadAllText("AuthorDates.json");
        }


        static List<string> courses = new List<string>() { "Solr", "dotTrace", "Jira" };
        static Random randomGenerator = new Random();

        public static List<CourseView> CourseViews(int numberOfViews)
        {
            List<CourseView> courseViews = new List<CourseView>();
            for (int i = 0; i < numberOfViews; i++)
            {
                int generatedId = randomGenerator.Next(9999, 100000);
                CourseView courseView = new CourseView()
                {
                    userId = generatedId,
                    user = "user_" + generatedId,
                    course = courses[randomGenerator.Next(courses.Count())],
                    watchedDate = new DateTime(2015, 07, randomGenerator.Next(1, 28)),
                    secondsWatched = randomGenerator.Next(0, 1000)
                };

                courseViews.Add(courseView);
            }

            return courseViews;
        }

        public static string CourseViewsString(int numberOfViews)
        {
            List<CourseView> courseViews = CourseViews(numberOfViews);

            dynamic result = new ExpandoObject();

            result.views = courseViews;

            return JsonConvert.SerializeObject(result, Formatting.Indented);

            //return JsonConvert.SerializeObject(courseViews, Formatting.Indented);
        }


        public static List<UserInteraction> UserInteractions(int numberOfInteractions)
        {
            List<UserInteraction> userLogs = new List<UserInteraction>();
            for (int i = 0; i < numberOfInteractions; i++)
            {
                UserInteraction uI = new UserInteraction();
                uI.GenerateFakeLog();
                userLogs.Add(uI);
            }
            return userLogs;
        }

        public static DataSet CoursesDataSet ()
        {
            DataSet dataSet = new DataSet("Courses");
            //dataSet.Namespace = "NetFrameWork";
            DataTable table = new DataTable();
            DataColumn idColumn = new DataColumn("id", typeof(int));
            idColumn.AutoIncrement = true;

            DataColumn itemColumn = new DataColumn("name", typeof(string));
            table.Columns.Add(idColumn);
            table.Columns.Add(itemColumn);
            dataSet.Tables.Add(table);

            string[] courses = new string[] { "Solr", "Spark", "Jira" };

            foreach (var course in courses)
            {
                DataRow newRow = table.NewRow();
                newRow["name"] = course;
                table.Rows.Add(newRow);
            }
            
            dataSet.AcceptChanges();

            return dataSet;
        }

    }
}
