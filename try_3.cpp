#include <iostream>

template<typename T> struct IsContainer {
	template<typename C> static constexpr bool has_size( decltype(&C::size) ) { return true;  }
	template<typename C> static constexpr bool has_size(...)                  { return false; }
	                     static constexpr bool value = has_size<T>(nullptr);
};

struct Container : IsContainer<Container> {
	const unsigned int size();
};

struct NonContainer : IsContainer<NonContainer> {};

int main() {
	Container obj;
	std::cout << obj.value <<std::endl;
}
