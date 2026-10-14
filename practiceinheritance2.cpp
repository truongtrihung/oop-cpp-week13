#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Lớp cơ sở Employee (Quản lý thông tin định danh nhân sự)
class Employee {
protected:
    string identificationCard; // Thay tên biến: cccd -> identificationCard
    string phoneNum;           // Thay tên biến: sdt -> phoneNum
    string residence;          // Thay tên biến: address -> residence
public:
    Employee() {
        identificationCard = "";
        phoneNum = "";
        residence = "";
    }
    
    Employee(string idCard, string phone, string addr) {
        identificationCard = idCard;
        phoneNum = phone;
        residence = addr;
    }

    virtual ~Employee() {} 

    virtual void displayInfo() const {
        cout << "CCCD    : " << identificationCard << endl;
        cout << "SDT     : " << phoneNum << endl;
        cout << "Address : " << residence << endl;
    }

    virtual double tinhLuong() const = 0; 

    // Getters & Setters tùy chỉnh phong cách đặt tên
    string getCCCD() const { return identificationCard; }
    string getSDT() const { return phoneNum; }
    string getAddress() const { return residence; }
    
    void setCCCD(string idCard) { identificationCard = idCard; }
    void setSDT(string phone) { phoneNum = phone; }
    void setAddress(string addr) { residence = addr; }
};

// 2. Lớp HourlyEmployee (Nhân viên tính lương theo giờ làm việc)
class HourlyEmployee : public Employee {
private:
    int workHours;     // Thay tên biến: soGioLamViec -> workHours
    double hourlyRate; // Thay tên biến: donGia -> hourlyRate
public:
    HourlyEmployee() : Employee() {
        workHours = 0;
        hourlyRate = 0.0;
    }
    
    HourlyEmployee(string idCard, string phone, string addr, int hours, double rate) 
        : Employee(idCard, phone, addr) {
        workHours = hours;
        hourlyRate = rate;
    }

    double tinhLuong() const override {
        return workHours * hourlyRate;
    }

    void displayInfo() const override {
        cout << "--- Nhan vien theo gio ---" << endl;
        Employee::displayInfo();
        cout << "So gio lam viec: " << workHours << endl;
        cout << "Don gia         : " << hourlyRate << endl;
        cout << "Luong           : " << tinhLuong() << endl;
    }

    int getSoGioLamViec() const { return workHours; }
    double getDonGia() const { return hourlyRate; }
    
    void setSoGioLamViec(int hours) { workHours = hours; }
    void setDonGia(double rate) { hourlyRate = rate; }
};

// 3. Lớp MonthlyEmployee (Nhân viên biên chế hưởng lương tháng cố định)
class MonthlyEmployee : public Employee {
private:
    double baseSalary;  // Thay tên biến: luongCoBan -> baseSalary
    double allowance;   // Thay tên biến: phuCap -> allowance
    double bonusFactor; // Thay tên biến: heSoThuong -> bonusFactor
public:
    MonthlyEmployee() : Employee() {
        baseSalary = 0.0;
        allowance = 0.0;
        bonusFactor = 0.0;
    }
    
    MonthlyEmployee(string idCard, string phone, string addr, double base, double allow, double bonus) 
        : Employee(idCard, phone, addr) {
        baseSalary = base;
        allowance = allow;
        bonusFactor = bonus;
    }

    double tinhLuong() const override {
        return baseSalary + allowance + (baseSalary * bonusFactor);
    }

    void displayInfo() const override {
        cout << "--- Nhan vien theo thang ---" << endl;
        Employee::displayInfo();
        cout << "Luong co ban    : " << baseSalary << endl;
        cout << "Phu cap         : " << allowance << endl;
        cout << "He so thuong    : " << bonusFactor << endl;
        cout << "Luong           : " << tinhLuong() << endl;
    }

    double getLuongCoBan() const { return baseSalary; }
    double getPhuCap() const { return allowance; }
    double getHeSoThuong() const { return bonusFactor; }
    
    void setLuongCoBan(double base) { baseSalary = base; }
    void setPhuCap(double allow) { allowance = allow; }
    void setHeSoThuong(double bonus) { bonusFactor = bonus; }
};

