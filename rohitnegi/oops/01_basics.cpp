#include <iostream>
using namespace std;

class Student
{
    string name;
    int age;
    int roll_number;
    string grade;

public:
    void set_name(string name)
    {
        if (name.length() == 0)
        {
            return;
        }
        this->name = name;
    }
    void set_age(int age)
    {
        if (age < 0 || age > 100)
        {
            return;
        }
        this->age = age;
    }
    void set_roll_number(int roll_number)
    {
        this->roll_number = roll_number;
    }
    void set_grade(string grade)
    {
        this->grade = grade;
    }
    string get_grade(int pin)
    {
        if (pin == 123)
        {
            return grade;
        }
        return "Error";
    }
    void print_details()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << roll_number << endl;
        cout << "Grade: " << grade << endl;
        cout << endl;
    }
};

int main()
{
    Student s1;
    s1.set_name("Mohit Agrawal");
    s1.set_age(20);
    s1.set_roll_number(47);
    s1.set_grade("A+");
    s1.print_details();

    Student s2;
    s2.set_name("Pawan Kumar");
    s2.set_age(22);
    s2.set_roll_number(50);
    s2.set_grade("B-");
    s2.print_details();

    cout << s1.get_grade(123) << endl;
    cout << s1.get_grade(124) << endl;
    return 0;
}