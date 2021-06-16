
#include "LanScanner.hpp"
#include <ifaddrs.h>
#include <iostream>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <linux/if_link.h>

void LanScanner::getHostIp()
{
    ifaddrs *ifaddrs;
    char hostaddr[NI_MAXHOST];

    if(getifaddrs(&ifaddrs) == -1)
        exit(EXIT_FAILURE);

    for (auto it = ifaddrs; it != nullptr; it = it->ifa_next)
    {
        if(it->ifa_addr == nullptr)
            continue;
        if(it->ifa_addr->sa_family == AF_INET)
        {
            int nameInfo = getnameinfo(it->ifa_addr, sizeof(struct sockaddr_in), hostaddr,
                                NI_MAXHOST, nullptr, 0, NI_NUMERICHOST);
            if (nameInfo != 0)
                exit(EXIT_FAILURE);
            m_interfaces.push_back(std::string(hostaddr));
        }
    }
}

void LanScanner::printIpAddreses()
{
    for(auto &it: m_interfaces)
    {
        std::cout << it << std::endl;
    }
}

void LanScanner::lanScan(std::string p_ipAddr)
{
    std::cout << p_ipAddr << std::endl;

    if(auto found = p_ipAddr.find("*"); found != std::string::npos)
    {
        p_ipAddr.erase(found);
        for(auto i = 0; i <= 255; i++)
        {
            std::cout << p_ipAddr + std::to_string(i) << std::endl;
        }
    }
    
    
    // std::cout << p_ipAddr;
    
}