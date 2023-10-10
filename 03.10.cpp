#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std; 

class Reservoir {
    string name;
    int width;
    int length;
    int depth;
    string type;

public:

    Reservoir() 
        : name(""), width(0), length(0), depth(0), type("") {}

    explicit Reservoir(const string n, int w, int l, int d, const string t) 
        : name(n), width(w), length(l), depth(d), type(t) {}

    Reservoir(const Reservoir& r) 
        : name(r.name), width(r.width), length(r.length), depth(r.depth), type(r.type) {}

    int volume()
    {return  width * length * depth;}

    int surfaceArea() 
    {return width * length;}

    bool typeCompare (const Reservoir& r) const
    {return type == r.type;}

    bool areaCompare(Reservoir& r) 
    {return (typeCompare(r) && surfaceArea() > r.surfaceArea());}

    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    void setLength(const int& l) { length = l; }
    int getLength() const { return length; }

    void setWidth(const int& w) { width = w; }
    int getWidth() const { return width; }

    void setDepth(const int& d) { depth = d; }
    int getDepth() const { return depth; }

    void setType(const string& t) { type = t; }
    string  getType() const { return type; }

    void copy(const Reservoir& r) {
        name = r.name;
        width = r.width;
        length = r.length;
        depth = r.depth;
        type = r.type;
    }
};

class Handler {
    vector<Reservoir> reservoirs;
public:
    void add() {
        string name;
        string type; 
        int width;
        int length;
        int depth;

        cin.ignore();

        cout << "Name: "; 
        getline(cin, name);

        cout << "Type: ";
        getline(cin, type);

        cout << "Length: ";
        cin >> length;

        cout << "Width: ";
        cin >> width;

        cout << "Depth: ";
        cin >> depth;

        Reservoir r(name, width, length, depth, type);
        reservoirs.push_back(r);
    }

    void remove(int index) {
        if (index < reservoirs.size()) {
            reservoirs.erase(reservoirs.begin() + index);
        }
    }

    void save(const string& filename) const {
        ofstream out(filename);
        for (const Reservoir& r : reservoirs) {
            out << r.getName() << " " << r.getType() << " " << r.getLength() << " " << r.getWidth() << " " << r.getDepth() <<  "\n";
        }
        out.close();
    }


    void print() const {
        for (const Reservoir& r : reservoirs) {
            cout << "\nName: " << r.getName() << "\nType: " << r.getType() << "\nWidth: " << r.getWidth() << "\nLength: " << r.getLength() << "\nDepth: " << r.getDepth() << "\n";
        }
    }

};


int main()
{
    Handler reservoirs;
    int index; 
    bool work = 1;

    while(work)
    {
        int choice = 0;
        cout << "\n1) Add\n2) Remove\n3) Save as .txt\n4) Save as .bin\n5) Print\n0) Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            reservoirs.add();
            break;
        case 2:
            cin >> index;
            reservoirs.remove(index);
            break;
        case 3:
            reservoirs.save("reservoirs.txt");
            cout << "File saved as .txt\n";
            break;
        case 4:
            reservoirs.save("reservoirs.bin");
            cout << "File saved as .bin\n";
            break;
        case 5: 
            reservoirs.print();
            break;
        case 0:
            work = 0;
            break;
        default:
            cout << "Wrong input buddy, no big deal\n";
            break;
        }
    }
}
