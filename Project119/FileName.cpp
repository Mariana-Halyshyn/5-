#include <iostream>
using namespace std;

// ������� ���� �����
class OSOBA {
public:
    int age; 

public:
    OSOBA(int a = 0) : age(a) {} // �����������

    virtual void changeAge(int newAge) {
        age = newAge;
        cout << "³� ������ ��: " << age << endl;
    }

    void displayAge() const {
        cout << "³� �����: " << age << endl;
    }
};

class STUDENT : public OSOBA {
private:
    int course; 

public:
    STUDENT(int a = 0, int c = 1) : OSOBA(a), course(c) {} // �����������

    // ������� �� ��������� ����
    void changeAge(int newAge) override {
        OSOBA::changeAge(newAge); // ������ ������� �������� �����
        course++; 
        cout << "������� ���������� �� ����: " << course << endl;
    }

    void displayCourse() const {
        cout << "����: " << course << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ukr");
    OSOBA* person = new OSOBA(18);
    person->displayAge(); 
    person->changeAge(19); 

    // ���� STUDENT
    STUDENT* student = new STUDENT(18, 1);
    student->displayAge(); 
    student->displayCourse(); 
    student->changeAge(19); 

    // pol
    OSOBA* ptr = student; 
    ptr->displayAge(); //��� ��'�������� 
    ptr->changeAge(20); 
    ptr->changeAge(21);

    delete person;
    delete student;
    return 0;
}