// zv3d_dynarray.c
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

#include "zv3d_dynarray.h"

zvd_coll_error_t zvd_coll_darray_init(zvd_coll_darray_t* arr) {
	if (!arr) return k_zvd_coll_err_invarg;
	arr->m_data = 0;
	arr->m_cnt = 0;
	arr->m_cap = 0;
	return k_zvd_coll_err_ok;
}

// synchronize (update) arr->m_data to actual capacity of an array
zvd_coll_error_t zvd_coll_darray_sync_cap(zvd_coll_darray_t* arr) {
	zvd_coll_size_t n_bytes_req;
	
	if (!arr) return k_zvd_coll_err_invarg;
	n_bytes_req = arr->m_cap * sizeof(zvd_coll_darray_t);
	
	if (0 == n_bytes_req) {
		if (arr->m_data) {
			zvd_coll_mem_free(arr->m_data);
			arr->m_data = 0;
		}
	} else {
		if (arr->m_data) {
			arr->m_data = zvd_coll_mem_realloc(arr->m_data, n_bytes_req);
		} else {
			arr->m_data = zvd_coll_mem_alloc(n_bytes_req);
			if (!arr->m_data)
				return k_zvd_coll_err_badalloc;
		}
	}
	return k_zvd_coll_err_ok;	
}

zvd_coll_error_t zvd_coll_darray_grow(zvd_coll_darray_t* arr, zvd_coll_size_t n, zvd_coll_size_t* poldcnt) {
	zvd_coll_error_t retval;
	zvd_coll_size_t nsize_req;
	if (!arr) return k_zvd_coll_err_invarg;
	
	if (!poldcnt)
		*poldcnt = arr->m_cnt;
	nsize_req = arr->m_cnt + n;
	if (nsize_req > arr->m_cap) {
		if (arr->m_cap == 0)
			arr->m_cap = K_ZVD_COLL_DARR_MINCAP;

		while (arr->m_cap < nsize_req)
			arr->m_cap += (arr->m_cap << 1);
		retval = zvd_coll_darray_sync_cap(arr);
		if (k_zvd_coll_err_ok != retval)
			return retval;
	}
	
	arr->m_cnt += nsize_req;
	return k_zvd_coll_err_ok;
}