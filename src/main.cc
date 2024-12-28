#include "object.h"
#include <iostream>

class Int : public Object {
public:
	Int(int n = 0) : n_{n}  {}

	Int const & print(std::ostream & ost = std::cout) const override 
	{
		ost << n_;
		return *this;
	}

private:
	int n_;
};

int main()
{
	Int i1{2}, i2{3}, i3{4};
	std::cout << i1 << ' ' << i1.id() << '\n';
	std::cout << i2 << ' ' << i2.id() << '\n';
	std::cout << i3 << ' ' << i3.id() << '\n';
	return 0;
}
