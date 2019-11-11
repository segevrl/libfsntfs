/*
 * Attribute list entry functions
 *
 * Copyright (C) 2010-2019, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFSNTFS_ATTRIBUTE_LIST_ENTRY_H )
#define _LIBFSNTFS_ATTRIBUTE_LIST_ENTRY_H

#include <common.h>
#include <types.h>

#include "libfsntfs_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfsntfs_attribute_list_entry libfsntfs_attribute_list_entry_t;

struct libfsntfs_attribute_list_entry
{
	/* The type
	 */
	uint32_t type;

	/* The size
	 */
	uint16_t size;

	/* The name size
	 */
	uint16_t name_size;

	/* The data first VCN
	 */
	uint64_t data_first_vcn;

	/* The file reference
	 */
	uint64_t file_reference;

	/* The identifier
	 */
	uint16_t identifier;

	/* The name
	 */
	uint8_t *name;
};

int libfsntfs_attribute_list_entry_initialize(
     libfsntfs_attribute_list_entry_t **attribute_list_entry,
     libcerror_error_t **error );

int libfsntfs_attribute_list_entry_free(
     libfsntfs_attribute_list_entry_t **attribute_list_entry,
     libcerror_error_t **error );

int libfsntfs_attribute_list_entry_read_data(
     libfsntfs_attribute_list_entry_t *attribute_list_entry,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error );

int libfsntfs_attribute_list_entry_compare_by_file_reference(
     libfsntfs_attribute_list_entry_t *first_attribute_list_entry,
     libfsntfs_attribute_list_entry_t *second_attribute_list_entry,
     libcerror_error_t **error );

int libfsntfs_attribute_list_entry_get_type(
     libfsntfs_attribute_list_entry_t *attribute_list_entry,
     uint32_t *type,
     libcerror_error_t **error );

int libfsntfs_attribute_list_entry_get_file_reference(
     libfsntfs_attribute_list_entry_t *attribute_list_entry,
     uint64_t *mft_entry_index,
     uint16_t *sequence_number,
     libcerror_error_t **error );

int libfsntfs_attribute_list_entry_get_utf8_name_size(
     libfsntfs_attribute_list_entry_t *attribute_list_entry,
     size_t *utf8_string_size,
     libcerror_error_t **error );

int libfsntfs_attribute_list_entry_get_utf8_name(
     libfsntfs_attribute_list_entry_t *attribute_list_entry,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error );

int libfsntfs_attribute_list_entry_get_utf16_name_size(
     libfsntfs_attribute_list_entry_t *attribute_list_entry,
     size_t *utf16_string_size,
     libcerror_error_t **error );

int libfsntfs_attribute_list_entry_get_utf16_name(
     libfsntfs_attribute_list_entry_t *attribute_list_entry,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error );

int libfsntfs_attribute_list_entry_compare_name_with_utf8_string(
     libfsntfs_attribute_list_entry_t *attribute_list_entry,
     const uint8_t *utf8_string,
     size_t utf8_string_length,
     libcerror_error_t **error );

int libfsntfs_attribute_list_entry_compare_name_with_utf16_string(
     libfsntfs_attribute_list_entry_t *attribute_list_entry,
     const uint16_t *utf16_string,
     size_t utf16_string_length,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFSNTFS_ATTRIBUTE_LIST_ENTRY_H ) */
