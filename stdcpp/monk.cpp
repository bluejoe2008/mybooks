#include "monk.h"

Monk::Monk(string name, string monkName)
	:Actor(name, true), _monkName(monkName)
{
}

Monk::~Monk()
{
	Actor::say("°¢ÃÖÍÓ·ğ£¬Æ¶É®È¥Ò²...");
}

void Monk::say()
{
	Actor::say("°¢ÃÖÍÓ·ğ£¬Æ¶É®ÄË" + _monkName + "ÊÇÒ²...");
}

void Monk::patter()
{
	cout << _name << ": ††ÂïÄØ°Èßä…Ë..." << endl;
}

void Monk::setName(string name)
{
	_name  = name;
	cout << "Monk::setName()... " << endl;
	cout << "_name: " << _name << endl;
}
