#include "GpuImg.hpp"
#include "steel_thread.h"
#include "mem_object.h"

using namespace cv;

GpuImg::GpuImg(scow_Steel_Thread *pthread, std::string &filename, cl_mem_flags flags) :
Mat(imread(filename, CV_LOAD_IMAGE_GRAYSCALE))
{
    std::size_t size = this->rows * this->cols * sizeof(*this->data);
	this->device_picture = Make_Buffer(pthread, flags | CL_MEM_COPY_HOST_PTR, size, (void*)this->data);
	this->picture_out = Make_Buffer(pthread, flags, size, NULL);
}

GpuImg::~GpuImg()
{
    this->device_picture->Destroy(this->device_picture);
    this->picture_out->Destroy(this->picture_out);
}

void GpuImg::fromGPU()
{
    this->picture_out->Read(this->picture_out, CL_TRUE, (void*)this->data, MEASURE, NULL, NULL);
}

void GpuImg::Show()
{
    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", *this);
    waitKey(0);
}
