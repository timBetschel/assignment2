#include "pcb.h"

pcb::pcb(osp2023::id_type processID, osp2023::time_type burstTime) {
    id = processID;
    total_time = burstTime;
    time_used = 0;
    total_wait_time = 0;
}