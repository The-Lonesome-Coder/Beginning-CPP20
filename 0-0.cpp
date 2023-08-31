#include <iostream>
#include <format>


int main(void)
{
	int fish_count {20}, pond_diameter {50};

	std::cout << std::format("Pond diameter required for {} fish is {} feet.", fish_count, pond_diameter);

	return 0;
}