#pragma once
#include <string>

class Community
{
public:
    Community(std::string);
    
    ~Community();
    std::string getName() {return name;}
	void setName(std::string newName) {name = newName;}
private:
    std::string name;
    

};

