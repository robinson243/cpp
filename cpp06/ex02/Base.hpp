/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:32:51 by romukena          #+#    #+#             */
/*   Updated: 2026/03/09 17:18:36 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP


class Base
{
public:
    virtual ~Base();
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif