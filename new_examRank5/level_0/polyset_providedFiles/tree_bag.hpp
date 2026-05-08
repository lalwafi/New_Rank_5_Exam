/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bag.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:41:34 by fatkeski          #+#    #+#             */
/*   Updated: 2026/04/29 23:00:23 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "bag.hpp"

class tree_bag : virtual public bag {
protected:
	// binary search tree node structure
	struct node {
	  node *l;
	  node *r;
	  int value;
	};

	node *tree; // root node

public:
	tree_bag();
	tree_bag(const tree_bag &);
	tree_bag  &operator=(const tree_bag &);
	~tree_bag();

	node *extract_tree(); // getter
	void set_tree(node *); // places the incoming tree from outside into the class's tree.

	virtual void insert(int);
	virtual void insert(int *array, int size);
	virtual void print() const;
	virtual void clear();

private:
	static void destroy_tree(node *);
	static void print_node(node *);
	static node *copy_node(node *); // void* -> node* conversion was done
};
