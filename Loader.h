#include <string>
#include <iostream>
#include <vector>
#include "pcb.h"
#ifndef LOADER
#define LOADER
class Loader {
   public:
   std::vector<pcb> loadDataset(const std::string& datasetFile);
};
#endif //LOADER
