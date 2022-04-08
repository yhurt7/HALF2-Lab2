#include "complex.h"
#include <vector>
#include <math.h>
#define pi 3.14159

Complex::Complex()
{
  Re = 0;
  Im = 0;
}

Complex::Complex(double Re, double Im)
{
  this -> Im = Im;
  this -> Re = Re;
}

Complex::Complex(const Complex& other)
{
  Re = other.Re;
  Im = other.Im;
}

double Complex::GetRe()
{
  return Re;
}

double Complex::GetIm()
{
  return Im;
}

void Complex::SetRe(double Re)
{
  this -> Re = Re;
}

void Complex::SetIm(double Im)
{
  this -> Im = Im;
}

Complex Complex::operator+(Complex a)
{
  return Complex(this->Re + a.Re, this->Im + a.Im);
}

Complex Complex::operator-(Complex a)
{
  return Complex(this->Re - a.Re, this->Im - a.Im);
}

Complex Complex::operator*(Complex a)
{
  return Complex((this->Re * a.Re)-(this->Im * a.Im), (this->Re * a.Im) + (this->Im * a.Re));
}

Complex Complex::operator/(Complex a)
{
  double _Re = (this->Re * a.Re + this->Im * a.Im) / (pow(a.Re,2) + pow(a.Im, 2));
  double _Im = (this->Im * a.Re - this->Re * a.Im) / (pow(a.Re, 2) + pow(a.Im, 2));
  return Complex(_Re, _Im);
}

Complex& Complex::operator=(const Complex& other)
{
  Re = other.Re;
  Im = other.Im;
  return *this;
}

bool Complex::operator==(Complex a)
{
  if (this->Re == a.Re and this->Im == a.Im)
  {
    return true;
  }
  return false;
}

std::ostream& operator<<(std::ostream& out, Complex a)
{
  out<< a.Re << (a.Im >= 0 ? " + " : " - ") << abs(a.Im) << "i" << std::endl;
  return out;
}

std::istream& operator>>(std::istream& in, Complex& a)
{
  in >> a.Re;
  in >> a.Im;
  return in;
}

double Complex::Module()
{
  return sqrt(pow(this->Re, 2) + pow(this->Im, 2));
}

Complex Complex::IntPow(int m)
{
  double phi = atan2(this->Im, this->Re); // àðãóìåíò
  return Complex(pow(this->Module(), m) * cos(m * phi), pow(this->Module(), m) * sin(m * phi));
}

Complex RootExtract(int n, Complex a)
{
  double phi = atan2(a.GetIm(), a.GetRe());
  return Complex(pow(a.Module(), (double)1 / n) * cos((phi + 2 * pi) / n), pow(a.Module(), (double)1 / n) * sin((phi + 2 * pi) / n));
}

Complex Complex::DrobPow(int m, int n)
{
  return RootExtract(n, this->IntPow(m));
}

void Complex::PrintTrigonomForm()
{
  double phi = atan2(this->GetIm(), this->GetRe());
  std::cout << this->Module() << "(cos(" << phi << ") + i*sin(" << phi << ")" << std::endl;
}
