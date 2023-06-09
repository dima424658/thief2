/*
 * $Source: x:/prj/tech/libsrc/r3d/RCS/utils.h $
 * $Revision: 1.3 $
 * $Author: JAEMZ $
 * $Date: 1998/06/18 11:27:14 $
 *
 * View point related functions
 *
 */

#ifndef __UTILS_H
#define __UTILS_H

#include <matrixs.h>

// Render a wire frame of radius rad.
// The caller is responsible for setting
// object space and color and block
EXTERN void r3_wire_cube(float rad);

// Draws a vector at position pos, and extending towards vec.
// You can scale it and set the maximum size of the vector
// The user is responsible for setting color and block and frame
EXTERN void r3_render_vector(mxs_vector pos,mxs_vector vec,float scale,float maxv);

// The caller is responsible for all that jazz
// even setting object space and color and block
EXTERN void r3_wire_sphere(float rad);

// Pass it a bounding box
EXTERN void r3_wire_bbox(mxs_vector *bmin,mxs_vector *bmax);

#endif // UTILS
