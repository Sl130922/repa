#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>  
#include <fstream>  
#include <string>  
#include <vector>  
#include <sstream>  
#include <algorithm>


class Employee {
private:
    const std::string _name;
    const int _age;
    const std::string _position;
    int _group;
public:
    Employee(const std::string& name, const int& age, const std::string& position, const int& group) : _name(name), _age(age), _position(position), _group(group) {}

    int getage() const {
        return _age;
    }
    std::string getPosition() const {
        return _position;
    }
    void printAll() const {
        std::cout << _name << ", " << _age << ", " << _position << ", " << "группа " << _group << std::endl;
        std::cout << std::endl;
    }
};

class Database {
private:
    std::vector<Employee*> employees;
public:
    void addEmployee(Employee* e) {
        employees.push_back(e);
    }

    void printAllEmployees() const {
        for (const auto& employee : employees) {
            employee->printAll();
        }
    }

    void printAllEngineers() const {
        std::for_each(employees.begin(), employees.end(), [](const Employee* e) {
            if (e->getPosition() == "инженер") {
                e->printAll();
            }
            });
    }
    void printAllNonPresidents() const {
        std::vector<Employee*> nonPresidents;
        for (const auto& employee : employees) {
            if (employee->getPosition() != "председатель") {
                nonPresidents.push_back(employee);
            }
        }
        std::sort(nonPresidents.begin(), nonPresidents.end(), [](const Employee* a, const Employee* b) {
            return a->getage() < b->getage();
            });

        for (const auto& employee : nonPresidents) {
            employee->printAll();
        }
    }
    ~Database() {
        for (const auto& employee : employees) {
            delete employee;
        }
    }
};
int main() {
    setlocale(LC_ALL, "RUS");
    Database db;
    std::string _name, _position, _groupM;
    int _age, _group;
    std::string path = "bd.txt";
    std::ifstream file;
    file.open(path);
    if (!file.is_open()) {
        std::cout << "Error" << std::endl;
    }
    else
    {
        std::cout << "Open!" << std::endl;
        std::string line;
        while (getline(file, line)) {
            std::stringstream ss(line);
            getline(ss, _name, ',');
            ss >> _age >> std::ws;
            getline(ss, _position, ',');
            ss >> _groupM >> std::ws;
            ss >> _group;
            Employee* e = new Employee(_name, _age, _position, _group);
            db.addEmployee(e);
        }
        file.close();
    }
    std::cout << "Общая база данных:" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    db.printAllEmployees();
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Информация об инженерах:" << std::endl;
    std::cout << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    db.printAllEngineers();
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Информация о всех не председателях:" << std::endl;
    std::cout << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    db.printAllNonPresidents();
    return 0;
}