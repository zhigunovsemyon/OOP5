#include "object.h"
#include <iostream>
#include <string_view>

class Double : public Object {
public:
	Double(double n = 0) : n_{n} {}

	Double const & print(std::ostream & ost = std::cout) const override
	{
		ost << n_;
		return *this;
	}

	Double & read(std::istream & ist = std::cin) override
	{
		ist >> n_;
		return *this;
	}

	std::string_view type() override { return "Double"; }

private:
	double n_;
};

class Int : public Object {
public:
	Int(int n = 0) : n_{n} {}

	Int const & print(std::ostream & ost = std::cout) const override
	{
		ost << n_;
		return *this;
	}

	Int & read(std::istream & ist = std::cin) override
	{
		ist >> n_;
		return *this;
	}

	std::string_view type() override { return "Int"; }

private:
	int n_;
};

int main()
{
	Int i1;
	Double i2;
	std::cin >> i1;
	i2.read();

	std::cout << i1 << ' ' << i1.id() << ' ' << i1.type() << '\n';
	std::cout << i2 << ' ' << i2.id() << ' ' << i2.type() << '\n';
	return 0;
}
