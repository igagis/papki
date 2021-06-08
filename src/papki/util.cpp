#include "util.hpp"

#include <utki/debug.hpp>

using namespace papki;

bool papki::is_dir(const std::string& path_name){
    return path_name.length() != 0 && path_name.back() == '/';
}

std::string papki::not_dir(const std::string& path_name){
    size_t slashPos = path_name.rfind('/');
	if(slashPos == std::string::npos){ // no slash found
		return path_name;
	}

	ASSERT(slashPos > 0)
	ASSERT(path_name.size() > 0)
	ASSERT(path_name.size() >= slashPos + 1)

	return std::string(path_name, slashPos + 1);
}

std::string papki::dir(const std::string& path_name){
    size_t slashPos = path_name.rfind('/');
	if(slashPos == std::string::npos){ // no slash found
		return std::string();
	}

	ASSERT(slashPos > 0)
	ASSERT(path_name.size() > 0)
	ASSERT(path_name.size() >= slashPos + 1)

	return std::string(path_name, 0, slashPos + 1);
}

std::string papki::suffix(std::string_view path_name){
    size_t dot_pos = path_name.rfind('.');
	if(dot_pos == std::string::npos || dot_pos == 0){ // NOTE: dot_pos is 0 for hidden files in *nix systems
		return std::string();
	}else{
		ASSERT(dot_pos > 0)
		ASSERT(path_name.size() > 0)
		ASSERT(path_name.size() >= dot_pos + 1)
		
		// check for hidden file on *nix systems
		if(path_name[dot_pos - 1] == '/'){
			return std::string();
		}
		
		return std::string(path_name.substr(dot_pos + 1));
	}
	ASSERT(false)
}

std::string papki::not_suffix(std::string_view path_name){
    size_t dot_pos = path_name.rfind('.');
	if(dot_pos == std::string::npos || dot_pos == 0){ // NOTE: dot_pos is 0 for hidden files in *nix systems
		return std::string(path_name);
	}else{
		ASSERT(dot_pos > 0)
		ASSERT(path_name.size() > 0)
		ASSERT(path_name.size() >= dot_pos + 1)
		
		// check for hidden file on *nix systems
		if(path_name[dot_pos - 1] == '/'){
			return std::string(path_name);
		}
		
		return std::string(path_name.substr(0, dot_pos));
	}
	ASSERT(false)
}
