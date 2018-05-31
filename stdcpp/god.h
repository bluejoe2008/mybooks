#include "monk.h"

/////////////////////神仙/////////////////////

class God : public Actor  
{
public:
	void printName();
	void fly(); //神仙可以飞来飞去
	God(string name, bool gender);
};

//////////////////////佛//////////////////////

class Buddha : public Actor
{
private:
	God _god;
	Monk _monk;
public:
	Buddha(string name, string monkName)
		: Actor(name, true), _monk(name, monkName), _god(name, true)
	{
	}

	void patter()
	{
		_monk.patter();
	}

	void fly()
	{
		_god.fly();
	}
};
