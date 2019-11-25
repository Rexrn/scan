#pragma once

#include <cinttypes>
#include <utility>
#include <vector>

namespace rexrn_scan
{

struct result
{
	std::size_t progress;
	std::size_t required;
};

struct fmt_element
{
	enum type {
		integer,
		real,
		character,
		string,
		constant_characters
	} type;


};


namespace details
{

template <typename TInputIt>
std::vector<fmt_element> parse_fmt_elements(TInputIt fmt_beg, TInputIt fmt_end)
{
	// TODO: implement this.
	return {};
}

}


template <typename TInputIt>
result scan(
	TInputIt srcBeg_, TInputIt srcEnd_,
	TInputIt fmtBeg_, TInputIt fmtEnd_)
{
	auto fmt_elements = details::parse_fmt_elements(fmtBeg_, fmtEnd_);
	// TODO: implement this.
	return {};
}

}
