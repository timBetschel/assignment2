#include "Simulator.h"

int main(int argc, char** argv) {
    /* check command line arguments */
    if (argc != 2) {
        std::cerr << "Arguments need to have the format: ./sjf datafile" << std::endl;
        return EXIT_FAILURE;
    }

    Simulator sim;
    Loader load;
    std::vector<pcb> pcbs = load.loadDataset(argv[1]);
    sim.runSJF(pcbs);

    return EXIT_SUCCESS; 
}