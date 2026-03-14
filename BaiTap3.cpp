#include<iostream>
#include <numeric>
using namespace std;

//Khai báo struct phân số
struct fraction
{
    long long numerator;
    long long denominator;
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

fraction add(fraction a, fraction b)
{
    fraction tmp;

    //Quy đồng 2 phân số rồi cộng
    tmp.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    tmp.denominator = a.denominator * b.denominator;
    simplify(tmp);

    return tmp;
}

fraction sub(fraction a, fraction b)
{
    fraction tmp;

    //Quy đồng 2 phân số rồi trừ
    tmp.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    tmp.denominator = a.denominator * b.denominator;
    simplify(tmp);

    return tmp;
}

fraction multiply(fraction a, fraction b)
{
    fraction tmp;

    //Nhân tử với tử, mẫu với mẫu
    tmp.numerator = a.numerator * b.numerator;
    tmp.denominator = a.denominator * b.denominator;
    simplify(tmp);

    return tmp;
}

fraction divide(fraction a, fraction b)
{
    fraction tmp;

    //Nhân phân số 1 với nghịch đảo phân số 2 
    tmp.numerator = a.numerator * b.denominator;
    tmp.denominator = a.denominator * b.numerator;
    simplify(tmp);

    return tmp;
}

int main()
{
    fraction f1, f2;
    cout << "Nhập phân số a: ";
    f1 = input();
    simplify(f1);
    cout << "Nhập phân số b: ";
    f2 = input();
    simplify(f2);

    cout << "Tổng 2 phân số là: ";    output(add(f1, f2));
    cout << "Hiệu 2 phân số là: ";    output(sub(f1, f2));
    cout << "Tích 2 phân số là: ";    output(multiply(f1, f2));

    //Kiểm tra xem phân số thứ 2 có bằng 0 không. Nếu bằng 0 -> không chia được
    if (f2.numerator == 0)
        cout << "Không chia được do phân số thứ 2 bằng 0!";
    else{
        cout << "Thương 2 phân số là: "; 
        output(divide(f1, f2));
    }
    
    return 0;
}