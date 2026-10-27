//
// RT64
//

#pragma once

#include "shared/rt64_hlsl.h"

#ifdef HLSL_CPU
namespace interop {
#endif
    struct VideoInterfaceCB {
        float2 videoResolution;
        float2 textureResolution;
        float gamma;
        // 40winks: film grain (VI gamma dither bit set and the launcher's Film Grain option on).
        uint filmGrain;
        uint grainSeed;
        float fbWidth;
        float fbHeight;
    };
#ifdef HLSL_CPU
};
#endif