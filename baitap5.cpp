#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
    case 4: case 6: case 9: case 11: return 30;
    case 2: return isLeapYear(year) ? 29 : 28;
    default: return 31;
    }
}

Date nextDay(Date date) {
    date.day++;
    if (date.day > daysInMonth(date.month, date.year)) {
        date.day = 1;
        date.month++;
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }
    return date;
}

Date previousDay(Date date) {
    date.day--;
    if (date.day < 1) {
        date.month--;
        if (date.month < 1) {
            date.month = 12;
            date.year--;
        }
        date.day = daysInMonth(date.month, date.year);
    }
    return date;
}

int dayOfYear(Date date) {
    int days = date.day;
    for (int i = 1; i < date.month; i++) {
        days += daysInMonth(i, date.year);
    }
    return days;
}

int main() {
    Date date;
    cout << "Nhap ngay: ";
    cin >> date.day;
    cout << "Nhap thang: ";
    cin >> date.month;
    cout << "Nhap nam: ";
    cin >> date.year;

    Date next = nextDay(date);
    Date prev = previousDay(date);
    int dayInYear = dayOfYear(date);

    cout << "Ngay ke tiep: " << next.day << "/" << next.month << "/" << next.year << endl;
    cout << "Ngay truoc đo: " << prev.day << "/" << prev.month << "/" << prev.year << endl;
    cout << "Ngay thu bao nhieu trong nam: " << dayInYear << endl;

    return 0;
}
