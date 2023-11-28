#pragma once

#include <string>
#include "Community.h"

class Jobs
{
    friend std::ostream& operator<<(std::ostream&, const Jobs&);
public:
    //Jobs();
    Jobs(Community);
    Jobs(Community, int);
    ~Jobs();
    
    
    int getLotNumber() {return lotNumber;}
    Community com;
    
private:
    int lotNumber;

};

