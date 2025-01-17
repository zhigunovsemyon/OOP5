#pragma once
#include "object.h"

class Double : public CObject {
public:
	~Double() override { delete n_; }

	Double(Double const & i) : n_{new double{*i.n_}} {}

	Double(double n = 0) : n_{new double{n}} {}

	Double & operator=(Double const & i)
	{
		*n_ = *i.n_;
		return *this;
	}

	Double const & print(std::ostream & ost) const override
	{
		ost << *n_;
		return *this;
	}

	Double & add(Object const & other) override
	{
		auto cmp{dynamic_cast<Double const *>(&other)};
		if (nullptr == cmp)
			throw Object::exceptions::NOT_MATCHING_DERIVED;

		*n_ += *(cmp->n_);
		return *this;
	}

	Double & read(std::istream & ist) override
	{
		ist >> *n_;
		return *this;
	}

	std::string_view type() const override { return "Double"; }

	bool equal(Object const & i) const noexcept(false) override
	{
		auto cmp{dynamic_cast<Double const *>(&i)};
		if (nullptr == cmp)
			throw Object::exceptions::NOT_MATCHING_DERIVED;

		return *n_ == *(cmp->n_);
	}

	int compare(CObject const & other) const noexcept(false) override
	{
		auto cmp{dynamic_cast<Double const *>(&other)};
		if (nullptr == cmp)
			throw Object::exceptions::NOT_MATCHING_DERIVED;

		auto diff{*n_ - *cmp->n_};
		return (diff > 0) ? 1 : (diff < 0) ? -1 : 0;
	}

private:
	double * n_;
};
