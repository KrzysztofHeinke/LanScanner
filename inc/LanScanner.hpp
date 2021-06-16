#pragma once

#include <string>
#include <vector>

class LanScanner
{
    public:
    LanScanner(){
        getHostIp();
    }
    void lanScan(std::string p_ipAddr);

    private:
    void getHostIp();
    void printIpAddreses();
    std::vector<std::string> m_interfaces;
};
