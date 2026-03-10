/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:51:03 by romukena          #+#    #+#             */
/*   Updated: 2026/03/09 18:01:39 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    int randomNum = rand() % 3;

    switch (rand) {
	case 0:
	    return *A;
	case 1:
	    return *B;
	case 2:
	    return *C;
    }
}