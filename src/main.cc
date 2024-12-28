#include "object.h"
#include <iostream>

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

private:
	int n_;
};

int main()
{
	Int i1, i2, i3;
	std::cin >> i1;
	i2.read();
	std::cin >> i3;

	std::cout << i1 << ' ' << i1.id() << '\n';
	std::cout << i2 << ' ' << i2.id() << '\n';
	i3.print();
	std::cout << ' ' << i3.id() << '\n';
	return 0;
}
