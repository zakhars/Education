#include <blackbox/blackbox.hpp>

namespace blackbox
{
	BlackBox::BlackBox(const std::string& config) 
	{}
	
	BlackBox::~BlackBox() 
	{}
	
	int BlackBox::call(const int contract_index, const double bid, const double ask)
	{
		return contract_index + int(bid) + int(ask);
	}
}
