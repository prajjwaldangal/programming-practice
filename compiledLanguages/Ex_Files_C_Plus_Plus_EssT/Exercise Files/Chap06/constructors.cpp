// constructors.cpp by Bill Weinman <http://bw.org/>
// updated 2020-08-30
#include <cstdio>
#include <string>

const std::string unk = "unknown";
const std::string clone_prefix = "clone-";

// -- interface --
class Animal {
    std::string a_type = "";
    std::string a_name = "";
    std::string a_sound = "";
public:
    Animal();   // default constructor
    Animal(const std::string & type, const std::string & name, const std::string & sound);
    Animal(const Animal &); // copy constructor
    ~Animal();  // destructor
    Animal & operator = (const Animal &); // copy operator
    void print() const;
};

// -- implementation --
Animal::Animal() : a_type(unk), a_name(unk), a_sound(unk) {
    puts("default constructor");
}

Animal::Animal(const std::string & type, const std::string & name, const std::string & sound)
: a_type(type), a_name(name), a_sound(sound) {
    puts("constructor with arguments");
}

Animal::Animal(const Animal & a) {
    puts("copy constructor");
    a_name = clone_prefix + a.a_name;
    a_type = a.a_type;
    a_sound = a.a_sound;
}

Animal::~Animal() {
    printf("destructor: %s the %s\n", a_name.c_str(), a_type.c_str());
    a_name = "";
    a_type = "";
    a_sound = "";

}

Animal & Animal::operator = (const Animal & o) {
    puts("assignment operator");
    if(this != &o) {
        a_name = clone_prefix + o.a_name;
        a_type = o.a_type;
        a_sound = o.a_sound;
    }
    return *this;
}

void Animal::print () const {
    printf("%s the %s says %s\n", a_name.c_str(), a_type.c_str(), a_sound.c_str());
}

class foo {
    int ia;
    int ib;
    int ic;
    public:
        void set_ia(int r) {
            ia = r;
        }
        int get_ia() {
            return ia;
        }
};

struct bar {
    int ia;
    int ib;
    int ic;
};

int main() {
    Animal a;
    a.print();
    
    const Animal b("cat", "pheogos", "meow");
    b.print();
    
    const Animal c = b;
    c.print();
    
    a = c;
    a.print();
    bar br = {1,2,3};
    printf("ia: %d, ib: %d, ic: %d\n", br.ia, br.ib, br.ic);
    foo f;
    f.set_ia(15);
    printf("ia: %d\n", f.get_ia());
    puts("end of main");
    return 0;
}
