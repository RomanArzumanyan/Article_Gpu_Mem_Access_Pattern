#include <iostream>
#include "scow.h"
#include "GpuImg.hpp"
#include "GpuKernel.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

int main()
{
    SCOW_Set_Up();
    scow_Steel_Thread *pthread = Make_Steel_Thread(Pick_Device_By_Type(CL_DEVICE_TYPE_GPU));

    std::string filename = "C:\\Images\\Shore.pgm";
    GpuImg shore(pthread, filename);
    shore.Show();

    const int runs = 8;

#if 0
    std::string kfile = "ReadRow4.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols/4, shore.rows);
#endif

#if 0
    std::string kfile = "ReadRow8.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols / 8, shore.rows);
#endif

#if 0
    std::string kfile = "ReadRow16.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols / 16, shore.rows);
#endif

#if 0
    std::string kfile = "ReadRow2.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols / 2, shore.rows);
#endif

#if 0
    std::string kfile = "SimpleCopy.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols, shore.rows);
#endif

#if 0
    std::string kfile = "ReadCol2.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols, shore.rows/2);
#endif

#if 0
    std::string kfile = "ReadCol4.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols, shore.rows / 4);
#endif

#if 0
    std::string kfile = "ReadCol8.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols, shore.rows / 8);
#endif

#if 0
    std::string kfile = "ReadCol16.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols, shore.rows / 16);
#endif

#if 0
    std::string kfile = "ReadRow2x2.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols / 2, shore.rows / 2);
#endif

#if 0
    std::string kfile = "ReadRow4x4.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols / 4, shore.rows / 4);
#endif

#if 0
    std::string kfile = "ReadRow8x8.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols / 8, shore.rows / 8);
#endif

#if 0
    std::string kfile = "ReadRow16x16.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols / 16, shore.rows / 16);
#endif

#if 0
    std::string kfile = "ReadCol2x2.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols / 2, shore.rows / 2);
#endif

#if 0
    std::string kfile = "ReadCol4x4.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols / 4, shore.rows / 4);
#endif

#if 0
    std::string kfile = "ReadCol8x8.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols / 8, shore.rows / 8);
#endif

    std::string kfile = "ReadCol16x16.cl";
    GpuKernel filter(pthread, kfile);
    filter.Bunch(shore, runs, shore.cols / 16, shore.rows / 16);

    shore.fromGPU();
    shore.Show();

    pthread->Destroy(pthread);
    SCOW_Tear_Down();
}