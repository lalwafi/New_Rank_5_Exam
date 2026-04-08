#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;
class ATarget
{
	protected:
		std::string _type;
	public:
		ATarget();
		ATarget(const std::string type);
		ATarget(const ATarget &copy);
		ATarget &operator=(const ATarget &copy);
		virtual ~ATarget();

		const std::string &getType() const;
		void	getHitBySpell(const ASpell &spell) const;
		virtual ATarget *clone() const = 0;

};