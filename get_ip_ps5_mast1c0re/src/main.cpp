#include <mast1c0re.hpp>

#define FTP_PORT 9023

void main()
{
    PS::Debug.connect(IP(192, 168, 1, 155), 9023);

    char ip_address[SCE_NET_CTL_IPV4_ADDR_STR_LEN] = {0};
    int ret = PS::get_ip_address(ip_address);

    PS::Debug.printf("%s", ip_address);
    if (ret >= 0)
        PS::notification("Listening on IP:%s\nPort: %i", ip_address, FTP_PORT);
    else
        PS::notification("Unable to get IP address");
    PS::Debug.disconnect();
}