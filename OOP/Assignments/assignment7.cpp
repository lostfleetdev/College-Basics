#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Media {
protected:
    string title;
    double price;
public:
    Media(string t, double p) : title(t), price(p) {}

    virtual void display() {}    
};

class Book : public Media {
private:
    int pages;
public:
    Book(string t, double p, int pg) : Media(t, p), pages(pg) {}

    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
        cout << "Pages : " << pages << endl;
        cout << endl;
    }
};


class Tape : public Media {
private:
    int playTime; 
public:
    Tape(string t, double p, int pt) : Media(t, p), playTime(pt) {}

    
    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
        cout << "Playtime: " << playTime << " minutes" << endl;
        cout << endl;
    }
};

int main() {
    vector<Media*> list;

    list.push_back(new Book("The Expanse : Caliban's War", 19.99, 300));
    list.push_back(new Tape("Interstellar", 9.99, 166));

    for(auto m : list){
        m->display();
    }

    for(auto m : list){
        delete m;
    }
    return 0;
}
