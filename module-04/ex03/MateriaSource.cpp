#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource() : count(0){
	std::cout << "\e[0;33mDefault Constructor called of MateriaSource\e[0m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	std::cout << "\e[0;33mCopy Constructor called of MateriaSource\e[0m" << std::endl;
	*this = copy;
}

// Destructor
MateriaSource::~MateriaSource() {
	std::cout << "\e[0;31mDestructor called of MateriaSource\e[0m" << std::endl;
}

// Operators
MateriaSource & MateriaSource::operator=(const MateriaSource &assign)
{
	std::cout << "\e[0;33mAssignation operator called of MateriaSource\e[0m" << std::endl;
	if (&assign == this)
		return *this;
	this->count = assign.count;
	for (int i = 0; i < this->count; i++)
		this->materia[i] = assign.materia[i];
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	if (this->count < 4) {
		this->materia[this->count] = m;
		this->count++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->count; i++) {
		if (this->materia[i]->getType() == type)
			return this->materia[i]->clone();
	}
	return NULL;
}