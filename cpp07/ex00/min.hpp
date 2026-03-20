/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:01:28 by romukena          #+#    #+#             */
/*   Updated: 2026/03/20 19:19:43 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIN_HPP
#define MIN_HPP
#include <iostream>

template <typename T>
const T &min(const T &a,const T &b)
{
	return (a < b ? a : b);
}

#endif