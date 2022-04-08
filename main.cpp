#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
setlocale(LC_ALL, "rus");

Complex a(10,5);
Complex b;

cout << "Введите комплексное число в виде Re Im: ";
cin >> b;

cout << "a + b = " << a + b;
cout << "a - b = " << a - b;
cout << "a * b = " << a * b;
cout << "a / b = " << a / b;

if (a == b)
{
cout << "a = b" << endl;
}

cout << "Положительная степень: " << a.IntPow(2);
cout << "Отрицательная степень: " << a.IntPow(-2);
a.DrobPow(10,5).PrintTrigonomForm(); cout << ": Дробная степень в тригонометрической форме " << endl;

return 0;
}