int main() {
    // Khởi tạo danh sách quản lý sử dụng đa hình thông qua vector con trỏ
    vector<Employee*> staffList;
    staffList.push_back(new HourlyEmployee("07987654321", "0901111111", "Ha Noi", 160, 50000));
    staffList.push_back(new HourlyEmployee("07987654322", "0902222222", "Hai Phong", 120, 60000));
    staffList.push_back(new MonthlyEmployee("079987654321", "0903333333", "Da Nang", 15000000, 2000000, 1.2));
    staffList.push_back(new MonthlyEmployee("079987654322", "0904444444", "Hue", 12000000, 1500000, 1.0));

    // Hiển thị toàn bộ danh sách nhân sự
    cout << "=== DANH SACH NHAN VIEN ===" << endl;
    for (size_t i = 0; i < staffList.size(); ++i) {
        staffList[i]->displayInfo();
        cout << "--------------------------" << endl;
    }

    // Tính tổng quỹ lương công ty
    double totalPayroll = 0;
    for (size_t i = 0; i < staffList.size(); ++i) {
        totalPayroll += staffList[i]->tinhLuong();
    }
    cout << "-> Tong quy luong cua cong ty: " << totalPayroll << endl << endl;

    // Tìm kiếm nhân sự có mức thu nhập cao nhất và thấp nhất
    if (!staffList.empty()) {
        Employee* highestPaid = staffList[0];
        Employee* lowestPaid = staffList[0];
        for (size_t i = 1; i < staffList.size(); ++i) {
            if (staffList[i]->tinhLuong() > highestPaid->tinhLuong()) {
                highestPaid = staffList[i];
            }
            if (staffList[i]->tinhLuong() < lowestPaid->tinhLuong()) {
                lowestPaid = staffList[i];
            }
        }
        cout << "=== NHAN VIEN LUONG CAO NHAT ===" << endl;
        highestPaid->displayInfo();
        cout << "\n=== NHAN VIEN LUONG THAP NHAT ===" << endl;
        lowestPaid->displayInfo();
        cout << endl;
    }

    // Thống kê phân loại số lượng nhân viên
    int hourlyCount = 0;
    int monthlyCount = 0;
    for (size_t i = 0; i < staffList.size(); ++i) {
        if (dynamic_cast<HourlyEmployee*>(staffList[i])) {
            hourlyCount++;
        } else if (dynamic_cast<MonthlyEmployee*>(staffList[i])) {
            monthlyCount++;
        }
    }
    cout << "=== THONG KE SO LUONG ===" << endl;
    cout << "So luong HourlyEmployee : " << hourlyCount << endl;
    cout << "So luong MonthlyEmployee: " << monthlyCount << endl << endl;

    // Lọc danh sách nhân viên vượt mức lương chỉ định
    double thresholdSalary;
    cout << "Nhap muc luong de tim kiem (greater than): ";
    cin >> thresholdSalary;
    cout << "=== DANH SACH NHAN VIEN LUONG > " << thresholdSalary << " ===" << endl;
    bool matchFound = false;
    for (size_t i = 0; i < staffList.size(); ++i) {
        if (staffList[i]->tinhLuong() > thresholdSalary) {
            staffList[i]->displayInfo();
            cout << "--------------------------" << endl;
            matchFound = true;
        }
    }
    if (!matchFound) {
        cout << "Khong tìm thay nhân vien nao thoa man.\n" << endl;
    }

    // Sắp xếp thứ tự danh sách theo chiều lương giảm dần
    sort(staffList.begin(), staffList.end(), [](Employee* empA, Employee* empB) {
        return empA->tinhLuong() > empB->tinhLuong();
    });

    cout << "=== DANH SACH SAU KHI SAP XEP LUONG GIAM DAN ===" << endl;
    for (size_t i = 0; i < staffList.size(); ++i) {
        cout << "CCCD: " << staffList[i]->getCCCD() << " | Luong: " << staffList[i]->tinhLuong() << endl;
    }

    // Thu hồi vùng nhớ động đã cấp phát tránh rò rỉ bộ nhớ (Memory Leak)
    for (size_t i = 0; i < staffList.size(); ++i) {
        delete staffList[i];
    }
    staffList.clear();

    return 0;
}