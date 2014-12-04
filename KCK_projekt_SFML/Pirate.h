#pragma once
class Pirate
{
public:
	Pirate();
	~Pirate();
	void attack(int x, int y, Ship &s);

private:

	static unsigned int chance;
};

