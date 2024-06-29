#include <iostream>
#define MAX 1000

// ساختار چندجمله ای
struct Polynomial 
{
    int coeff[MAX];
    int power[MAX];
    int termCount;
} p1, p2, p3, p4;

// تابع گرفتن چندجمله ای
void getPolynomial(Polynomial& p) {
    std::cout << "enter number gomalat polonomial:";
    std::cin >> p.termCount;
    std::cout << "enter coeff and power for gomle:\n";
    for (int i = 0; i < p.termCount; i++) {
        std::cin >> p.power[i] >> p.coeff[i];
    }

    // مرتب سازی چند جمله ای بر اساس توان - یافتن بیشترین توان و جابجایی یا سوآپ
    for(int i =0;i<p.termCount;i++) {
        for(int j=i+1;j<p.termCount;j++) {
           if(p.power[j] > p.power[i]) {
              int temp = p.power[i];
              p.power[i] = p.power[j];
              p.power[j] = temp;

              temp = p.coeff[i];
              p.coeff[i] = p.coeff[j];
              p.coeff[j] = temp;
           }
        }
    }
}

// تابع نمایش چندجمله ای
void displayPolynomial(Polynomial p) {
    for (int i = 0; i < p.termCount; i++) {
        if (i > 0) std::cout << " + ";
        std::cout << p.coeff[i] << "x^" << p.power[i];
    }
    std::cout << "\n";
}


void addPolynomials(Polynomial& p1, Polynomial& p2, Polynomial& p) {
    p.termCount = 0;
    for (int i = 0; i < p1.termCount; i++) {
        p.power[p.termCount] = p1.power[i];
        p.coeff[p.termCount] = p1.coeff[i];
        p.termCount++;
    }

    for (int i = 0; i < p2.termCount; i++) {
        bool found = false;
        for (int j = 0; j < p.termCount; j++) {
            if (p2.power[i] == p.power[j]) {
                p.coeff[j] += p2.coeff[i];
                found = true;
                break;
            }
        }
        if (!found) {
            p.power[p.termCount] = p2.power[i];
            p.coeff[p.termCount] = p2.coeff[i];
            p.termCount++;
        }
    }
}


Polynomial multiplyPolynomials(const Polynomial& p1, const Polynomial& p2) {
    Polynomial p;
    p.termCount = 0;

    for (int i = 0; i < p1.termCount; i++) {
        for (int j = 0; j < p2.termCount; j++) {
            int newPower = p1.power[i] + p2.power[j];
            int newCoeff = p1.coeff[i] * p2.coeff[j];
            bool found = false;
            for (int k = 0; k < p.termCount; k++) {
                if (p.power[k] == newPower) {
                    p.coeff[k] += newCoeff;
                    found = true;
                    break;
                }
            }
            if (!found) {
                p.power[p.termCount] = newPower;
                p.coeff[p.termCount] = newCoeff;
                p.termCount++;
            }
        }
    }
    return p;
}


int main() {
    std::cout << "enter polonomialfirist:\n";
    getPolynomial(p1);

    std::cout << "enter polonomial secend:\n";
    getPolynomial(p2);

    std::cout << "polonomial firist: ";
    displayPolynomial(p1);

    std::cout << "polonomial secend:";
    displayPolynomial(p2);

    addPolynomials(p1, p2, p3);
    std::cout << "sum polonomials: ";
    displayPolynomial(p3);

    p4 = multiplyPolynomials(p1, p2);
    std::cout <<"zarb polonomials:";
    displayPolynomial(p4);

    return 0;
}