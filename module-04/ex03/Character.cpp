#include "Character.hpp"

// Constructors
Character::Character() : name("default") , count(0) {
	std::cout << "\e[0;33mDefault Constructor called of Character\e[0m" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

Character::Character(std::string const & name) : name(name) , count(0) {
	std::cout << "\e[0;33mConstructor called of Character\e[0m" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

Character::Character(const Character &copy) {
	std::cout << "\e[0;33mCopy Constructor called of Character\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Character::~Character() {
	std::cout << "\e[0;31mDestructor called of Character\e[0m" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->materias[i])
			delete this->materias[i];
	}
}

// Operators
Character & Character::operator=(const Character &assign) {
	std::cout << "\e[0;33mAssignation operator called of Character\e[0m" << std::endl;
	if (&assign == this) { return *this; }
	this->name = assign.getName();
	this->count = assign.count;
	for (int i = 0; i < 4; i++) {
		if (this->materias[i])
			delete this->materias[i];
	}
	for (int i = 0; i < assign.count; i++) {
		this->equip(assign.materias[i]->clone());
	}
	return *this;
}

// Member functions
std::string const & Character::getName() const { return this->name; }

void Character::equip(AMateria *m) {
	if (this->count < 4) {
		this->materias[this->count] = m;
		this->count++;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < this->count) {
		this->materias[idx] = NULL;
	}
	for (int i = idx; i < this->count - 1; i++) {
		this->materias[i] = this->materias[i + 1];
	}
	this->materias[this->count - 1] = NULL;
	this->count--;
}

void Character::use(int idx, ICharacter& target) {
	if (this->materias[idx] && idx >= 0 && idx < this->count) {
		this->materias[idx]->use(target);
	}
}