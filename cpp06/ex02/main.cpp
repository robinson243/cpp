/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:01:58 by romukena          #+#    #+#             */
/*   Updated: 2026/03/10 16:55:28 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

int main() {
	std::srand(std::time(NULL));
	Base *obj = generate();
	identify(obj);
	identify(*obj);
	return 0;
}
