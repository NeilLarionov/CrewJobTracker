#pragma once
#include <vector>
#include "Community.h"
#include "Jobs.h"
#include <memory>

class Crew
{
    friend std::ostream &operator<<(std::ostream&, const Crew&);
public:
    Crew();
    Crew(std::string);
    ~Crew();
    std::string getName() const {return name;}
    int getNumJobs() {return jobs.size();}
    void assignHouse(Community, int);
	void assignHouse(std::unique_ptr<Jobs>&);
    void setName(std::string nameVal) {name = nameVal;}
    const std::vector<std::unique_ptr<Jobs>>& getJobVec() {return jobs;}
    

private:
    std::vector<std::unique_ptr<Jobs>> jobs;
    std::string name;
    

};

