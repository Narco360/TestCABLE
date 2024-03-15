#include "testcable.h"
#include <QApplication>
#include <QDebug>
//#include <iostream> using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestCable w;
    w.show();


    //Debut test Detection des devices.
    /*
    FT_STATUS ftStatus;
    FT_DEVICE_LIST_INFO_NODE *devInfo;
    DWORD numDevs;
    // create the device information list
    ftStatus = FT_CreateDeviceInfoList(&numDevs);
    if (ftStatus == FT_OK) {
        cout<<"Number of devices is "<<numDevs<<endl;
    }
    if (numDevs > 0) {
        // allocate storage for list based on numDevs
        devInfo =
            (FT_DEVICE_LIST_INFO_NODE*)malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*numDevs);
        // get the device information list
        ftStatus = FT_GetDeviceInfoList(devInfo,&numDevs);
        if (ftStatus == FT_OK) {
            for (DWORD i = 0; i < numDevs; i++) {
                cout << "Dev " << i+1 << ":" << endl;
                cout << " Flags=0x" << hex << devInfo[i].Flags << endl;
                cout << " Type=0x" << hex << devInfo[i].Type << endl;
                cout << " ID=0x" << hex << devInfo[i].ID << endl;
                cout << " LocId=0x" << hex << devInfo[i].LocId << endl;
                cout << " SerialNumber=" << devInfo[i].SerialNumber << endl;
                cout << " Description=" << devInfo[i].Description << endl;
                cout << " ftHandle=0x" << hex << devInfo[i].ftHandle << endl;
            }
        }
    }
    */
    //Fin test


    return a.exec();
}
