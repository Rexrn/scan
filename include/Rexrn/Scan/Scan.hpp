#pragma once

#include <cinttypes>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>

namespace rexrn_scan
{

struct scan_result
{
	std::size_t progress = 0;
	std::size_t required = 0;
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

	bool opt = false;
};


namespace details
{

template <typename TFwdIt>
std::vector<scan_fmt_element> parse_fmt_elements(TFwdIt fmt_beg, TFwdIt fmt_end)
{
	// TODO: implement this.
	return {};
}

template <typename TFwdIt>
struct single_scan_result
{
	TFwdIt it;
	bool success = false;
};

template <typename TFwdIt, typename TArg1st, typename... TArgs>
single_scan_result<TFwdIt> try_scan(
	TFwdIt src_beg, TFwdIt src_end,
	scan_fmt_element const & fmt_,
	std::tuple<TArg1st*, TArgs*...> const& args_
	)
{
	// TODO: implement this.
	return {};
}

}


template <typename TFwdIt, typename TArg1st, typename... TArgs>
scan_result scan(
	TFwdIt src_beg, TFwdIt src_end,
	TFwdIt fmt_beg, TFwdIt fmt_end,
	TArg1st& arg1st, TArgs&... args
	)
{
	auto args_tuple = std::make_tuple(&arg1st, (&args)...);

	auto fmt_elements = details::parse_fmt_elements(fmt_beg, fmt_end);

	std::size_t fid = 0;

	scan_result result;
	// Count how many format elements are required.
	result.required = std::count_if(fmt_elements.begin(), fmt_elements.end(),
			[](auto const& f) { return !f.opt; }
		);

	for(auto it = src_beg; it != src_end || fid >= fmt_elements.size(); ++it)
	{
		auto const& f = fmt_elements[fid];
		auto single_scan_result = details::try_scan(it, src_end, f, args_tuple);
		if(single_scan_result.success)
		{
			it = single_scan_result.it;
			++result.progress;
		}
		else
		{
			if (f.opt)
				++fid;
			else
				break;
		}
	}

	return result;
}

}
