#include "actor.h"

//兵器类的构造函数
Weapon::Weapon()
{
	_name = "赤手空拳";
	_power = 1;
}


Weapon::Weapon(string name, int power)
	:_name(name), _power(power)
{
}

Actor::Actor()
{
	_name = "无名氏";
	_gender = true;

	cout << _name << "出现..." << endl;
}

Actor::~Actor()
{
	cout << _name << "至此隐退江湖..." << endl;
}

Actor::Actor(string name, bool gender)
{
	_name = name;
	_gender = gender;

	cout << _name << "出现..." << endl;
}

inline void Actor::say()
{
	cout << _name << ": 我乃" << _name << "是也..." << endl;
}

void Actor::say(string message)
{
	cout << _name << "：" << message << endl;
}

void Actor::showWeapon()
{
	cout << "佩带兵器: ";
	cout << _weapon._name << "，威力: " << _weapon._power << endl;
}

void Actor::operator += (Weapon & weapon)
{
	_weapon = weapon;
}