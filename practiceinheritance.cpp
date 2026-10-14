#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class People
class People {
private:
    string name;
    string cccd;
    string address;
public:
    People() {
        name = "";
        cccd = "";
        address = "";
    }
    People(string n, string c, string a) {
        name = n;
        cccd = c;
        address = a;
    }

    // Getter
    string getPeopleName() const { return name; }
    string getPeopleCccd() const { return cccd; }
    string getPeopleAddress() const { return address; }

    // Setter 
    void setPeopleName(string n) { name = n; }
    void setPeopleCccd(string c) { cccd = c; }
    void setPeopleAddress(string a) { address = a; }

    virtual void displayInfo() const {
        cout << "   | CCCD      : " << cccd << endl;
        cout << "   | Name      : " << name << endl;
        cout << "   | Address   : " << address << endl;
        cout << "=============================" << endl;
    }
};

// Class Student 
class Student : public People {
private:
    string mssv;
    int yearEntrance;
public:
    Student() : People() {
        mssv = "";
        yearEntrance = 0;
    }
    Student(string n, string c, string a, string m, int y) : People(n, c, a) {
        mssv = m;
        yearEntrance = y;  
    }

    // Getter 
    string getMSSV() const { return mssv; }
    int getYearEntrance() const { return yearEntrance; }

    // Setter
    void setMSSV(string m) { mssv = m; }
    void setYearEntrance(int y) { yearEntrance = y; }

    void displayInfo() const override {
        cout << "   | CCCD      : " << getPeopleCccd() << endl;
        cout << "   | Name      : " << getPeopleName() << endl;
        cout << "   | Address   : " << getPeopleAddress() << endl;
        cout << "   | MSSV      : " << getMSSV() << endl;
        cout << "   | Y Entrance: " << getYearEntrance() << endl;
        cout << "=============================" << endl;
    }
};

// Class Fiestudent
class FIEstudent : public Student {
private:
    int credits;
public:
    FIEstudent() : Student() {
        credits = 0;
    }
    FIEstudent(string n, string c, string a, string m, int y, int cr) : Student(n, c, a, m, y) {
        credits = cr;
    }

    // Getter 
    int getCredits() const { return credits; }

    // Setter
    void setCredits(int cr) { credits = cr; }

    void displayInfo() const override {
        cout << "   | CCCD      : " << getPeopleCccd() << endl;
        cout << "   | Name      : " << getPeopleName() << endl;
        cout << "   | Address   : " << getPeopleAddress() << endl;
        cout << "   | MSSV      : " << getMSSV() << endl;
        cout << "   | Y Entrance: " << getYearEntrance() << endl;
        cout << "   | Credits   : " << getCredits() << endl;
        cout << "=============================" << endl;
    }
};

int main() {
    // === 1. Tạo các đối tượng People bằng các constructor khác nhau ===
    People p1; // mặc định
    People p2("079123456789", "Nguyen Van A", "Ho Chi Minh"); // có tham số

    // === 2. Tạo các đối tượng Student ===
    Student s1; // mặc định (gọi People())
    Student s2("079123456789", "Tran Thi B", "Ha Noi", "SV001", 2023); // có tham số

    // === 3. Tạo các đối tượng FIEstudent ===
    FIEstudent f1; // mặc định (Student() -> People())
    FIEstudent f2("079987654321", "Le Minh C", "Da Nang", "FIE2023001", 2023, 120); // có tham số

    // === 4. Hiển thị thông tin các đối tượng ===
    cout << "---- Thong tin doi tuong p1 (People - mac dinh) ----" << endl;
    p1.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong p2 (People - co tham so) ----" << endl;
    p2.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong s1 (Student - mac dinh) ----" << endl;
    s1.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong s2 (Student - co tham so) ----" << endl;
    s2.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong f1 (FIEstudent - mac dinh) ----" << endl;
    f1.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong f2 (FIEstudent - co tham so) ----" << endl;
    f2.displayInfo();
    cout << endl;

    return 0;
}
