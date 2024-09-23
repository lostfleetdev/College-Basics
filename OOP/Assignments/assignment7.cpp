#include <iostream>
#include <string>

using namespace std;

class Media {
protected:
    string title;
    double price;
public:
    Media(string t, double p) : title(t), price(p) {}

    virtual void getdata() {};
    virtual void display() {}; 
    virtual void setdata() {
        this->getdata();
    }  
};

class Book : public Media {
private:
    int pages;
public:
    Book(string t, double p, int pg) : Media(t, p), pages(pg) {}

    void getdata() {
        cout << "\nBook Title: ";
        cin >> title;
        cout << "\nPrice: ";
        cin >> price;
        cout << "\nPages: ";
        cin >> pages;
    }
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

    void getdata() {
        cout << "\nTape Title: ";
        cin >> title;
        cout << "\nPrice: ";
        cin >> price;
        cout << "\nPlay time: ";
        cin >> playTime;
    }
    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
        cout << "Playtime: " << playTime << " minutes" << endl;
        cout << endl;
    }
};

int main() {
    Media* media1 = new Book("The Expanse : Caliban's War", 19.99, 300);
    Media* media2 = new Tape("Interstellar", 9.99, 166);

    media1->display();
    cout << endl;
    media2->display();

    delete media1;
    delete media2;  

    
    return 0;
}
