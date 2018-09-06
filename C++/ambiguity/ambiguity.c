#include <iostream>
using namespace std;
class A {
    public:
        void f() {
            cout << "Hello A World\n" << endl;
        }
};

class B {
    public:
        void f() {
            cout << "Hello B World\n" << endl;
        }
        void g();
};

class C : public A, public B {
    public:
        void f() {
            cout << "Hello C World\n" << endl;
        }
        void g();
        void h();

};

int main() {
    C c;
    c.A::f();
    c.B::f();
    c.C::f();
    c.f();
}
