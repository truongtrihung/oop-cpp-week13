#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class People
class People{
private:
    string name;
    string cccd;
    string address;
public:
    People(){
        name = "";
        cccd = "";
        address = "";
    }
    People (string n, string c, string a){
        name = n;
        cccd = c;
        address = a;
    }

    // Getter
    string getPeopleName () const {return name;}
    string getPeopleCccd () const {return cccd;}
    string getPeopleAddress () const {return address;}

    // Setter 
    void setPeopleName (string n) {name = n;}
    void setPeopleCccd (string c) {cccd = c;}
    void setPeopleAddress (string a) {address = a;}
};

// Class Student 
class Student : public People {
private:
    string mssv;
    int yearEntrance;
public:
    Student () : People () {
        mssv = "";
        yearEntrance = 0;
    }
    Student (string n, string c, string a, string m, int y) : People (n, c, a) {
        mssv = m;
        yearEntrance = y;  
    }

    // Getter 
    string getMSSV () const {return mssv;}
    int getYearEntrance () const {return yearEntrance;}

    // Setter
    void setMSSV (string m) {mssv = m;}
    void setYearEntrance (int y) {yearEntrance = y;}
};

// Class Fiestudent
class FIEstudent : public Student {
private:
    int credits;
public:
    FIEstudent () : Student () {
        credits = 0;
    }
    FIEstudent (string n, string c, string a, string m, int y, int cr) : Student (n, c, a, m, y) {
        credits = cr;
    }

    // Getter 
    int getCredits () const {return credits;}

    // Setter
    void setCredits (int cr) {credits = cr;}

    void displayInfo () const {
        cout << "   | CCCD      : " << getPeopleCccd() << endl;
        cout << "   | Name      : " << getPeopleName () << endl;
        cout << "   | Address   : " << getPeopleAddress () << endl;
        cout << "   | MSSV      : " << getMSSV () << endl;
        cout << "   | Y Entrance: " << getYearEntrance () << endl;
        cout << "   | Credits   : " << getCredits () << endl;
        cout << "=============================" << endl;
    }
};
int main() {
    FIEstudent f1; 
    FIEstudent f2("079987654321", "Le Minh C", "Da Nang", "FIE2023001", 2023, 120);

    cout << "== Thong tin doi tuong f1 (khoi tao mac dinh) ==" << endl;
    f1.displayInfo();

    cout << "== Thong tin doi tuong f2 (khoi tao co tham so) ==" << endl;
    f2.displayInfo();

    return 0;
}