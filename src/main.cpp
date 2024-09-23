#include <iostream>
#include "SdsHdr.h"
int main()
{
    using namespace againstsky::sedis;
    const char *str ="Hello World";
    SdsHdr sds_hdr("hello world");
    printf("%s\n",sds_hdr.c_str());
    printf("size %d,len %d,free %d\n",sds_hdr.size(),sds_hdr.len(),sds_hdr.free());
    sds_hdr.resize(5);
    printf("%s\n",sds_hdr.c_str());
    printf("size %d,len %d,free %d\n",sds_hdr.size(),sds_hdr.len(),sds_hdr.free());

    sds_hdr.resize(15);
    printf("%s\n",sds_hdr.c_str());
    printf("size %d,len %d,free %d\n",sds_hdr.size(),sds_hdr.len(),sds_hdr.free());
    return 0;
}
