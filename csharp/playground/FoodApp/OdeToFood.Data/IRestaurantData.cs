using System;
using System.Linq;
using OdeToFood.Core;
using System.Collections.Generic;


namespace OdeToFood.Data
{
    public interface IRestaurantData
    {
        IEnumerable<Restaurant> GetAll();
    }

    public class InMemoryRestaurantData : IRestaurantData
    {
        public static string RandomString(int length)
        {
            var random = new Random();
            const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            return new string(Enumerable.Repeat(chars, length)
                .Select(s => s[random.Next(s.Length)]).ToArray());
        }

        readonly List<Restaurant> restaurants;

        public InMemoryRestaurantData()
        {
            restaurants = new List<Restaurant>()
            {
                new Restaurant {Id = 1, Name = "Scott's Pizza", Location = "Maryland", Cuisine = CuisineType.Italian},
                new Restaurant {Id = 2, Name = "Cinnamon Club", Location = "London", Cuisine = CuisineType.Italian},
                new Restaurant {Id = 3, Name = "La Costa", Location = "California", Cuisine = CuisineType.Mexican}
            };
        }

        public IEnumerable<Restaurant> GetAll()
        {
            return from r in restaurants
                orderby r.Name
                select r;
        }
    }
}