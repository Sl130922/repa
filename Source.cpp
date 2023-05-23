#include <iostream> 
#include <vector> 

class Detail {
protected:
    Detail() {}
public:
    virtual ~Detail() {}
    template<typename T>
    friend void add_to_vector(std::vector<Detail*>& v);
};

class Build : public Detail {
protected:
    Build() = default;
public:
    virtual ~Build() {}
    template<typename T>
    friend void add_to_vector(std::vector<Detail*>& v);
};

template<typename T>
void add_to_vector(std::vector<Detail*>& v) {
    v.push_back(new T());
}

int main(int argc, char* argv[]) {
    std::vector<Detail*> dt;
    add_to_vector<Detail>(dt);
    add_to_vector<Build>(dt);
    for (Detail* c : dt) {
        delete c;
    }
    dt.clear();
    return 0;
}