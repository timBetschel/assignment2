#include "Simulator.h"

int main(int argc, char** argv) {
    /* check command line arguments */
    if (argc != 2) {
        std::cerr << "Arguments need to have the format: ./fifo datafile" << std::endl;
        return EXIT_FAILURE;
    }

    Simulator sim;
    Loader load;
    std::vector<pcb> pcbs = load.loadDataset(argv[1]);
    sim.runFIFO(pcbs);
    sim.displayResults();

    return EXIT_SUCCESS; 
}