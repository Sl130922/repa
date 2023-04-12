#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Car {
public:
    Car(std::string model, std::string brand) : car_model(model), car_brand(brand) {}
    virtual ~Car() {};
protected:
    std::string const car_model;
    std::string const car_brand;
};

class Mercedes : public Car {
public:
    Mercedes(std::string model, std::string brand) : Car(brand, model) {}
    virtual ~Mercedes() {
        std::cout << "Марка авто: " << car_brand << " | Модель авто: " << car_model << std::endl;
    }
};

class BMW : public Car {
public:
    BMW(std::string model, std::string brand) : Car(brand, model) {}
    virtual ~BMW() {
        std::cout << "Марка авто: " << car_brand << " | Модель авто: " << car_model << std::endl;
    }
};

class Nissan : public Car {
public:
    Nissan(std::string model, std::string brand) : Car(brand, model) {}
    virtual ~Nissan() {
        std::cout << "Марка авто: " << car_brand << " | Модель авто: " << car_model << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");
    std::ifstream file;
    std::vector <Car*> garage;
    file.open("Cars.txt");
    std::string brand;
    std::string model;
    if (file.is_open()) {

        while (!file.eof()) {
            file >> brand;
            file >> model;

            if (brand == "Mercedes") {
                garage.emplace_back(new Mercedes(brand, model));
            }
            if (brand == "BMW") {
                garage.emplace_back(new BMW(brand, model));
            }
            if (brand == "Nissan") {
                garage.emplace_back(new Nissan(brand, model));
            }
        }
    }
    for (int i = 0; i < garage.size(); ++i) {
        delete garage[i];
        garage[i] = 0;
    }
    return 0;
}


