#include <iostream>
#include <string>
#include <sstream>
#include "windows.h"
using std::string;
using std::stringstream;

int print(string str) {
    std::cout << "\n" << std::endl;
    std::cout << str << std::endl;
    std::cout << "\n" << std::endl;
    return 0;
}

int Help() {
    std::cout << "\n" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "Example : DisResolution /width 1920 /height 1080" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "\n" << std::endl;
    return 0;
}

int main(int arg, char** argv)
{

    int width, height;
    stringstream fmt;

    if (5 == arg) {
        //std::cout << "Get arg!" << std::endl;
        width = atoi(argv[2]);
        //std::cout << width << std::endl;
        height = atoi(argv[4]);
        //std::cout << height << std::endl;
    }
    else {
        Help();
        return 0;
    }


    LPDEVMODEW MypDevMode = new DEVMODEW;
    MypDevMode->dmSize = sizeof(DEVMODEW);
    MypDevMode->dmDriverExtra = 0;
    if (0 == EnumDisplaySettingsW(NULL, ENUM_CURRENT_SETTINGS, MypDevMode)) {
        print(string("获取当前显示设置出错！"));
    }
    else {
        fmt << "Current Resolution: " << MypDevMode->dmPelsWidth << " x " << MypDevMode->dmPelsHeight;

        print(fmt.str());

        MypDevMode->dmDisplayFixedOutput = 0;
        MypDevMode->dmPelsWidth = width;
        MypDevMode->dmPelsHeight = height;
        MypDevMode->dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;

        fmt.str("");
        fmt << "Target Resolution: " << MypDevMode->dmPelsWidth << " x " << MypDevMode->dmPelsHeight;
        print(fmt.str());
        ChangeDisplaySettingsW(MypDevMode, 0);
        print("Set Done!");
    }
    delete MypDevMode;
    return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
