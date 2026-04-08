#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string type) : _type(type) {}

ATarget::ATarget(const ATarget &copy) : _type(copy._type){}

ATarget	&ATarget::operator=(const ATarget &copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

ATarget::~ATarget() {}

const std::string &ATarget::getType() const
{
	return (this->_type);
}

void	ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}
