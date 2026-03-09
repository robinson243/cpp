/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:22:48 by romukena          #+#    #+#             */
/*   Updated: 2026/03/09 13:58:40 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    Data* original = &data;
    
    std::cout << "Original ptr: " << original << std::endl;
    
    uintptr_t raw = Serializer::serialize(original);
    std::cout << "Serialized: " << std::hex << raw << std::dec << std::endl;
    
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized ptr: " << deserialized << std::endl;
    
    if (original == deserialized) {
        std::cout << "SUCCESS: serialize/deserialize works!" << std::endl;
    } else {
        std::cout << "FAILURE: pointers don't match!" << std::endl;
    }
    
    return 0;
}
