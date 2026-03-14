#include<iostream>
#include<iomanip>
using namespace std;

//Khai báo struct học sinh gồm tên điểm toán, văn và điểm trung bình
struct student{
    char name[30];
    double math;
    double literature;
    double avr;
};

//Hàm nhập dữ liệu từ bàn phím trả về kiểu student
student input()
{
    student tmp;

    cout << "Nhập họ tên: ";
    cin.getline(tmp.name, 30);

    cout << "Nhập điểm toán và điểm văn: ";
    cin >> tmp.math >> tmp.literature;
    cin.ignore();

    //Tính điểm trung bình
    tmp.avr = (tmp.math + tmp.literature) / 2;

    return tmp;
}

//Hàm xuất thông tin học sinh
void print(student tmp)
{
    cout << "Tên: " << tmp.name << "\n";
    cout << "Điểm toán: " << tmp.math << "\n";
    cout << "Điểm văn: " << tmp.literature << "\n";

    //In điểm trung bình với 2 chữ số thập phân
    cout << "Trung bình: " << fixed << setprecision(2) << tmp.avr;
}

int main()
{
    student a;
    a = input();

    print(a);

    return 0;
}