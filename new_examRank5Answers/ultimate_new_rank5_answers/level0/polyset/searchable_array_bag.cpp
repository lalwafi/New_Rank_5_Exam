/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:26:23 by fatkeski          #+#    #+#             */
/*   Updated: 2026/04/28 20:25:53 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"


searchable_array_bag::searchable_array_bag()
{

}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& source) : array_bag(source)
{

}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& source)
{
	if(this != &source)
	{
		array_bag::operator=(source);
	}
	return(*this);
}

bool searchable_array_bag::has(int value) const
{
	for(int i = 0; i < this->size; i++)
	{
		if(this->data[i] == value)
			return (true);
	}
	return(false);
}

searchable_array_bag::~searchable_array_bag()
{

}
