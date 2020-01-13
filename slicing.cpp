/*#include<iostream> 
using namespace std; 
  
class Derived; 
  
class Base { 
private: 
    virtual void fun() { cout << "Base Fun"; } 
}; 
  
class Derived: public Base { 
public: 
    void fun() { cout << "Derived Fun"; } 
}; 
  
int main() 
{ 
   Base *ptr = new Derived; 
   ptr->fun(); 
   return 0; 
} */




/****************************************************************VIRTUAL DESTRUCTOR USING SHARED POINTER***************************************************/

// Program to show the order of destruction of objects using 
// shared_ptr 
/*#include <iostream> 
#include <memory> 
using namespace std; 

class Base { 
public: 
	Base() 
	{ 
		cout << "Constructing Base" << endl; 
	} 
	~Base() 
	{ 
		cout << "Destructing Base" << endl; 
	} 
}; 

class Derived : public Base { 
public: 
	Derived() 
	{ 
		cout << "Constructing Derived" << endl; 
	} 
	~Derived() 
	{ 
		cout << "Destructing Derived" << endl; 
	} 
}; 

int main() 
{ 
	std::shared_ptr<Base> sp{ new Derived }; 

	// make_shared can also be used to create sp. 
	// std::shared_ptr<Base> sp{std::make_shared<Derived>()}; 
	// Use sp 
} 
*/
//

// Program to show exception to this behavior while using 
// shared_ptr 
/*#include <iostream> 
#include <memory> 
using namespace std; 
  
class Base { 
public: 
    Base() 
    { 
        cout << "Constructing Base" << endl; 
    } 
    ~Base() 
    { 
        cout << "Destructing Base" << endl; 
    } 
}; 
  
class Derived : public Base { 
public: 
    Derived() 
    { 
        cout << "Constructing Derived" << endl; 
    } 
    ~Derived() 
    { 
        cout << "Constructing Derived" << endl; 
    } 
}; 
  
int main() 
{ 
    Base* p = new Derived{}; 
    std::shared_ptr<Base> sp{ p }; 
} */

//Here, if the shared_ptr is initialised from Base* (here ‘p’), then this magical behavior of smart destruction will not be achieved as this will call Base::~Base() and not Derived::~Derived(). The shared_ptr will not able to find out the exact type of the object which is being pointed to by ‘p’. So in this case, the magic does not happen.




// Thanks to Venki for suggesting this code. 
#include <iostream> 
using namespace std; 

class Empty 
{}; 

class Derived1 : public Empty 
{}; 

class Derived2 : virtual public Empty 
{}; 

class Derived3 : public Empty 
{	 
	char c; 
}; 

class Derived4 : virtual public Empty 
{ 
	char c; 
}; 

class Dummy 
{ 
	char c; 
}; 

int main() 
{ 
	cout << "sizeof(Empty) " << sizeof(Empty) << endl; 
	cout << "sizeof(Derived1) " << sizeof(Derived1) << endl; 
	cout << "sizeof(Derived2) " << sizeof(Derived2) << endl; 
	cout << "sizeof(Derived3) " << sizeof(Derived3) << endl; 
	cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;	 
	cout << "sizeof(Dummy) " << sizeof(Dummy) << endl; 

	return 0; 
} 


