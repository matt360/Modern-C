#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

//std::string GetName()
//{
//	return "Mateusz";
//}

//char* GetName()
//{
//	return "Mateusz";
//}

auto GetName()->const char* // specify the type you want to return - it's called trailing return types
{
	return "Mateusz";
}

class Device {};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;

public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}

};

int main()
{
	auto a = 5L; // auto = long int

	auto b = a;  // auto = long int

	auto c = "Mateusz"; // auto = const char*

	auto d = 5.5f; // auto = float

	auto e = 5; // auto = int

	auto g = 'a'; // auto = char

	std::cout << b << std::endl;

	auto name = GetName();

	//name.size();

	// when to use 'auto'
	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	// 1 way of iterating
	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
	typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap;

	DeviceManager dm;
	const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices();
	const DeviceMap& u_devices = dm.GetDevices();

	const auto& a_devices = dm.GetDevices();

	std::cin.get();
}