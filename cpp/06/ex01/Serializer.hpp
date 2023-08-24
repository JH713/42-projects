#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <cstdint>

class Serializer
{
private:
	Serializer();
	Serializer(Serializer &copy);
	Serializer& operator=(const Serializer &ref);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif