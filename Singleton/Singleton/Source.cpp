
#include <iostream>
using namespace std;

/* Place holder for thread synchronization mutex */
class Mutex
{   /* placeholder for code to create, use, and free a mutex */
};

/* Place holder for thread synchronization lock */
class Lock
{
public:
	Lock(Mutex& m) : mutex(m) { /* placeholder code to acquire the mutex */ }
	~Lock() { /* placeholder code to release the mutex */ }
private:
	Mutex & mutex;
};

class Singleton
{
public:
	// method to get instance of object 
	static Singleton* GetInstance();
	int a;
	~Singleton() { cout << "In Dtor" << endl; }

private:
	// private constructor for Singleton pattern 

	Singleton(int _a) : a(_a) { cout << "In Ctor" << endl; }


	static Mutex mutex;

	// Not defined, to prevent copying
	Singleton(const Singleton&);
	Singleton& operator =(const Singleton& other);
};

Mutex Singleton::mutex;

// implementation of get instace method :
//return instance of single object 
Singleton* Singleton::GetInstance()
{
	Lock lock(mutex);

	cout << "Get Inst" << endl;

	// Initialized during first access
	static Singleton inst(1);

	return &inst;
}

int main()
{
	// Since single instance cannot use "new " operator  
	// intance is assigned to GetInstance method  which returns "Singleton Object "

	Singleton* singleton = Singleton::GetInstance();

	// get value of varible "a" from instance which has public acesss 

	cout << "The value of the singleton: " << singleton->a << endl;
	cin.get();
	return 0;
}

