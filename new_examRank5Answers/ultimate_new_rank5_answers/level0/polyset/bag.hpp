/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bag.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:12:00 by fatkeski          #+#    #+#             */
/*   Updated: 2026/04/29 23:00:23 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once // multiple include guard blocker -> "This file is included only once; if the same file is included a second time, ignore it."

// bag data structure is equivalent to multiset. it is a structure that holds a value and how many instances of it exist.
// abstract class and even an interface. everything that is a bag should be able to perform the following 4 operations
class bag
{
 public:
	virtual void insert (int) = 0;
	virtual void insert (int *, int) = 0;
	virtual void print() const = 0;
	virtual void clear() = 0;
};
