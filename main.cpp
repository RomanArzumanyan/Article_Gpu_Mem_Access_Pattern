#include <iostream>
#include <vector>
#include "scow.h"
#include "GpuImg.hpp"
#include "GpuKernel.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

struct Launch
{
    string fname;
    int dimx, dimy;

    Launch(string name, int x, int y) :
        fname(name), dimx(x), dimy(y)
    {}
};

int main()
{
    SCOW_Set_Up();
    scow_Steel_Thread *pthread = Make_Steel_Thread(Pick_Device_By_Type(CL_DEVICE_TYPE_GPU));

    std::string filename = "C:\\Images\\Shore.pgm";
    GpuImg shore(pthread, filename);
    //GpuImg shore(pthread, filename, CL_MEM_ALLOC_HOST_PTR);

    const int runs = 8;
    vector<Launch> launches({
        Launch("SimpleCopy.cl",   shore.cols,      shore.rows),
        Launch("ReadRow2.cl",     shore.cols / 2,  shore.rows),
        Launch("ReadRow4.cl",     shore.cols / 4,  shore.rows),
        Launch("ReadRow8.cl",     shore.cols / 8,  shore.rows),
        Launch("ReadRow16.cl",    shore.cols / 16, shore.rows),
        Launch("ReadCol2.cl",     shore.cols,      shore.rows / 2),
        Launch("ReadCol4.cl",     shore.cols,      shore.rows / 4),
        Launch("ReadCol8.cl",     shore.cols,      shore.rows / 8),
        Launch("ReadCol16.cl",    shore.cols,      shore.rows / 16),
        Launch("ReadRow2x2.cl",   shore.cols / 2,  shore.rows / 2),
        Launch("ReadRow4x4.cl",   shore.cols / 4,  shore.rows / 4),
        Launch("ReadRow8x8.cl",   shore.cols / 8,  shore.rows / 8),
        Launch("ReadRow16x16.cl", shore.cols / 16, shore.rows / 16),
        Launch("ReadCol2x2.cl",   shore.cols / 2,  shore.rows / 2),
        Launch("ReadCol4x4.cl",   shore.cols / 4,  shore.rows / 4),
        Launch("ReadCol8x8.cl",   shore.cols / 8,  shore.rows / 8),
        Launch("ReadCol16x16.cl", shore.cols / 16, shore.rows / 16)
    });

    for (auto it = launches.begin(); it != launches.end(); it++){
        cout << it->fname << "\t";
        GpuKernel kern(pthread, it->fname);
        kern.Bunch(shore, runs, it->dimx, it->dimy);
    }

    shore.fromGPU();
    shore.Show();

    pthread->Destroy(pthread);
    SCOW_Tear_Down();
}