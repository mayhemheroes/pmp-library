#include <stdint.h>
#include <stdio.h>
#include <climits>
#include "pmp/SurfaceMesh.h"

#include <fuzzer/FuzzedDataProvider.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    std::string str = provider.ConsumeRandomLengthString();

    pmp::SurfaceMesh sm;
    sm.has_edge_property(str);

    return 0;
}
