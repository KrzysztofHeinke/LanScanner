#pragma once

#include <string>
#include <vector>

class LanScanner
{
    public:
    LanScanner(bool scanPort = false);
    void lanScan(std::string p_ipAddr);

    private:
    void getHostIp();
    void printIpAddreses();
    void pingIp(const std::string &p_ipAddr);
    std::vector<std::string> m_interfaces;

    bool m_scanPorts;
};
