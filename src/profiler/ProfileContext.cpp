#include "ProfileContext.h"

namespace Profiler {

void ProfileContext::Update(double dT) {
    totalTime += dT ;
    averageTime = (averageTime * nCalls + dT) / (nCalls + 1) ;
    nCalls += 1 ;
    // Update minimum and maximum time
    if ((minTime == -1.0) || (minTime > dT))
        minTime = dT;
    if ((maxTime == -1.0) || (maxTime < dT))
        maxTime = dT;
}

ProfileContext::ProfileContext () : minTime(-1.0), maxTime(-1.0),
totalTime(0.0), averageTime(0.0), nCalls(0) {

}

double ProfileContext::Get_totalTime() {
    return totalTime;
}

double ProfileContext::Get_averageTime() {
    return averageTime;
}

unsigned int ProfileContext::Get_nCalls() {
    return nCalls;
}

double ProfileContext::Get_minTime() {
    return minTime;
}
double ProfileContext::Get_maxTime() {
    return maxTime;
}

}   // end namespace "Profiler"

