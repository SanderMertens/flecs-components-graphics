#ifndef REFLECS_COMPONENTS_GRAPHICS_H
#define REFLECS_COMPONENTS_GRAPHICS_H

#include "bake_config.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsRect {
    int32_t width;
    int32_t height;
    int32_t x;
    int32_t y;
} EcsRect;

typedef struct EcsColor {
    float r;
    float g;
    float b;
    float a;
} EcsColor;

typedef struct EcsCanvas2D {
    EcsRect window;
    EcsRect viewport;
    const char *title;
    EcsColor background_color;
} EcsCanvas2D;

typedef struct EcsCamera2D {
    EcsVec2 position;
    EcsVec2 zoom;
    bool enabled;
} EcsCamera2D;

typedef struct EcsComponentsGraphicsHandles {
    EcsEntity Color;
    EcsEntity Canvas2D;
    EcsEntity Camera2D;
} EcsComponentsGraphicsHandles;

void EcsComponentsGraphics(
    EcsWorld *world,
    int flags,
    void *handles_out);

#define EcsComponentsGraphics_DeclareHandles(handles)\
    EcsDeclareHandle(handles, Color);\
    EcsDeclareHandle(handles, Canvas2D);\
    EcsDeclareHandle(handles, Camera2D);

#ifdef __cplusplus
}
#endif

#endif
