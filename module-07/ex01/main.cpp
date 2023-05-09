#include "iter.hpp"

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};
	::iter(arr, 5, ::print<int>);

	std::string arr2[] = {"Hallo", "Wie", "Geht's", "Dir", "?"};
	::iter(arr2, 5, ::print<std::string>);
	return 0;
}
