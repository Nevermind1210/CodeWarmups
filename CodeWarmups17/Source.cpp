#include <iostream>
#include <string>
#include <vector>
int SockPairs(const std::string& socks)
{
	int pairs = 0;
	std::vector<char> singles;

	for (auto count : socks)
	{
		auto iter = std::find(singles.begin(), singles.end(), count);
		if (iter != singles.end())
		{
			*iter = 0;
			pairs++;
		}
		else
		{
			singles.push_back(count);
		}
	}
	return pairs;
}

int main(int argc, char** argv)
{
	std::cout << "AA Count - " << SockPairs("AA") << std::endl;
	std::cout << "ABABC     Count - " << SockPairs("ABABC") << std::endl;
	std::cout << "CABBACCC  Count - " << SockPairs("CABBACCC") << std::endl;

	return 0;
}