#include "Simulator.h"

void Simulator::runFIFO(std::vector<pcb> pcbs){
    osp2023::time_type timeTally = 0;
    osp2023::time_type totalTurnaroundTime = 0;
    osp2023::time_type totalWaitingTime = 0;
    osp2023::time_type totalResponseTime = 0;
    size_t numProcesses = pcbs.size();

    while (!pcbs.empty()){
        pcb& curProcess = pcbs.front();
        curProcess.total_wait_time = timeTally;
        curProcess.time_used = curProcess.total_wait_time + curProcess.total_time;

        totalTurnaroundTime += curProcess.time_used;
        totalWaitingTime += curProcess.total_wait_time;
        totalResponseTime = totalWaitingTime; //because arrival time is 0 for each process.
        timeTally += curProcess.total_time;

        std::cout << "ProcessID: " << curProcess.id << ", Burst Time: " << curProcess.total_time 
        << "ms, Turnaround Time: " << curProcess.time_used << "ms, Waiting Time: " << curProcess.total_wait_time 
        << "ms, Response Time: " << curProcess.total_wait_time << "ms" << std::endl;

        pcbs.erase(pcbs.begin());

    }
    std::cout << std::endl;
    std::cout << "Average Turnaround Time: " << totalTurnaroundTime/numProcesses << "ms" << std::endl;
    std::cout << "Average Waiting Time: " << totalWaitingTime/numProcesses << "ms" << std::endl;
    std::cout << "Average Response Time: " << totalResponseTime/numProcesses << "ms" << std::endl;
}

void Simulator::runSJF(std::vector<pcb> pcbs){
    std::sort(pcbs.begin(), pcbs.end(), [](const pcb& proccessA, const pcb& proccessB){
        return proccessA.total_time < proccessB.total_time;
    });

    osp2023::time_type timeTally = 0;
    osp2023::time_type totalTurnaroundTime = 0;
    osp2023::time_type totalWaitingTime = 0;
    osp2023::time_type totalResponseTime = 0;
    size_t numProcesses = pcbs.size();

    while (!pcbs.empty()){
        pcb& curProcess = pcbs.front();
        curProcess.total_wait_time = timeTally;
        curProcess.time_used = curProcess.total_wait_time + curProcess.total_time;

        totalTurnaroundTime += curProcess.time_used;
        totalWaitingTime += curProcess.total_wait_time;
        totalResponseTime = totalWaitingTime; //because arrival time is 0 for each process.
        timeTally += curProcess.total_time;

        std::cout << "ProcessID: " << curProcess.id << ", Burst Time: " << curProcess.total_time 
        << "ms, Turnaround Time: " << curProcess.time_used << "ms, Waiting Time: " << curProcess.total_wait_time 
        << "ms, Response Time: " << curProcess.total_wait_time << "ms" << std::endl;

        pcbs.erase(pcbs.begin());

    }
    std::cout << std::endl;
    std::cout << "Average Turnaround Time: " << totalTurnaroundTime/numProcesses << "ms" << std::endl;
    std::cout << "Average Waiting Time: " << totalWaitingTime/numProcesses << "ms" << std::endl;
    std::cout << "Average Response Time: " << totalResponseTime/numProcesses << "ms" << std::endl;
}

void Simulator::runRR(std::vector<pcb> pcbs, int quantum){
    
}