#include <iostream>
#include <SDL.h>
#include <map>
#include <unordered_map>
#include <tuple>

int main(int argc, char* argv[])
{
	std::map<std::pair<int, char>, char> someOrderedMap;
	//std::unordered_map<std::pair<int, char>, char> someUnorderedMap;
	
	someOrderedMap.emplace(std::make_pair(1, '1'), 'a');
	//someUnorderedMap.emplace(std::make_pair(1, '1'), 'a');

	std::cout << someOrderedMap.at(std::make_pair(1, '1')) << std::endl;
	//std::cout << someUnorderedMap.at(std::make_pair(1, '1')) << std::endl;

	return 0;
}
