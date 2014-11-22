#include "GpuKernel.hpp"
#include "kernel.h"

GpuKernel::GpuKernel(scow_Steel_Thread *pthread, std::string &filename, std::string &kernel_name)
{
    this->pkernel = Make_Kernel(pthread, READ_FROM_FILES, filename.c_str(), kernel_name.c_str(), "");
}

GpuKernel::~GpuKernel()
{
    this->pkernel->Destroy(this->pkernel);
}

void GpuKernel::Launch(GpuImg &gpu_img)
{
    unsigned int
        dim = 2,
        wg[2] = { gpu_img.cols, gpu_img.rows },
        linesize = wg[0];

    this->pkernel->Set_ND_Sizes(this->pkernel, dim, wg, NULL);
    scow_Kernel_Arg arg_picture = { sizeof(cl_mem), (void*)&gpu_img.device_picture->cl_mem_object };
    scow_Kernel_Arg arg_linesize = { sizeof(linesize), (void*)&linesize };
    this->pkernel->Launch(this->pkernel, &this->pkernel->parent_steel_thread->q_cmd, 0, NULL, NULL, MEASURE, 
        arg_picture, arg_linesize);
}