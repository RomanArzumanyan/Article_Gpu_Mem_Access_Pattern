#include <iostream>
#include "GpuKernel.hpp"
#include "kernel.h"

using namespace std;

GpuKernel::GpuKernel(scow_Steel_Thread *pthread, std::string &filename, std::string kernel_name)
{
    this->pkernel = Make_Kernel(pthread, READ_FROM_FILES, filename.c_str(), kernel_name.c_str(), "");
}

GpuKernel::~GpuKernel()
{
    this->pkernel->Destroy(this->pkernel);
}

double GpuKernel::Launch(GpuImg &gpu_img, int size_x, int size_y)
{
    unsigned int dim = 2;
    unsigned int wg[2];

    wg[0] = (size_x == -1) ? gpu_img.cols : size_x;
    wg[1] = (size_y == -1) ? gpu_img.rows : size_y;

    this->pkernel->Set_ND_Sizes(this->pkernel, dim, wg, NULL);
    scow_Kernel_Arg arg_picture_in = K_ARG(gpu_img.device_picture->cl_mem_object);
    scow_Kernel_Arg arg_picture_out = K_ARG(gpu_img.picture_out->cl_mem_object);
    scow_Kernel_Arg arg_width = K_ARG(gpu_img.cols);
    scow_Kernel_Arg arg_height = K_ARG(gpu_img.rows);
    this->pkernel->Launch(this->pkernel, &this->pkernel->parent_steel_thread->q_cmd, 0, NULL, NULL, MEASURE, 
        arg_picture_in, arg_picture_out, arg_width, arg_height);
    return this->pkernel->timer->Get_Last_Time(this->pkernel->timer, DEVICE_TIME);
}

void GpuKernel::Bunch(GpuImg &gpu_img, int runs, int size_x, int size_y)
{
    for (int i = 0; i < runs; i++){
        cout << Launch(gpu_img, size_x, size_y) << "\t";
    }
    cout << endl;
}