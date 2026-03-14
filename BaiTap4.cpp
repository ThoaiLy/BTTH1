#include<iostream>
using namespace std;

//Khai báo struct Date(lưu trữ ngày tháng năm)
struct Date
{
    int day;
    int month;
    int year;
};

Date input() ///Hàm nhập ngày, tháng, năm từ bàn phím và trả về kiểu Date
{
    cout << "Nhập ngày tháng năm: ";
    Date tmp;
    cin >> tmp.day >> tmp.month >> tmp.year;

    return tmp;
}

void output(Date tmp) //In ra dưới dạng dd/mm/yyyy
{
    cout << "Ngày kế tiếp là: ";
    cout << tmp.day << "/" << tmp.month << "/" << tmp.year;
}

//Hàm kiểm tra tính hợp lệ của ngày vừa nhập trả về kiểu bool
bool check(Date cur)
{
    //Kiểm tra ngày, tháng, năm nhập hợp lệ hay không
    if(cur.day < 1 || cur.month < 1 || cur.month > 12 || cur.year < 1)
        return false;
    if(cur.month == 2)
    {
        /*Đối với tháng 2 nếu là năm nhuận thì kiểm tra xem ngày có lớn hơn 29 không
        nếu lớn hơn -> ngày không hợp lệ*/
        if((cur.year % 400 == 0) || (cur.year % 4 == 0 && cur.year % 100 != 0))
        {
            if(cur.day > 29)
                return false;
        }
        /*Năm không nhuận thì kiểm tra xem ngày có lớn hơn 28 không
        nếu lớn hơn -> ngày không hợp lệ*/
        else
        {
            if(cur.day > 28)
                return false;
        }
    }
    /*Đối với các tháng 1 3 5 7 8 10 12, nếu ngày nhập lớn hơn 31 -> không hợp lệ*/
    else if(cur.month == 1 || cur.month == 3 || cur.month == 5 || cur.month == 7 || cur.month == 8 || cur.month == 10 || cur.month == 12)
    { 
        if(cur.day > 31)
            return false;
    }
    /*Đối với các còn lại, nếu ngày nhập lớn hơn 30 -> không hợp lệ*/
    else
    {
        if(cur.day > 30)
            return false;
    }
    return true;
}

Date nextday(Date cur)
{
    //Tạo bản sao của ngày hiện tại 
    Date tmp = cur;
    if(tmp.month == 2)
    {
        if((tmp.year % 400 ==0) || (tmp.year % 4 ==0 && tmp.year % 100 != 0))
        {
            //Nếu là ngày cuối tháng 2 của năm nhuận -> ngày thành ngày 1 / 3
            if(tmp.day == 29)
            {
                tmp.day = 1;
                tmp.month++;
            }
            else
                tmp.day++; //Chưa phải cuối tháng → tăng ngày
        }
        else
        {
            //Nếu là ngày cuối tháng 2 của năm không nhuận -> ngày thành ngày 1 / 3
            if(tmp.day == 28)
            {
                tmp.day = 1;
                tmp.month++;
            }
            else
                tmp.day++;
        }
    }
    // Các tháng có 31 ngày
    else if(tmp.month == 1 || tmp.month == 3 || tmp.month == 5 || tmp.month == 7 || tmp.month == 8 || tmp.month == 10 || tmp.month == 12)
    {
        //Trường hợp 31 / 12 -> chuyển sang đầu năm mới
        if(tmp.month == 12 && tmp.day == 31)
        {
            tmp.month = 1;
            tmp.day = 1;
            tmp.year++;
        }
        //Ngày cuối tháng -> chuyển sang đầu tháng sau
        else if (tmp.day == 31)
        {
            tmp.month++;
            tmp.day = 1;
        }
        else
            tmp.day++;
    }
    //Các tháng có 30 ngày
    else
    {
        //Ngày cuối tháng -> chuyển sang đầu tháng sau
        if(tmp.day == 30)
        {
            tmp.month++;
            tmp.day = 1;
        }
        else
            tmp.day++;
    }

    //Trả về ngày kế tiếp
    return tmp;
}

int main()
{
    Date cur;
    cur=input();

    while(!check(cur))
    {
        cout << "Ngày nhập vào không hợp lệ. Vui lòng nhập lại!\n";
        cur=input();
    }

    Date next = nextday(cur);
    output(next);
}