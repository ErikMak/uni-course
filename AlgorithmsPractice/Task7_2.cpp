/*
Author: ErikMak
Task:

Найти все анаграммы из слов-кандидатов для всех подмножеств
букв из исходного слова.
Для хранения списка слов-кандидатов используйте контейнер
std::unordered_set. Используйте второй параметр
шаблона контейнера для указания собственной хеш-функции, 
чтобы сравнивать строки без учёта порядка букв

*/

#include <iostream>
#include <string>
#include <list>
#include <unordered_set>
#include <iomanip>

struct hash {
public:
    size_t operator()(const std::string &s) const
    {
        size_t result = 1;
        for(size_t i = 0; i < s.length(); ++i) {
            result *= (s[i] + 31);
        }
        return result;
    }
};

struct comp {
public:
    bool operator()(const std::string &str1, const std::string &str2) const {
        int r_result = 0;
        for(size_t i = 0; i < str1.length(); ++i) {
            r_result += str1[i];
        }
        int l_result = 0;
        for(size_t i = 0; i < str2.length(); ++i) {
            l_result += str2[i];
        }
        
        if (r_result == l_result)
            return true;
        else
            return false;
    }
};

typedef std::unordered_set<std::string, hash, comp> Myset;

class Enumerator {
    private:
        Myset list;
    public:
        Enumerator(Myset list) {
            this->list = list;
        }
        void run(const std::string& buf, int num = 0, std::string s = "") {
            if (num == buf.length()) {
                if(s != "") {
                    std::cout << "Word: " << s << std::setw(15-s.length()) << std::boolalpha \
                    << (list.find(s) != list.end()) << '\n';
                }
                return;
            }
            std::string p = s;
            run(buf, num+1, p); 
            p += buf[num];
            run(buf, num+1, p); 
        }
};

int main() {
    Myset list;
    list.insert("inlets");
    list.insert("lestn");
    list.insert("banana");
    list.insert("nnaanb");
    list.insert("google");
    list.insert("enlists");
    list.insert("footage");
    list.insert("roodmo");
    list.insert("lorem");

    Enumerator enumeration(list);
    enumeration.run("listen");
}