#include <iostream>
#include "object.h"

class Int : public Object{
public:
	Int(int n = 0) : n_{n} {}

private:
	int n_;
};

int main()
{
	Int i1{2},i2{3},i3{4};
	i1.id();
	i2.id();
	i3.id();
	return 0;
}
