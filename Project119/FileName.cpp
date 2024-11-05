#include <iostream>
using namespace std;

// Базовий клас ОСОБА
class OSOBA {
public:
    int age; 

public:
    OSOBA(int a = 0) : age(a) {} // Конструктор

    virtual void changeAge(int newAge) {
        age = newAge;
        cout << "Вік змінено на: " << age << endl;
    }

    void displayAge() const {
        cout << "Вік особи: " << age << endl;
    }
};

class STUDENT : public OSOBA {
private:
    int course; 

public:
    STUDENT(int a = 0, int c = 1) : OSOBA(a), course(c) {} // Конструктор

    // перехід на наступний курс
    void changeAge(int newAge) override {
        OSOBA::changeAge(newAge); // Виклик функції базового класу
        course++; 
        cout << "Студент переходить на курс: " << course << endl;
    }

    void displayCourse() const {
        cout << "Курс: " << course << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ukr");
    OSOBA* person = new OSOBA(18);
    person->displayAge(); 
    person->changeAge(19); 

    // клас STUDENT
    STUDENT* student = new STUDENT(18, 1);
    student->displayAge(); 
    student->displayCourse(); 
    student->changeAge(19); 

    // pol
    OSOBA* ptr = student; 
    ptr->displayAge(); //пізнє зв'язування 
    ptr->changeAge(20); 
    ptr->changeAge(21);

    delete person;
    delete student;
    return 0;
}