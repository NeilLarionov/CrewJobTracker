#include "Jobs.h"

//Jobs::Jobs() : community{"NONE"}, lotNumber{-1}
//{
//}

Jobs::Jobs(Community communityVal) : com{communityVal}, lotNumber{-1}
{
}
Jobs::Jobs(Community communityVal, int lotNumberVal) : com{communityVal}, lotNumber{lotNumberVal}
{
}

Jobs::~Jobs()
{
}

//std::ostream& operator<<(std::ostream& os, const Jobs& job)
//{
//    os << job.com.get
//    return os;
//}

