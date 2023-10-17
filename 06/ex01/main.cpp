#include <iostream>
#include "Serializer.hpp"
#include <inttypes.h>
#include "data.hpp"

void	print_data(Data *data)
{
	std::cout << "----------------------" << std::endl;
	std::cout << "Name: " << data->name << std::endl;
	std::cout << "Age: " << data->age << std::endl;
	std::cout << "Country: " << data->country << std::endl;
	std::cout << "Money: " << data->money << std::endl;
	std::cout << "----------------------" << std::endl;
}

Data*	original_pointer;

uintptr_t	create_serialized_data(void)
{
	Data	*data = new Data;

	data->name = "Daniel";
	data->age = 23;
	data->country = "Brazil";
	data->money = 16.99;
	original_pointer = data;
	return (Serializer::serialize(data));
}

void	print_serialized_data(uintptr_t serialized_data)
{
	Data	*data;

	data = Serializer::deserialize(serialized_data);
	print_data(data);
}

int main(void)
{
	uintptr_t	serialized_data;

	serialized_data = create_serialized_data();
	print_serialized_data(serialized_data);
	
	Data*		deserialized_data;

	deserialized_data = Serializer::deserialize(serialized_data);
	std::cout << "Deserialized data: " << deserialized_data << std::endl;
	std::cout << "Original pointer:  " << original_pointer << std::endl;

	delete deserialized_data;
	return (0);
}
