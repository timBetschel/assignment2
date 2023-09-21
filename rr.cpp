#include "Simulator.h"

int main(int argc, char** argv) {
    /* check command line arguments */
    if (argc != 3) {
        std::cerr << "Arguments need to have the format: ./rr quantum datafile" << std::endl;
        return EXIT_FAILURE;
    }

    int quantum = std::stoi(argv[1]);
    Simulator sim;
    Loader load;
    std::vector<pcb> pcbs = load.loadDataset(argv[2]);
    sim.runRR(pcbs, quantum);
    sim.displayResults();

    return EXIT_SUCCESS; 
}