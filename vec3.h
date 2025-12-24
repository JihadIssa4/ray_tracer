#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <stdio.h>

/*
 * vec3 structure
 */
typedef struct s_vec3
{
    double e[3];
} vec3;

/*
 * point3 is just an alias for vec3
 */
typedef vec3 point3;

/*
 * Constructors (replacement)
 */
static inline vec3 vec3_create(double e0, double e1, double e2)
{
    vec3 v;
    v.e[0] = e0;
    v.e[1] = e1;
    v.e[2] = e2;
    return v;
}

static inline vec3 vec3_zero(void)
{
    return vec3_create(0.0, 0.0, 0.0);
}

/*
 * Component access
 */
static inline double vec3_x(vec3 v) { return v.e[0]; }
static inline double vec3_y(vec3 v) { return v.e[1]; }
static inline double vec3_z(vec3 v) { return v.e[2]; }

/*
 * Basic operations
 */
static inline vec3 vec3_neg(vec3 v)
{
    return vec3_create(-v.e[0], -v.e[1], -v.e[2]);
}

static inline vec3 vec3_add(vec3 u, vec3 v)
{
    return vec3_create(
        u.e[0] + v.e[0],
        u.e[1] + v.e[1],
        u.e[2] + v.e[2]
    );
}

static inline vec3 vec3_sub(vec3 u, vec3 v)
{
    return vec3_create(
        u.e[0] - v.e[0],
        u.e[1] - v.e[1],
        u.e[2] - v.e[2]
    );
}

static inline vec3 vec3_mul(vec3 u, vec3 v)
{
    return vec3_create(
        u.e[0] * v.e[0],
        u.e[1] * v.e[1],
        u.e[2] * v.e[2]
    );
}

static inline vec3 vec3_mul_scalar(vec3 v, double t)
{
    return vec3_create(
        v.e[0] * t,
        v.e[1] * t,
        v.e[2] * t
    );
}

static inline vec3 vec3_div_scalar(vec3 v, double t)
{
    return vec3_mul_scalar(v, 1.0 / t);
}

/*
 * Length utilities
 */
static inline double vec3_length_squared(vec3 v)
{
    return v.e[0]*v.e[0] + v.e[1]*v.e[1] + v.e[2]*v.e[2];
}

static inline double vec3_length(vec3 v)
{
    return sqrt(vec3_length_squared(v));
}

/*
 * Dot and cross products
 */
static inline double vec3_dot(vec3 u, vec3 v)
{
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

static inline vec3 vec3_cross(vec3 u, vec3 v)
{
    return vec3_create(
        u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]
    );
}

/*
 * Unit vector
 */
static inline vec3 vec3_unit(vec3 v)
{
    return vec3_div_scalar(v, vec3_length(v));
}

/*
 * Output helper (replacement for operator<<)
 */
static inline void vec3_print(vec3 v)
{
    printf("%f %f %f\n", v.e[0], v.e[1], v.e[2]);
}

#endif
