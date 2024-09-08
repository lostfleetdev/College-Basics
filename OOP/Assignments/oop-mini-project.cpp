#include <iostream>
#include <string>
#include <vector>
#include <ctime>


using namespace std;
// Base class for food items
class FoodItem {
protected:
    string name;
    int quantity;
    time_t expirationDate;

public:
    FoodItem(string name, int quantity, time_t expirationDate) 
        : name(name), quantity(quantity), expirationDate(expirationDate) {}

    virtual void getDetails() {
        cout << "Food: " << name << " | Quantity: " << quantity 
                  << " | Expires in " << timeToExpiration() << " days." << endl;
    }

    bool isExpired() {
        time_t now = time(0);
        return difftime(expirationDate, now) <= 0;
    }

    int timeToExpiration() {
        time_t now = time(0);
        return difftime(expirationDate, now) / (60 * 60 * 24);  // Returns days to expiration
    }
};

// Derived classes for different types of food
class Dairy : public FoodItem {
public:
    Dairy(string name, int quantity, time_t expirationDate) 
        : FoodItem(name, quantity, expirationDate) {}

    void getDetails() override {
        cout << "Dairy: " << name << " | Quantity: " << quantity 
                  << " | Expires in " << timeToExpiration() << " days." << endl;
    }
};

class Vegetable : public FoodItem {
public:
    Vegetable(string name, int quantity, time_t expirationDate) 
        : FoodItem(name, quantity, expirationDate) {}

    void getDetails() override {
        cout << "Vegetable: " << name << " | Quantity: " << quantity 
                  << " | Expires in " << timeToExpiration() << " days." << endl;
    }
};

class Meat : public FoodItem {
public:
    Meat(string name, int quantity, time_t expirationDate) 
        : FoodItem(name, quantity, expirationDate) {}

    void getDetails() override {
        cout << "Meat: " << name << " | Quantity: " << quantity 
                  << " | Expires in " << timeToExpiration() << " days." << endl;
    }
};

// Class to represent fridge's mood
class FridgeMood {
    string mood;

public:
    FridgeMood() : mood("neutral") {}

    void updateMood(int expiredItems) {
        if (expiredItems > 5) mood = "angry";
        else if (expiredItems > 0) mood = "sad";
        else mood = "happy";
    }

    string getMoodMessage() {
        if (mood == "happy") return "I'm happy! Great job managing food!";
        if (mood == "sad") return "I'm sad... Please check your fridge more often.";
        if (mood == "angry") return "I'm angry! Too much food waste!";
        return "I'm neutral.";
    }
};

// Fridge class to manage food items
class Fridge {
    vector<FoodItem*> foodItems;
    FridgeMood currentMood;

public:
    void addFoodItem(FoodItem* item) {
        foodItems.push_back(item);
    }

    void checkFoodStatus() {
        int expiredCount = 0;
        for (auto& item : foodItems) {
            item->getDetails();  // Display the details of each food item
            if (item->isExpired()) {
                cout << "*** " << item->timeToExpiration() << " days: Expired! ***\n";
                expiredCount++;
            }
        }
        currentMood.updateMood(expiredCount);
    }

    void showFridgeMood() {
        cout << currentMood.getMoodMessage() << endl;
    }

    ~Fridge() {
        for (auto& item : foodItems) {
            delete item;  // Free allocated memory for food items
        }
    }
};

// Function to create expiration dates dynamically
time_t createExpirationDate(int daysFromNow) {
    return time(0) + daysFromNow * 24 * 60 * 60;
}

// Function to handle user input for adding food items
void userAddFoodItems(Fridge &fridge) {
    string name;
    int quantity;
    int daysToExpire;
    char foodType;

    cout << "Enter the type of food item (D - Dairy, V - Vegetable, M - Meat): ";
    cin >> foodType;

    cout << "Enter the name of the food: ";
    cin >> name;

    cout << "Enter the quantity: ";
    cin >> quantity;

    cout << "Enter the number of days until expiration: ";
    cin >> daysToExpire;

    time_t expirationDate = createExpirationDate(daysToExpire);

    // Create appropriate food item based on type
    FoodItem* newItem = nullptr;
    if (foodType == 'D' || foodType == 'd') {
        newItem = new Dairy(name, quantity, expirationDate);
    } else if (foodType == 'V' || foodType == 'v') {
        newItem = new Vegetable(name, quantity, expirationDate);
    } else if (foodType == 'M' || foodType == 'm') {
        newItem = new Meat(name, quantity, expirationDate);
    } else {
        cout << "Invalid food type!" << endl;
        return;
    }

    // Add the new item to the fridge
    fridge.addFoodItem(newItem);
    cout << "Food item added to fridge successfully!" << endl;
}

int main() {
    Fridge myFridge;
    char choice;

    // User interaction loop
    do {
        cout << "\n--- Fridge Assistant ---\n";
        cout << "1. Add Food Item\n";
        cout << "2. Check Food Status\n";
        cout << "3. Show Fridge Mood\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case '1':
                userAddFoodItems(myFridge);
                break;
            case '2':
                myFridge.checkFoodStatus();
                break;
            case '3':
                myFridge.showFridgeMood();
                break;
            case '4':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option! Please choose again.\n";
        }
    } while (choice != '4');

    return 0;
}
