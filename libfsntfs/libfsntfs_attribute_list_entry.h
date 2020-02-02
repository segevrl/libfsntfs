/*
 * Attribute list entry functions
 *
 * Copyright (C) 2010-2020, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFSNTFS_ATTRIBUTE_LIST_ENTRY_H )
#define _LIBFSNTFS_ATTRIBUTE_LIST_ENTRY_H

#include <common.h>
#include <types.h>

#include "libfsntfs_extern.h"
#include "libfsntfs_libcerror.h"
#include "libfsntfs_libcthreads.h"
#include "libfsntfs_mft_attribute_list_entry.h"
#include "libfsntfs_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfsntfs_internal_attribute_list_entry libfsntfs_internal_attribute_list_entry_t;

struct libfsntfs_internal_attribute_list_entry
{
	/* The MFT attribute list entry
	 */
	libfsntfs_mft_attribute_list_entry_t *mft_attribute_list_entry;

#if defined( HAVE_LIBFSNTFS_MULTI_THREAD_SUPPORT )
	/* The read/write lock
	 */
	libcthreads_read_write_lock_t *read_write_lock;
#endif
};

int libfsntfs_attribute_initialize(
     libfsntfs_attribute_t **attribute,
     libfsntfs_mft_attribute_list_entry_t *mft_attribute_list_entry,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_attribute_free(
     libfsntfs_attribute_t **attribute,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFSNTFS_ATTRIBUTE_LIST_ENTRY_H ) */

