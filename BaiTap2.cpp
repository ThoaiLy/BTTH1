#include<iostream>
#include <numeric>
using namespace std;

//Khai báo struct phân số
struct fraction
{
    long long numerator;
    long long denominator;
};

/*
Đầu vào: Dữ liệu nhập từ bàn phím 
Đầu ra: Trả về giá trị kiểu fraction
Chức năng: Nhập và kiểm tra phân số được nhập
*/
fraction input()
{
    fraction tmp;
    //Kiểm tra phân số có hợp lệ không
    while(true)
    {
        /*Kiểm tra phân số được nhập là số hay các kí tự khác như a, b, !,....*/
        if(!(cin >> tmp.numerator >> tmp.denominator))
        {
            cout << "Phân số không hợp lệ. Vui lòng nhập lại phân số: ";
            cin.clear(); //Xóa trạng thái lỗi của cin
            cin.ignore(100000, '\n'); //Bỏ dữ liệu sai trong bộ đệm
            continue;
        }

        //Kiểm tra số được nhập có phải là số nguyên không hay chứa các kí tự dư khác
        if(cin.peek() == '.' || cin.peek() != '\n')
        {
            cout << "Phân số không hợp lệ. Vui lòng nhập lại phân số: ";
            cin.clear(); //Xóa trạng thái lỗi của cin
            cin.ignore(100000, '\n'); //Bỏ dữ liệu sai trong bộ đệm
            continue;
        }

        //Kiểm tra mẫu có hợp lệ không
        if(tmp.denominator == 0)
        {
            cout << "Phân số không hợp lệ. Vui lòng nhập lại phân số: ";
            continue;
        }
        break;
    }

    //Trả về phân số đã nhập
    return tmp;
}

/*
Đầu vào: Phân số f1
Đầu ra: Không có giá trị trả về
Chức năng: In ra phân số
*/
void output(fraction f1)
{
    if(f1.numerator == 0) //Tử bằng 0 chỉ in 0
        cout << 0;
    else if(f1.denominator == 1) //Mẫu bằng 1 chỉ in tử
        cout << f1.numerator;
    else
        cout << f1.numerator << "/" << f1.denominator;
}

/*
Đầu vào: Phân số f1
Đầu ra: Không có giá trị trả về
Chức năng: Rút gọn và chuẩn hóa dấu phân số
*/
void simplify(fraction &f1)
{
    //Chuẩn hóa lại dấu của phân số
    if(f1.denominator < 0)
    {
        f1.numerator = -f1.numerator;
        f1.denominator = -f1.denominator;
    }
    //Rút gọn bằng cách tìm ước chung lớn nhất rồi chia tử mẫu cho ước chung lớn nhất
    long long g = gcd(llabs(f1.numerator), llabs(f1.denominator));
    f1.numerator = f1.numerator / g;
    f1.denominator = f1.denominator / g;
}

/*
Đầu vào: 2 phân số f1 và f2
Đầu ra: Số nguyên biểu thị lớn hơn, bé hơn và bằng
        1: >
        -1: <
        0: =
Chức năng: So sánh hai phân số
*/
int compare(fraction f1, fraction f2)
{
    //Quy đồng 2 phân số
    long long a_numer = f1.numerator * f2.denominator;
    long long b_numer = f2.numerator * f1.denominator;
    //So sánh
    if(a_numer > b_numer)
        return 1;
    else if(a_numer < b_numer)
        return -1;
    else
        return 0;
}

int main()
{
    fraction f1, f2;
    cout << "Nhập phân số thứ nhất: ";
    f1 = input();
    simplify(f1);
    cout << "Nhập phân số thứ hai: ";
    f2 = input();
    simplify(f2);

    int result = compare(f1,f2);
    if(result == 1)
        {
            cout << "Phân số ";
            output(f1);
            cout << " là phân số lớn nhất.";

        }
        else if(result == -1)
        {
            cout << "Phân số ";
            output(f2);
            cout << " là phân số lớn nhất.";
        }
        else
            cout << "Hai phân số bằng nhau" << "\n";
    
    return 0;
}