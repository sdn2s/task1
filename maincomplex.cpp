#include <iostream>
#include <string>
using namespace std;

// ���������� ������ ����������� �����
class Complex
{
private:
	double re;
	double im;

	double SqrAbs() { return this->re * this->re + this->im * this->im; }

public:
	// ����������� �� ��������� � � �����������
	Complex(double re = 0, double im = 0) :re(re), im(im) {}
	// ����������� �����������
	Complex(const Complex& complex) :re(complex.re), im(complex.im) {}
	// ����������
	~Complex() { this->re = 0; this->im = 0; }



	// ��������������� ������
	
	// ������ �����
	double Abs() { return sqrt(this->SqrAbs()); }
	// �������� �����
	double Arg() { return atan2(this->im, this->re); }
	// ���������� ���������
	Complex Reverse()
	{
		Complex complex(this->im, this->re);
		double a = this->re * this->re + this->im * this->im;
		if (a > 0) {
			complex.re = this->re / a;
			complex.im = -this->im / a;
		}
		return complex;
	}
	// �������������� ����� � ������
	string ToString()
	{
		if (this->im == 0) return to_string(this->re);
		if (this->re == 0) return to_string(this->im) + "i";

		// ����� ������������ ����� � ������������� ������ ������
		if (this->im >= 0)
		{
			if (this->im == 1) return to_string(this->re) + "+i";
			if (this->re == 1) return to_string(this->im) + "i";
			return to_string(this->re) + "+" + to_string(this->im) + "i";
		}
		// ����� ������������ ����� � ������������� ������ ������
		else
		{
			return to_string(this->re) + to_string(this->im) + "i";
		}
		
		return "";
	}
	// �������� ��������� ���� ����������� �����
	bool Equals(Complex other) { return ((this->re == other.re) && (this->im == other.im)); }




	// ������������� ���������
	 
	// �������� ������������
	Complex& operator=(const Complex& complex)
	{
		// �������� �� ����������������
		if (&complex == this) return *this;
		this->re = complex.re;
		this->im = complex.im;

		// ���������� ������� ������
		return *this;
	}
	// �������� ��������� ����������� �����
	friend Complex operator*(Complex cx1, Complex cx2) { 
		// ������������� ������� ������������ �����
		Complex complex = Complex();
		complex.re = cx1.re * cx2.re - cx1.im * cx2.im;
		complex.im = cx1.im * cx2.re + cx1.re * cx2.im;
		return Complex(complex.re, complex.im);
	}
	// �������� ��������� �� �����������
	friend Complex operator*(double d, Complex complex) { return complex * d; }
	// �������� ��������� �� ������������ �����
	friend Complex operator*(Complex complex, double d) { return Complex(complex.re * d, complex.im * d); }
	// �������� ��������
	friend Complex operator+(Complex cx1, Complex cx2) { return Complex(cx1.re + cx2.re, cx1.im + cx2.im); }
	friend Complex operator~(Complex complex) { return Complex(complex.re, -complex.im); }
	friend Complex operator/(Complex cx1, Complex cx2) { 
		// ������������� ������� ������������ �����
		Complex complex = Complex();
		// ���������� �������� ����������� �����
		complex.re = (cx1.re * cx2.re + cx1.im * cx2.im) / (cx2.re * cx2.re + cx2.im * cx2.im);
		complex.im = (cx1.re * cx2.re + cx1.im * cx2.im) / (cx2.re * cx2.re + cx2.im * cx2.im);
		return complex;// ���������� ����������� ����� - ���������
	}
	// ��������� ���������
	friend Complex operator-(Complex complex) { return Complex(-complex.re, -complex.im); }
	friend Complex operator-(Complex cx1, Complex cx2) { return cx1 + (-cx2); }
	// �������� ������ � �����
	friend ostream& operator<<(ostream& stream, const Complex& complex)
	{
		stream << complex.re << showpos << complex.im << "i" << noshowpos;
		return stream;
	}
	friend bool operator==(Complex cx1, Complex cx2) {
		// �������� �������� �� null
		if (cx1 == NULL || cx2 == NULL) return false;
		return cx1.Equals(cx2);
	}
};



int main()
{
	setlocale(LC_ALL, "RU");

	// ������ ����������� �����
	Complex complex[3];
	int re = 0, im = 0;

	// ���� ����������� ����� � ����������
	for (int i = 0; i < 2; i++) {
		cout << "������� " << i+1 << "-� ����������� �����\n";
		cout << "������������� �����: "; cin >> re;
		cout << "������ �����: "; cin >> im;
		complex[i] = Complex(re, im);
	}
	
	complex[2] = Complex();
	cout << endl << endl;

	// ������ � ������������ �������
	for (int i = 0; i < 2; i++) {
		cout << "����������� ����� �" << (i + 1) << " = " << complex[i] << endl;
		cout << "������: " << complex[i].Abs() << endl;
		cout << "��������: " << complex[i].Arg() << endl;
		cout << "���������� ���������: " << complex[i].Reverse() << endl;
		cout << endl;
	}
	
	
	complex[2] = complex[0] + complex[1];
	cout << "����� = " << complex[2] << endl;

	complex[2] = complex[0] - complex[1];
	cout << "������� = " << complex[2] << endl;

	complex[2] = complex[0] * complex[1];
	cout << "������������ = " << complex[2] << endl;

	complex[2] = complex[0] / complex[1];
	cout << "�������� = " << complex[2] << endl;
	

	cout << endl;
	system("pause");
	return 0;

}
