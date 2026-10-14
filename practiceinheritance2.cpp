#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Class Employee (lớp cha)
class Employee {
protected:
    string cccd;
    string sdt;
    string address;
public:
    Employee() {
        cccd = "";
        sdt = "";
        address = "";
    }
    Employee(string c, string s, string a) {
        cccd = c;
        sdt = s;
        address = a;
    }

    virtual ~Employee() {} // Destructor ảo để hủy đúng đối tượng dẫn xuất

    virtual void displayInfo() const {
        cout << "CCCD    : " << cccd << endl;
        cout << "SDT     : " << sdt << endl;
        cout << "Address : " << address << endl;
    }

    // Hàm thuần ảo hoặc ảo để tính lương cho các lớp con
    virtual double tinhLuong() const = 0; 

    // getters & setters
    string getCCCD() const { return cccd; }
    string getSDT() const { return sdt; }
    string getAddress() const { return address; }
    void setCCCD(string c) { cccd = c; }
    void setSDT(string s) { sdt = s; }
    void setAddress(string a) { address = a; }
};

// 2. Class HourlyEmployee (kế thừa từ Employee)
class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;
public:
    HourlyEmployee() : Employee() {
        soGioLamViec = 0;
        donGia = 0.0;
    }
    HourlyEmployee(string c, string s, string a, int soGio, double dg) : Employee(c, s, a) {
        soGioLamViec = soGio;
        donGia = dg;
    }

    double tinhLuong() const override {
        return soGioLamViec * donGia;
    }

    void displayInfo() const override {
        cout << "--- Nhan vien theo gio ---" << endl;
        Employee::displayInfo();
        cout << "So gio lam viec: " << soGioLamViec << endl;
        cout << "Don gia         : " << donGia << endl;
        cout << "Luong           : " << tinhLuong() << endl;
    }

    int getSoGioLamViec() const { return soGioLamViec; }
    double getDonGia() const { return donGia; }
    void setSoGioLamViec(int g) { soGioLamViec = g; }
    void setDonGia(double dg) { donGia = dg; }
};

// 3. Class MonthlyEmployee (kế thừa từ Employee)
class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;
public:
    MonthlyEmployee() : Employee() {
        luongCoBan = 0.0;
        phuCap = 0.0;
        heSoThuong = 0.0;
    }
    MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs) : Employee(c, s, a) {
        luongCoBan = lcb;
        phuCap = pc;
        heSoThuong = hs;
    }

    double tinhLuong() const override {
        return luongCoBan + phuCap + (luongCoBan * heSoThuong);
    }

    void displayInfo() const override {
        cout << "--- Nhan vien theo thang ---" << endl;
        Employee::displayInfo();
        cout << "Luong co ban    : " << luongCoBan << endl;
        cout << "Phu cap         : " << phuCap << endl;
        cout << "He so thuong    : " << heSoThuong << endl;
        cout << "Luong           : " << tinhLuong() << endl;
    }

    double getLuongCoBan() const { return luongCoBan; }
    double getPhuCap() const { return phuCap; }
    double getHeSoThuong() const { return heSoThuong; }
    void setLuongCoBan(double lcb) { luongCoBan = lcb; }
    void setPhuCap(double pc) { phuCap = pc; }
    void setHeSoThuong(double hs) { heSoThuong = hs; }
};

