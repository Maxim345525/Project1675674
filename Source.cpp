#include <iostream>
#include <cstring>

using namespace std;

// Базовий клас "Рядок"
class String {
protected:
    char* str;
    int length;
public:
    // Конструктор без параметрів
    String() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    // Конструктор, що приймає як параметр C-рядок
    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Конструктор копіювання
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // Оператор присвоєння
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Отримання довжини рядка
    int getLength() const {
        return length;
    }

    // Очищення рядка
    void clear() {
        delete[] str;
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    // Деструктор
    ~String() {
        delete[] str;
    }

    // Конкатенація рядків
    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        delete[] result.str;
        result.str = new char[result.length + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    // Перевантажений оператор +=
    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }

    // Перевірка на рівність
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    // Перевірка на нерівність
    bool operator!=(const String& other) const {
        return !(*this == other);
    }
};

// Похідний клас "Бітовий рядок"
class BitString : public String {
public:
    // Конструктор без параметрів
    BitString() : String() {}

    // Конструктор, що приймає як параметр C-рядок
    BitString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        bool valid = true;
        for (int i = 0; i < length; ++i) {
            if (s[i] != '0' && s[i] != '1') {
                valid = false;
                break;
            }
        }
        if (valid)
            strcpy(str, s);
        else {
            str[0] = '\0';
            length = 0;
        }
    }

    // Конструктор копіювання
    BitString(const BitString& other) : String(other) {}

    // Оператор присвоєння
    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }

    // Зміна знаку числа (переклад числа в додатковий код)
    void changeSign() {
        for (int i = 0; i < length; ++i) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
    }

    // Складання бітових рядків
    BitString operator+(const BitString& other) const {
        BitString result;
        String::operator+(other);
        return result;
    }

    // Перевірка на рівність
    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    // Перевірка на нерівність
    bool operator!=(const BitString& other) const {
        return String::operator!=(other);
    }
};

int main() {
    // Приклад використання класів
    String str1("Hello");
    String str2 = "World";
    String str3 = str1 + str2;

    cout << "str1: " << str1.getLength() << " " << str1 << endl;
    cout << "str2: " << str2.getLength() << " " << str2 << endl;
    cout << "str3: " << str3.getLength() << " " << str3 << endl;

    BitString bitStr1("1010");
    BitString bitStr2("1100");
    BitString bitStr3 = bitStr1 + bitStr2;

    cout << "bitStr1: " << bitStr1.getLength() << " " << bitStr1 << endl;
    cout << "bitStr2: " << bitStr2.getLength() << " " << bitStr2 << endl;
    cout << "bitStr3: " << bitStr3.getLength() << " " << bitStr3 << endl;

    return 0;
}
