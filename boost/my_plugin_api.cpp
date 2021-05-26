#include <boost/config.hpp>
#include <boost/dll/alias.hpp>
#include <boost/shared_ptr.hpp>
#include <string>
#include <iostream>
#include "my_plugin_api.hpp"

namespace my_namespace {

class plugin_api : public my_plugin_api
{
float _agr;
public:
	plugin_api(): _agr(0) {
		std::cout<<" plugin const "<<std::endl;
	}
	static boost::shared_ptr<plugin_api> create()
	{
		return boost::shared_ptr<plugin_api>(new plugin_api);
	}
	std::string name() const 
	{
		return "plugin"; 
	}
	
	float calculate(float x, float y)
	{
		_agr += x + y;
		return _agr;
	}
	
	~plugin_api(){};
		
};

BOOST_DLL_ALIAS(
	my_namespace::plugin_api::create, plugin
	)
}