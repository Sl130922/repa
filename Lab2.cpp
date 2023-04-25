#include <iostream>
#include<string>
#include<vector>

class Class1 {
public:
	virtual Class1* clone() { return new Class1(*this); };
	virtual ~Class1() {};
};
class Class2 : public Class1 {
	Class1* clone() {
		return new Class2(*this);
	}
	virtual ~Class2() {};
};

void copy(std::vector<Class1*>& bd, Class1& obj) {
	bd.push_back(obj.clone());
}


int main()
{
	std::vector<Class1*> bd;
	Class1* obj1 = new Class1();
	Class2* obj2 = new Class2();
	copy(bd, *obj1);
	copy(bd, *obj2);
	for (Class1* obj : bd) {
		std::cout << typeid(*obj).name() << std::endl;
		delete obj;
	}
	return 0;
	std::cout << obj1;
}

