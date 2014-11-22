#include "GpuImg.hpp"
#include "steel_thread.h"
#include "mem_object.h"

using namespace cv;

GpuImg::GpuImg(scow_Steel_Thread *pthread, std::string &filename) :
Mat(imread(filename, CV_LOAD_IMAGE_GRAYSCALE))
{
    std::size_t size = this->rows * this->cols * sizeof(*this->data);
    this->device_picture = Make_Buffer(pthread, CL_MEM_COPY_HOST_PTR, size, (void*)this->data);
}


GpuImg::~GpuImg()
{
    this->device_picture->Destroy(this->device_picture);
}

void GpuImg::toGPU()
{
    this->device_picture->Write(this->device_picture, CL_TRUE, (void*)this->data, MEASURE, NULL, NULL);
}

void GpuImg::fromGPU()
{
    this->device_picture->Read(this->device_picture, CL_TRUE, (void*)this->data, MEASURE, NULL, NULL);
}