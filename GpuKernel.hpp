#pragma once

#include "GpuImg.hpp"

class GpuKernel
{
public:
    scow_Kernel* pkernel;

    GpuKernel(scow_Steel_Thread *pthread, std::string &filename, std::string &kernel_name);
    ~GpuKernel();
    void Launch(GpuImg &gpu_img);
};

