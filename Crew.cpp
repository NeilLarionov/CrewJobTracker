#include "Crew.h"

Crew::Crew() : name{"None"}
{
}

Crew::Crew(std::string nameVal) : name{nameVal}
{
}

Crew::~Crew()
{
}

void Crew::assignHouse(Community com, int lotNumber)
{
    std::unique_ptr<Jobs> job = std::make_unique<Jobs>(com, lotNumber); // create new ptr to a Job
    jobs.push_back(std::move(job));    // Add new job to crews jobs vector
}

void Crew::assignHouse(std::unique_ptr<Jobs>& job)
{
	jobs.push_back(std::move(job));
}
std::ostream &operator<<(std::ostream &os, const Crew &obj)
{
    os << obj.name;
    return os;
}
 
