#include "Data.hpp"

static std::string* createRandomString() {
	static const char *alnum = "abcdefghijklmnopqrstuvwzyz0123456789";
	std::string* s = new std::string();
	for (int i = 0; i < 8; i++)
		*s += alnum[rand() % 36];
	return s;
}

void* serialize(void) {
	char* raw = new char[sizeof(void*) * 2 + sizeof(int)];
	std::string* s1 = createRandomString();
	int n = rand();
	std::string* s2 = createRandomString();

	*(reinterpret_cast<std::string**>(raw)) = s1;
	*(reinterpret_cast<int*>(raw + sizeof(void*))) =  n;
	*(reinterpret_cast<std::string**>(raw + sizeof(void*) + sizeof(int))) = s2;
	return static_cast<void*>(raw);
}

Data* deserialize(void* _raw) {
	char* raw = static_cast<char*>(_raw);
	Data* data = new Data();
	data->s1 = *reinterpret_cast<std::string**>(raw);
	data->n = *reinterpret_cast<int*>(raw + sizeof(void*));
	data->s2 = *reinterpret_cast<std::string**>(raw + sizeof(void*) + sizeof(int));
	return (data);
}
