#include<iostream>
#include<exception>//    #include<stdexcept>
#include<windows.h>
using namespace std;
class OverSpeedException : public exception
{
	int speed;
	public:
	const char* what() // overide
	{
		return "Over Speed Exception Raised : check out car speed";
	}
	OverSpeedException(int speed)
	{
		this->speed = speed;
	}
	void getspeed()
	{
		cout<<"Your Car Speed is : "<<speed<<endl;
	}		
};// OverSpeedException Class end
class Car
{
	int speed;
	public:
	Car()
	{
		speed=0;
		cout<<"Car Speed is "<<speed<<endl;
	}
	void runCar()
	{
		for(; ;)  // while(1)
		{
			speed +=10;
			cout<<"Car Speed is "<<speed<<endl;
			Sleep(1500);
			if(speed>=120)
			{
				throw OverSpeedException(speed);
			}
		}	
	}				
};
int main()
{
	Car c1;
	try
	{
		c1.runCar();
	}
	catch(OverSpeedException &err)
	{
		cout<<err.what()<<endl;
		err.getspeed();
	}
	cout<<"Your Car Engine is OFF \n";
	cout<<"Dont Drive and Drink !!\n";
	cout<<"Happy Journey !!";
	return 0;
}