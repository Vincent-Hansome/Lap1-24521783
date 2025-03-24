#include <iostream>
using namespace std;
struct Phanso {
    int ts, ms;
};
void Nhap(Phanso& a) {
    do {
        cout << "Nhap tu to:"; cin >> a.ts;
        cout << "Nhap mau so:"; cin >> a.ms;
        if (a.ms == 0) cout << "Nhap sai hay nhap lai." << endl;
    } while (a.ms == 0);
}
int ucln(Phanso a) {
    int b = abs(a.ts), c = abs(a.ms);
    if (b == 0) return 1;
    while (b != c) {
        if (b > c) b -= c;
        else c -= b;
    }
    return c;
}
void Xuat(Phanso a) {
    int c = ucln(a);
    a.ts /= c;
    a.ms /= c;
    cout << "Phan so la:";
    if (a.ms < -1) cout << -a.ts << "/" << -a.ms;
    else if (a.ms == -1) cout << -a.ts;
    else if (a.ts == 0) cout << 0;
    else if (a.ms == 1) cout << a.ts;
    else cout << a.ts << "/" << a.ms;
}
int main()
{
    Phanso a;
    Nhap(a);
    Xuat(a);
    return 0;
}
