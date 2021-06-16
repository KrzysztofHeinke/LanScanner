#include <iostream>
#include "LanScanner.hpp"

int main(int argc, char *argv[])
{
    LanScanner lan;
    lan.lanScan(argv[1]);
    return 0;
}