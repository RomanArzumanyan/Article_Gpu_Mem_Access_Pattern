#pragma once
#include "GpuImg.hpp"

struct scow_Steel_Thread;

class GpuKernel
{
public:
    scow_Kernel* pkernel;

    GpuKernel(scow_Steel_Thread *pthread, std::string &filename, std::string kernel_name = "TestKernel");
    ~GpuKernel();
    // Returns launch time in microseconds
    double Launch(GpuImg &gpu_img, int size_x=-1, int size_y = -1);
    void Bunch(GpuImg &gpu_img, int runs = 8, int size_x = -1, int size_y = -1);
};

