/*
mcd and gcd using recursive method
*/

#include <iostream>

int maxcd(int x, int y, int i=2) {
    if (i > x || i > y) return 1;
    if (x % i == 0 && y % i == 0) return i * maxcd(x / i, y / i, i);
    else return maxcd(x, y, i + 1);
}

//metodo di euclide che scoprirete il prossimo semestre dopo aver fatto complementi matematici per l'informatica (o come si chiama adesso)
int maxcdEuclide(int a, int b) {
    if (b == 0)
        return a;
    return mcd(b, a % b);
}

//metodo con le sottrazioni ripetute
int maxCommonDivisor(int a, int b) {
    if (a == b) {
        return a;
    } else if (a > b) {
        return maxCommonDivisor(a - b, b);
    } else {
        return maxCommonDivisor(a, b - a);
    }
}

int main() {
    int a = 56;
    int b = 98;

    std::cout << "Massimo comune divisore di " << a << " e " << b << " e': " << maxcd(a, b) << std::endl;
    std::cout << "Minimo comune divisore di " << a << " e " << b << " e': " << mincd(a, b) << std::endl;

    return 0;
}



//extra method for mincd
/*int mincd(int a, int b, int i=2) {
    if (i>=x || i>=y) return 1;
    if (x%i==0 && y%i==0) return i * eraseI(x, y, i);
    else return 1 * mincd(x, y, i+1);
}
int eraseI(int x, int y, int i) {
    if (i > x || i > y) return 1;
    if (x % i == 0 && y % i == 0) return eraseI(x / i, y / i, i);
    else return 1 * eraseI(x, y, i + 1);
}*/
