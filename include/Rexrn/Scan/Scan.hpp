#pragma once

#include <cinttypes>
#include <utility>
#include <vector>

namespace rexrn_scan
{

struct scan_result
{
	std::size_t progress;
	std::size_t required;
};

struct scan_fmt_element
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
std::vector<scan_fmt_element> parse_fmt_elements(TInputIt fmt_beg, TInputIt fmt_end)
{
	// TODO: implement this.
	return {};
}

}


template <typename TInputIt>
scan_result scan(
	TInputIt srcBeg_, TInputIt srcEnd_,
	TInputIt fmtBeg_, TInputIt fmtEnd_)
{
	auto fmt_elements = details::parse_fmt_elements(fmtBeg_, fmtEnd_);
	// TODO: implement this.
	return {};
}

}
