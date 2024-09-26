// zv3d_dynarray.h
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

#ifndef ZV3D_DYNARRAY_H
#define ZV3D_DYNARRAY_H

#include "zv3d_collcfg.h"

// "d" -- dynamic array
typedef struct zvd_coll_darray_t {
	void* m_data;
	zvd_coll_size_t m_cnt;
	zvd_coll_size_t m_cap; 
} zvd_coll_darray_t;

zvd_coll_error_t zvd_coll_darray_init(zvd_coll_darray_t* arr);

// synchronize (update) arr->m_data to actual capacity of an array
zvd_coll_error_t zvd_coll_darray_sync_cap(zvd_coll_darray_t* arr);

zvd_coll_error_t zvd_coll_darray_grow(zvd_coll_darray_t* arr, zvd_coll_size_t n, zvd_coll_size_t* poldcnt);
#endif //ZV3D_DYNARRAY_H
