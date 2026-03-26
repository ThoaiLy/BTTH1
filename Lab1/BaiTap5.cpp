#include<iostream>
#include<string.h>
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

/*
Đầu vào: Chuỗi name (mảng ký tự)
Đầu ra: true nếu tên hợp lệ, false nếu không hợp lệ
Chức năng: Kiểm tra sự hợp lệ của tên được nhập
*/
bool checkName(char name[])
{
    if(strlen(name) == 0)
        return false; //Tên rỗng trả về false (Trường hợp không nhập mà nhấn enter luôn)

    bool allSpace = true; //Biến dùng để kiểm tra xem tên nhập có phải toàn kí tự cách không. Ví dụ name = "       "
    for(int i = 0; name[i] != '\0'; i++)
    {
        if(!isalpha(name[i]) && name[i] != ' ')
            return false;
        if(name[i] != ' ')
            allSpace = false;
    }
    if(allSpace)
        return false; //Tên nhập vào toàn dấu cách -> sai
    return true;
}

/*
Đầu vào: Dữ liệu nhập từ bàn phím
Đầu ra: Trả về một biến lưu thông tin học sinh kiểu student
Chức năng: Nhập thông tin học sinh và kiểm tra tính hợp lệ của dữ liệu
*/
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
        if(!(cin >> tmp.math >> tmp.literature) ||  tmp.math < 0 || tmp.math > 10 || tmp.literature < 0 || tmp.literature > 10 || cin.peek() != '\n')
        {
            cout << "Điểm không hợp lệ. Nhập lại: ";
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

/*
Đầu vào: Biến tmp (đang lưu thông tin học sinh) kiểu student
Đầu ra: Không có giá trị trả về
Chức năng: In thông tin học sinh ra màn hình
*/
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