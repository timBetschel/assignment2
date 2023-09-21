#include "Loader.h"


std::vector<pcb> Loader::loadDataset(const std::string& datasetFile){
    std::vector<pcb> pcbVector;
    std::ifstream in;
    in.open(datasetFile);
    if (!in.is_open()) {
        std::cerr << "Error opening dataset file argument: " << datasetFile << "\n";
        return pcbVector;
    }
    
    std::string inLine;
    while (std::getline(in, inLine)){
        std::istringstream iss(inLine);

        osp2023::id_type processID;
        osp2023::time_type burstTime;
        char comma;

        iss >> processID >> comma >> burstTime;
        pcb process(processID, burstTime);
        pcbVector.push_back(process);
    }
   
    return pcbVector;
} 