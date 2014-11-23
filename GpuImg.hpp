#pragma once

#include <string>
#include "scow.h"
#include "opencv2/opencv.hpp"

struct scow_Steel_Thread;
struct scow_Mem_Object;

class GpuImg : public cv::Mat
{
public:
    scow_Mem_Object *device_picture;
    scow_Mem_Object *picture_out;

    GpuImg(scow_Steel_Thread *pthread, std::string &filename);
    ~GpuImg();
    void fromGPU();
    void Show();
};

