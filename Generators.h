#include <iostream>

class Generator {
	virtual std::string generate() = 0;
};

class IDGenerator : Generator {
public:
	std::string generate();
};

class ExpirationDateGenerator : Generator {
public:
	std::string generate();
};