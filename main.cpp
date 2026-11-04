#include <iostream>

#include <string>

#include <vector>

using namespace std;

class Employee {

protected:

    string name;

    int age;

    double baseSalary;

public:

    Employee(string name, int age, double baseSalary) {

        this->name = name;

        this->age = age;

        this->baseSalary = baseSalary;

    }

    virtual void printInfo() {

        cout << «Name: « << name << endl;

        cout << «Age: « << age << endl;

        cout << «Base salary: « << baseSalary << endl;

    }

    virtual double calculateSalary() {

        return baseSalary;

    }

    virtual ~Employee() {}

};

class Manager : public Employee {

private:

    int teamSize;

public:

    Manager(string name, int age, double baseSalary, int teamSize)

        : Employee(name, age, baseSalary) {

        this->teamSize = teamSize;

    }

    void printInfo() override {

        Employee::printInfo();

        cout << «Team size: « << teamSize << endl;

    }

    double calculateSalary() override {

        return baseSalary + teamSize * 1000;

    }

};

class Developer : public Employee {

private:

    string programmingLanguage;

    int completedProjects;

public:

    Developer(string name, int age, double baseSalary,

              string programmingLanguage, int completedProjects)

        : Employee(name, age, baseSalary) {

        this->programmingLanguage = programmingLanguage;

        this->completedProjects = completedProjects;

    }

    void printInfo() override {

        Employee::printInfo();

        cout << «Programming language: «

             << programmingLanguage << endl;

        cout << «Completed projects: «

             << completedProjects << endl;

    }

    double calculateSalary() override {

        return baseSalary + completedProjects * 1500;

    }

};

class Intern : public Employee {

private:

    int internshipMonths;

public:

    Intern(string name, int age, double baseSalary, int internshipMonths)

        : Employee(name, age, baseSalary) {

        this->internshipMonths = internshipMonths;

    }

    void printInfo() override {

        Employee::printInfo();

        cout << «Internship months: «

             << internshipMonths << endl;

    }

    double calculateSalary() override {

        if (internshipMonths > 6) {

            return baseSalary + 2000;

        }

        return baseSalary;

    }

};

int main() {

    vector<Employee*> employees;

    employees.push_back(new Employee(«Petro», 30, 25000));

    employees.push_back(new Manager(«Olena», 35, 40000, 8));

    employees.push_back(new Developer(«Andrii», 27, 35000, «C++», 5));

    employees.push_back(new Intern(«Maria», 20, 10000, 7));

    for (Employee* employee : employees) {

        cout << «\n———————« << endl;

        employee->printInfo();

        cout << «Final salary: «

             << employee->calculateSalary() << endl;

    }

    for (Employee* employee : employees) {

        delete employee;

    }

    return 0;

}
