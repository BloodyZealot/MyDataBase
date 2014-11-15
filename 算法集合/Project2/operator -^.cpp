#include<iostream>
#include<string>
#include<thread>

using namespace std;

template<typename T>
class pointer
{
public:
	pointer() :data(0){}
	pointer(T* ptr) :data(ptr){}
	pointer(pointer<T>& p1) :data(p1.data){
		p1.data = 0;
	}
	~pointer(){
		delete data;
	}
	T& operator*(){
		return *data;
	}
	T* operator->(){
		return data;
	}
private:
	T* data;
};

int main()
{
	pointer<string> p1(new string("data"));
	pointer<string> p2(p1);
	cout << *p2 << endl << (p2->size());
	return 0;
}