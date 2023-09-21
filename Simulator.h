#include "Loader.h"
#ifndef SIMULATOR
#define SIMULATOR
class Simulator {
   public:
    void runFIFO(std::vector<pcb> pcbs);
    void runSJF(std::vector<pcb> pcbs);
    void runRR(std::vector<pcb> pcbs, int quantum);

   private:

};
#endif //SIMULATOR