int main() {
    // 3. Tạo ít nhất 2 đối tượng mỗi loại và lưu vào vector<Employee*> (Yêu cầu 3 & 4)
    vector<Employee*> dsNhanVien;
    dsNhanVien.push_back(new HourlyEmployee("07987654321", "0901111111", "Ha Noi", 160, 50000));
    dsNhanVien.push_back(new HourlyEmployee("07987654322", "0902222222", "Hai Phong", 120, 60000));
    dsNhanVien.push_back(new MonthlyEmployee("079987654321", "0903333333", "Da Nang", 15000000, 2000000, 1.2));
    dsNhanVien.push_back(new MonthlyEmployee("079987654322", "0904444444", "Hue", 12000000, 1500000, 1.0));

    // Hiển thị danh sách ban đầu
    cout << "=== DANH SACH NHAN VIEN ===" << endl;
    for (size_t i = 0; i < dsNhanVien.size(); ++i) {
        dsNhanVien[i]->displayInfo();
        cout << "--------------------------" << endl;
    }

    // 4. Tính tổng quỹ lương (Yêu cầu 4)[cite: 5]
    double tongQuyLuong = 0;
    for (size_t i = 0; i < dsNhanVien.size(); ++i) {
        tongQuyLuong += dsNhanVien[i]->tinhLuong();
    }
    cout << "-> Tong quy luong cua cong ty: " << tongQuyLuong << endl << endl;

    // 5. Tìm nhân viên có lương cao nhất và thấp nhất (Yêu cầu 5)[cite: 5]
    if (!dsNhanVien.empty()) {
        Employee* maxEmp = dsNhanVien[0];
        Employee* minEmp = dsNhanVien[0];
        for (size_t i = 1; i < dsNhanVien.size(); ++i) {
            if (dsNhanVien[i]->tinhLuong() > maxEmp->tinhLuong()) {
                maxEmp = dsNhanVien[i];
            }
            if (dsNhanVien[i]->tinhLuong() < minEmp->tinhLuong()) {
                minEmp = dsNhanVien[i];
            }
        }
        cout << "=== NHAN VIEN LUONG CAO NHAT ===" << endl;
        maxEmp->displayInfo();
        cout << "\n=== NHAN VIEN LUONG THAP NHAT ===" << endl;
        minEmp->displayInfo();
        cout << endl;
    }

    // 6. Đếm số lượng nhân viên từng loại (Yêu cầu 6)[cite: 5]
    int countHourly = 0;
    int countMonthly = 0;
    for (size_t i = 0; i < dsNhanVien.size(); ++i) {
        // Dùng dynamic_cast để kiểm tra kiểu thực tế của đối tượng
        if (dynamic_cast<HourlyEmployee*>(dsNhanVien[i])) {
            countHourly++;
        } else if (dynamic_cast<MonthlyEmployee*>(dsNhanVien[i])) {
            countMonthly++;
        }
    }
    cout << "=== THONG KE SO LUONG ===" << endl;
    cout << "So luong HourlyEmployee : " << countHourly << endl;
    cout << "So luong MonthlyEmployee: " << countMonthly << endl << endl;

    // 7. Tìm và hiển thị danh sách nhân viên có lương lớn hơn giá trị nhập từ người dùng (Yêu cầu 7)[cite: 5]
    double mucLuongSoSanh;
    cout << "Nhap muc luong de tim kiem (greater than): ";
    cin >> mucLuongSoSanh;
    cout << "=== DANH SACH NHAN VIEN LUONG > " << mucLuongSoSanh << " ===" << endl;
    bool found = false;
    for (size_t i = 0; i < dsNhanVien.size(); ++i) {
        if (dsNhanVien[i]->tinhLuong() > mucLuongSoSanh) {
            dsNhanVien[i]->displayInfo();
            cout << "--------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tìm thay nhân vien nao thoa man.\n" << endl;
    }

    // 8. Sắp xếp danh sách nhân viên theo lương giảm dần (Yêu cầu 8)[cite: 5]
    sort(dsNhanVien.begin(), dsNhanVien.end(), [](Employee* a, Employee* b) {
        return a->tinhLuong() > b->tinhLuong();
    });

    cout << "=== DANH SACH SAU KHI SAP XEP LUONG GIAM DAN ===" << endl;
    for (size_t i = 0; i < dsNhanVien.size(); ++i) {
        cout << "CCCD: " << dsNhanVien[i]->getCCCD() << " | Luong: " << dsNhanVien[i]->tinhLuong() << endl;
    }

    // Giải phóng bộ nhớ động đã cấp phát cho vector
    for (size_t i = 0; i < dsNhanVien.size(); ++i) {
        delete dsNhanVien[i];
    }
    dsNhanVien.clear();

    return 0;
}