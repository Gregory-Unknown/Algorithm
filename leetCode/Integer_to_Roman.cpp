#include <iostream>
#include <map>

std::string intToRoman(int num) {
    std::map<int, std::string> m;
    m[1] = "I";
    m[4] = "IV";
    m[5] = "V";
    m[9] = "IX";
    m[10] = "X";
    m[40] = "XL";
    m[50] = "L";
    m[90] = "XC";
    m[100] = "C";
    m[400] = "CD";
    m[500] = "D";
    m[900] = "CM";
    m[1000] = "M";

    std::string s = "";
    if (num < 1 || num > 3999) return "";
    std::map<int, std::string>::iterator it = --m.end();
    int i = 0;
    while (num > 0) {
        while (num >= it->first) {
            num -= it->first;
            s += it->second;
        }
        if (num >= 1)
            --it;
    }
    return s;
}

int main() {
    std::cout << intToRoman(3) <<  std::endl;
    std::cout << intToRoman(58) <<  std::endl;
    std::cout << intToRoman(1994) <<  std::endl;
    std::cout << intToRoman(3999) <<  std::endl;
}