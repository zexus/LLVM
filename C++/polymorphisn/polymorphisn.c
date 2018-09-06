#include<iostream>
using namespace std;
//基类对象
class Base
{
public:
	//有virtual关键字，运行时多态
	virtual void f(float x)
	{
		cout<<"Base::f(float)"<< x <<endl;
	}
    //无viratul关键字，不会发生运行时多态
	void g(float x)
	{
		cout<<"Base::g(float)"<< x <<endl;
	}
	void h(float x)
	{
		cout<<"Base::h(float)"<< x <<endl;
	}
};

class Derived : public Base
{
public:
	virtual void f(float x)
	{
		cout<<"Derived::f(float)"<< x <<endl;   //多态、覆盖
	}
    //子类与父类的函数同名，无virtual关键字，则为隐藏
	void g(int x)
	{
		cout<<"Derived::g(int)"<< x <<endl;     //隐藏
	}
	void h(float x)
	{
		cout<<"Derived::h(float)"<< x <<endl;   //隐藏
	}
};

int main(void)
{
	Derived d;	//子类
	Base *pb = &d;	//基类指针指向子类
	Derived *pd = &d;	//子类指针指向自己
	// Good : behavior depends solely on type of the object
	pb->f(3.14f);   // Derived::f(float) 3.14	调用子类，多态
	pd->f(3.14f);   // Derived::f(float) 3.14	调用子类
	// Bad : behavior depends on type of the pointer
	pb->g(3.14f);   // Base::g(float)  3.14	无多态，调用自己的
	pd->g(3.14f);   // Derived::g(int) 3 	无多态，调用自己的
	// Bad : behavior depends on type of the pointer
	pb->h(3.14f);   // Base::h(float) 3.14	无多态，调用自己的
	pd->h(3.14f);   // Derived::h(float) 3.14	无多态，调用自己的
	return 0;
}
