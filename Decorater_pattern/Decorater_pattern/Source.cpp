#include <iostream>
#include <string>



std::string c(const std::string cls) {
	return "\n" + cls + " Constructor";
}
std::string d(const std::string cls) {
	return "\n" + cls + " Destructor";
}

/*Base component class*/
class Sandwich
{
public:
	virtual ~Sandwich() { }
	virtual double getCost() = 0;
	virtual std::string getDesc() = 0;
};

/*Concrete component class*/
class WheatBread :public Sandwich
{
public:
	WheatBread() {

	}
	~WheatBread() {

	}
	std::string getDesc()
	{
		return "Wheat Bread";
	}

	double getCost()
	{
		return 2.0;
	}
};

/*Concrete component class*/
class WholeGrainBread :public Sandwich
{
public:
	WholeGrainBread() {

	}
	~WholeGrainBread() {

	}
	std::string getDesc()
	{
		return "WholeGrain Bread";
	}

	double getCost()
	{
		return 3.0;
	}
};

/*Concrete component class*/
class ItalianBread :public Sandwich
{
public:
	ItalianBread() {

	}
	~ItalianBread() {

	}
	std::string getDesc()
	{
		return "Italian Bread";
	}

	double getCost()
	{
		return 2.5;
	}
};

/*Decorator Base class*/
class SubDecorator : public Sandwich
{
	Sandwich *sandwich;
public:
	SubDecorator(Sandwich *sandwichRef)
	{

		sandwich = sandwichRef;
	}

	~SubDecorator() {

		delete sandwich;
	}
	double getCost()
	{
		return sandwich->getCost();
	}
	std::string getDesc()
	{
		return sandwich->getDesc();
	}
};

/*Decorator concrete class*/
class CheeseDecorator :public SubDecorator
{
private:
	std::string cheese_desc()
	{
		return " + Cheese";
	}

	double cheese_cost;

public:
	CheeseDecorator(Sandwich *sandwich) :SubDecorator(sandwich)
	{

		cheese_cost = 3.0;
	}

	~CheeseDecorator() {

	}
	std::string getDesc()
	{
		return SubDecorator::getDesc().append(cheese_desc());
	}

	double getCost()
	{
		return SubDecorator::getCost() + cheese_cost;
	}
};

/*Decorator concrete class*/
class VegDecorator :public SubDecorator
{
private:
	std::string veg_desc()
	{
		return " + Veg";
	}

	double veg_cost;

public:
	VegDecorator(Sandwich *sandwich) :SubDecorator(sandwich)
	{

		veg_cost = 2.0;
	}

	~VegDecorator() {

	}
	std::string getDesc()
	{
		return SubDecorator::getDesc().append(veg_desc());
	}

	double getCost()
	{
		return SubDecorator::getCost() + veg_cost;
	}
};

/*Decorator concrete class*/
class SauceDecorator :public SubDecorator
{
private:
	std::string sauce_desc()
	{
		return " + Sauce";
	}

	double sauce_cost;

public:
	SauceDecorator(Sandwich *sandwich) :SubDecorator(sandwich)
	{

		sauce_cost = .5;
	}

	~SauceDecorator() {

	}
	std::string getDesc()
	{
		return SubDecorator::getDesc().append(sauce_desc());
	}

	double getCost()
	{
		return SubDecorator::getCost() + sauce_cost;
	}
};

int main()
{
	Sandwich *sandwich = new CheeseDecorator(new WheatBread());
	sandwich = new VegDecorator(sandwich);
	sandwich = new SauceDecorator(new SubDecorator(sandwich));
	std::cout << "\nYour sandwich is " << sandwich->getDesc() << " and costs $" << sandwich->getCost();
	delete sandwich;
	std::cin.get();
	return 0;
}