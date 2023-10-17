#ifndef SERIALIZER_H
# define SERIALIZER_H
# include <stdint.h>
# include "data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const & rhs);
		~Serializer(void);

		Serializer & operator=(Serializer const & rhs);

	public:
		static uintptr_t	serialize(Data* ptr); //create structure Data
		static Data*		deserialize(uintptr_t raw);
};

#endif