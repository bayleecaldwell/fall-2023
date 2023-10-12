#include <iostream>

class Complex
{
private:
    double real;
    double img;

    Complex& addTo(const Complex& rhs);
    Complex& multiplyBy(const Complex& rhs);

public:
    Complex() : real(0.0), img(0.0) {}
    Complex(double r, double i) : real(r), img(i) {}

    double getReal() const {
        return real;
    }

    double getImg() const {
        return img;
    }

    Complex operator+(const Complex& rhs) const {
        Complex result(*this);
        result.addTo(rhs);
        return result;
    }

    Complex operator*(const Complex& rhs) const {
        Complex result(*this);
        result.multiplyBy(rhs);
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

Complex& Complex::addTo(const Complex& rhs) {
    real += rhs.real;
    img += rhs.img;
    return *this;
}

Complex& Complex::multiplyBy(const Complex& rhs) {
    double tempReal = real * rhs.real - img * rhs.img;
    double tempImg = real * rhs.img + img * rhs.real;
    real = tempReal;
    img = tempImg;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.getReal() << "+" << c.getImg() << "i";
    return os;
}

int main() {
    Complex a(2.0, 3.0);
    Complex b(1.0, 2.0);

    Complex c = a + b;
    Complex d = a * b;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << c << std::endl;
    std::cout << "a * b = " << d << std::endl;

    return 0;
}
