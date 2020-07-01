#include <iostream>
#include "StopWatch.h"

using namespace std;
using namespace std::chrono;
int DoSomeLongRunningThing()
{
    int counter = 0;
    for (int i = 0; i < 9000; i++)
    {
        std::cout << " " << std::endl;
        counter += 1;
    }
    return counter;
}
int main(int argc, char** argv)
{
    // For todays exercise, we want to record how much time it takes to "do some work"
    // you will need to:
    // - get a start time
    // - get an end time
    // - subtract the difference and print the result in miliseconds.
    // Once you've done that... how might you make your code easily re-usable.
    // --
    std::cout << "Hello World" << std::endl;
    
    // --
    std::cout << "TODO" << std::endl;
    // TODO: output to console - number of miliseconds it took to print "Hello World" above
    // --
    StopWatch sw; // naming convention
    sw.Start(); // starting to read function execution
    DoSomeLongRunningThing();
    sw.Stop();// well stopping it
    // --
    std::cout << "It took: " << sw.GetTime() << "ms" << std::endl;
    // TODO: output to console - number of miliseconds it took to took to call the above method

}