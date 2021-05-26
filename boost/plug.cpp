#include <boost/dll/import.hpp> // for import_alias
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include "my_plugin_api.hpp"

namespace dll = boost::dll;

int main(int argc, char* argv[]) 
{

    boost::filesystem::path lib_path(argv[1]);          // argv[1] contains path to directory with our plugin library
    boost::shared_ptr<my_plugin_api> plugin;            // variable to hold a pointer to plugin variable
	
    std::cout << "Loading the plugin" << std::endl;

    //plugin = dll::import<my_plugin_api>( lib_path / "my_plugin_api.so", "plugin", dll::load_mode::append_decorations );
	
	//std::cout << "plugin->calculate(1.5, 1.5) call:  " << plugin->calculate(1.5, 1.5) << std::endl;
	//std::cout<< plugin->name() << std::endl;
	
	typedef boost::shared_ptr<my_plugin_api> (pluginapi_t)();
	boost::function<pluginapi_t> creator;
	creator = boost::dll::import_alias<pluginapi_t>( lib_path / "my_plugin_api.so" , "plugin", dll::load_mode::append_decorations );
	
	plugin = creator();
	std::cout << "plugin->calculate(1.5, 1.5) call:  " << plugin->calculate(1.5, 1.5) << std::endl;
	std::cout << "plugin->calculate(1.5, 1.5) call:  " << plugin->calculate(1.5, 1.5) << std::endl;
	std::cout<< plugin->name() << std::endl;
	
}