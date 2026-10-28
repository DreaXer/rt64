//
// RT64
//

#pragma once

#include "render/rt64_shader_common.h"

#if SCRIPT_ENABLED
#include "script/rt64_script.h"
#endif

#include "rt64_draw_call.h"

namespace RT64 {
    struct GameCall {
        DrawCall callDesc;
        ShaderDescription shaderDesc;

        struct {
            // Only applies to raw triangle geometry from LLE triangle commands.
            uint32_t rawVertexStart;

            // Only applies to indexed geometry from the RSP.
            uint32_t faceIndicesStart;
        } meshDesc;

        struct {
            uint32_t highlightColor;
        } debuggerDesc;

        struct {
            bool enabled;
#       if SCRIPT_ENABLED
            CallMatchCallback *matchCallback; // FIXME: This only supports one match callback active at a time per draw call.
#       endif
        } lerpDesc;

        // 40winks: offset (10.2 fixed point) from this rect to the matched rect of the previous frame, see GameFrame::match.
        struct {
            int32_t dx = 0;
            int32_t dy = 0;
            // Offset of the lower right corner: differs from dx / dy only for untextured rects that change size (animated boxes).
            int32_t dx2 = 0;
            int32_t dy2 = 0;
        } rectLerpDesc;
    };
};