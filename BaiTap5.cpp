#include<iostream>
#include<iomanip>
#include <cctype>
using namespace std;

//Khai báo struct học sinh gồm: tên học sinh, điểm toán, điểm văn và điểm trung bình
struct student{
    char name[30];
    double math;
    double literature;
    double avg; //average: điểm trung bình
};

//Hàm kiểm tra tên có chứa ký tự lạ hoặc số hay không
bool checkName(char name[])
{
    for(int i = 0; name[i] != '\0'; i++)
    {
        if(!isalpha(name[i]) && name[i] != ' ')
            return false;
    }
    return true;
}

//Hàm nhập dữ liệu từ bàn phím, trả về kiểu student
student input()
{
    student tmp;

    cout << "Nhập họ tên: ";
    while(true)
    {
        cin.getline(tmp.name, 30);

        if(checkName(tmp.name)) //Nếu tên hợp lệ thì dừng
            break;
        else
            cout << "Tên không hợp lệ. Vui lòng nhập lại: ";
    }

    cout << "Nhập điểm toán và điểm văn: ";
    //Kiểm tra điểm nhập vào có hợp lệ không
    while(true)
    {
        if(!(cin >> tmp.math >> tmp.literature))
        {
            cout << "Diem khong hop le. Nhap lai: ";
            cin.clear(); //Xóa trạng thái lỗi của cin
            cin.ignore(1000,'\n'); //Bỏ dữ liệu sai trong bộ đệm
            continue;
        }
        cin.ignore(1000,'\n');
        break;
    }

    //Tính điểm trung bình
    tmp.avg = (tmp.math + tmp.literature) / 2;

    return tmp;
}

//Hàm xuất thông tin học sinh
void print(student tmp)
{
    cout << "Tên: " << tmp.name << "\n";
    cout << "Điểm toán: " << tmp.math << "\n";
    cout << "Điểm văn: " << tmp.literature << "\n";

    //In điểm trung bình với 2 chữ số thập phân
    cout << "Điểm trung bình: " << fixed << setprecision(2) << tmp.avg;
}

int main()
{
    student a;
    a = input();

    print(a);

    return 0;
}