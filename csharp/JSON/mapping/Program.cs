// ReSharper disable RedundantUsingDirective

using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.IO;
using Newtonsoft.Json;
using JsonSamples;

// ReSharper disable UnusedMember.Local
// ReSharper disable InconsistentNaming
// ReSharper disable All

namespace mapping
{
    internal static class Program
    {
        public static string smpl = Generate.SingleJson();

        public static void Main()
        {
            textreader();
        }

        public static void textreader()
        {
            JsonTextReader rdr = new JsonTextReader(new StringReader(smpl));
            while (rdr.Read())
            {
                if (rdr.Value != null)
                {
                    Console.WriteLine("Token: " +  rdr.TokenType + " Value: ", rdr.Value);
                } else
                    Console.WriteLine("Token: " + rdr.TokenType);
            }
        }

        public static void jsonserlizer(string[] args)
        {
            using (StreamWriter sw = new StreamWriter("./testingjsonfile.json"))
            {
                string json = Generate.SingleJson();
                JsonSerializer fsz = new JsonSerializer();
                fsz.Serialize(sw, json);
            }
        }

        public static void BasicSerialization()
        {
            string json = Generate.SingleJson();
            // Console.WriteLine(json);
            Author x = JsonConvert.DeserializeObject<Author>(json);
            // Console.WriteLine(x.name);
            string y = JsonConvert.SerializeObject(x, Formatting.Indented);
            Console.WriteLine(y);
        }

        public static void ObjectReference()
        {
            Author Saleh = new Author()
            {
                name = "Saleh",
                courses = new[] {"OS", "ARCH", "Whatever"}
            };

            Author Ali = new Author()
            {
                name = "Ali",
                courses = new[] {"OS2", "ARCHiii", "Whatever"}
            };
            Author Salma = new Author()
            {
                name = "Salma",
                courses = new[] {"Art", "ARCHiii"}
            };

            Saleh.favoriteAuthors = new List<Author>() {Ali, Saleh, Salma, Ali, Ali, Saleh};
            Ali.favoriteAuthors = new List<Author>() {Saleh, Salma};
            Salma.favoriteAuthors = new List<Author>() {Saleh};
            JsonSerializerSettings settings = new JsonSerializerSettings
            {
                PreserveReferencesHandling = PreserveReferencesHandling.None,
                Formatting = Formatting.Indented
            };
            string salehjson = JsonConvert.SerializeObject(Saleh, settings); // works fine 
            Console.WriteLine(salehjson);
            // Author SalehClone = JsonConvert.DeserializeObject<Author>(salehjson);
            // SalehClone.favoriteAuthors.ForEach(x => Console.WriteLine(x.name + " " +  x.GetHashCode()));
        }
    }
}