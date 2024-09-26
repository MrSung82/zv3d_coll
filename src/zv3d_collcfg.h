// zv3d_collcfg.h
/* MIT License

Copyright (c) 2024 Marat Sungatullin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef ZV3D_COLLCFG_H
#define ZV3D_COLLCFG_H


#include <stdlib.h>
#include <stddef.h>

#ifdef __GNUC__
#define zvd_cdecl __attribute__((__cdecl__))
#endif

typedef unsigned zvd_coll_size_t;
extern const zvd_coll_size_t k_zvd_coll_size_max;

typedef unsigned zvd_coll_index_t;
extern const zvd_coll_index_t k_zvd_coll_index_bad;

typedef unsigned char zvd_coll_byte_t;

typedef enum zvd_coll_error_t {
    k_zvd_coll_err_ok,
    k_zvd_coll_err_unk,
    k_zvd_coll_err_invarg,
    k_zvd_coll_err_badalloc
} zvd_coll_error_t;

typedef void* (zvd_cdecl* zvd_coll_mem_alloc_t)(zvd_coll_size_t);
extern zvd_coll_mem_alloc_t zvd_coll_mem_alloc;

typedef void* (zvd_cdecl* zvd_coll_mem_realloc_t)(void*, zvd_coll_size_t);
extern zvd_coll_mem_realloc_t zvd_coll_mem_realloc;

typedef void (zvd_cdecl* zvd_coll_mem_free_t)(void*);
extern zvd_coll_mem_free_t zvd_coll_mem_free;

// minimal capacity of dunamic array
#define K_ZVD_COLL_DARR_MINCAP 16
#endif //ZV3D_COLLCFG_H
