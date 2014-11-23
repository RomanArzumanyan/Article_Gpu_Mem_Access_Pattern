#pragma once

#include "GpuImg.hpp"

class GpuKernel
{
public:
    scow_Kernel* pkernel;

    GpuKernel(scow_Steel_Thread *pthread, std::string &filename, std::string kernel_name = "TestKernel");
    ~GpuKernel();
    void Launch(GpuImg &gpu_img, int size_x=-1, int size_y = -1);
};

