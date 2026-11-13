#pragma once
#include <string>
#include "bbdll.h"

namespace blackbox
{
	class BlackBox
	{
	public:
		BBAPI explicit BlackBox(const std::string& config);
		BBAPI ~BlackBox();
		// outputs
		BBAPI int call(const int contract_index, const double bid, const double ask);
	};
}
