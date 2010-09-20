#ifndef __PROFILECONTEXT_H_INCLUDED__
#define __PROFILECONTEXT_H_INCLUDED__

namespace Profiler {

class ProfileContext {
  private:
        double totalTime;       // Total time for function calling
        double averageTime;
        unsigned int nCalls;
        double minTime;
        double maxTime;
  public:
        void Update(double dT);
        ProfileContext();       // Constructor for min/maxTime inits
        // Access methods
        double Get_totalTime();
        double Get_averageTime();
        unsigned int Get_nCalls();
        double Get_minTime();
        double Get_maxTime();
};

} // namespace

#endif // __PROFILECONTEXT_H_INCLUDED__
