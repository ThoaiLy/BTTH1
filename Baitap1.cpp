#include<iostream>
#include<limits>
#include <numeric>
using namespace std;

//Khai báo struct phân số
struct fraction
{
    long long numerator; //Tử số
    long long denominator; //Mẫu số
};

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

        //Kiểm tra số được nhập có phải là số nguyên không
        if(cin.peek() == '.')
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

void output(fraction a) 
{
    if(a.numerator == 0) //Tử bằng 0 chỉ in 0
        cout << 0 << "\n";
    else if(a.denominator == 1) //Mẫu bằng 1 chỉ in tử
        cout << a.numerator << "\n";
    else
        cout << a.numerator << "/" << a.denominator << "\n";
}

void simplify(fraction &a)
{
    //Chuẩn hóa lại dấu của phân số
    if(a.denominator < 0)
    {
        a.numerator = -a.numerator;
        a.denominator = -a.denominator;
    }
    //Rút gọn bằng cách tìm ước chung lớn nhất rồi chia tử mẫu cho ước chung lớn nhất
    long long g = gcd(llabs(a.numerator), llabs(a.denominator));
    a.numerator = a.numerator / g;
    a.denominator = a.denominator / g;
}

int main()
{
    fraction f1;

    cout << "Nhập phân số: ";
    f1 = input();
    simplify(f1);
    cout << "Phân số đã nhập là: "; output(f1);

    return 0;
}