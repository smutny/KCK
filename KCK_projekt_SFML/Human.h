#pragma once
class Human
{
private:
	int price;
	bool bought;
public:
	Human();
	~Human();
	virtual void action();
	void SetPrice(int price);
	int GetPrice();
	void SetBoolTrue();
	void SetBoolFalse();
	bool GetBool();
};

