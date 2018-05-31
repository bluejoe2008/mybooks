#include <iostream> 
#include <string> 
using namespace std;

#ifndef __WEAPON__
#define __WEAPON__

/////////////////////兵器/////////////////////
class Weapon
{
private:
	string _name; //兵器名
	int _power; //威力
public:
	Weapon();
	Weapon(string name, int power);
	friend class Actor;
};

/////////////////////角色/////////////////////
class Actor
{
protected:
	string _name; //姓名
	bool _gender; //性别
private:
	Weapon _weapon; //佩带兵器
public:
	Actor();
	virtual ~Actor();
	Actor(string name, bool gender);
	void operator += (Weapon & weapon);

	inline virtual void say();
	void say(string message);
	void showWeapon();
	string getName() const {return _name;}
	bool getGender() const {return _gender;}

	Actor::Actor(string name)
	:_name(name), _gender(true)
{
	cout << _name << "出现..." << endl;
}

	friend class Monster;
	//friend ostream & operator<<(ostream & os, const Actor & actor);
};

#endif