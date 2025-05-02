#include <unordered_map>
#include <set>
#include <vector>
#include <string>

class FoodRatings {
private:
    std::unordered_map<std::string, int> foodRating; // food -> rating
    std::unordered_map<std::string, std::string> foodCuisine; // food -> cuisine
    std::unordered_map<std::string, std::multiset<std::pair<int, std::string>>> cuisineFoods; // cuisine -> multiset of (-rating, food)

public:
    FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(std::string food, int newRating) {
        // Get old rating and cuisine
        int oldRating = foodRating[food];
        std::string cuisine = foodCuisine[food];
        
        // Remove old entry from multiset
        cuisineFoods[cuisine].erase(cuisineFoods[cuisine].find({-oldRating, food}));
        
        // Update rating
        foodRating[food] = newRating;
        
        // Insert new entry
        cuisineFoods[cuisine].insert({-newRating, food});
    }
    
    std::string highestRated(std::string cuisine) {
        // Return the food with the highest rating (smallest negative rating)
        return cuisineFoods[cuisine].begin()->second;
    }
};