#include "scow.h"
#include "GpuImg.hpp"
#include "GpuKernel.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main()
{
    SCOW_Set_Up();
    scow_Steel_Thread *pthread = Make_Steel_Thread(Pick_Device_By_Type(CL_DEVICE_TYPE_GPU));

    std::string filename = "C:\\Images\\Shore.pgm";
    GpuImg shore(pthread, filename);
    namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("Display window", shore);
    waitKey(0);

    std::string kfile = "Dark.cl", kname = "Dark";
    GpuKernel dark(pthread, kfile, kname);
    dark.Launch(shore);
    shore.fromGPU();

    namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("Display window", shore);
    waitKey(0);

    pthread->Destroy(pthread);
    SCOW_Tear_Down();
}