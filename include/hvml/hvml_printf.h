// This file is a part of Purring Cat, a reference implementation of HVML.
//
// Copyright (C) 2020, <freemine@yeah.net>.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef _hvml_printf_h_
#define _hvml_printf_h_

#include "hvml/hvml_dom.h"
#include "hvml/hvml_jo.h"
#include "hvml/hvml_string.h"

#include <stddef.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int hvml_dom_serialize(hvml_dom_t *dom, hvml_stream_t *stream);
int hvml_jo_value_serialize(hvml_jo_value_t *jo, hvml_stream_t *stream);

int hvml_dom_printf(hvml_dom_t *dom, FILE *out);
int hvml_jo_value_printf(hvml_jo_value_t *jo, FILE *out);

int hvml_dom_serialize_string(hvml_dom_t *dom, hvml_string_t *str);
int hvml_jo_value_serialize_string(hvml_jo_value_t *jo, hvml_string_t *str);

#ifdef __cplusplus
}
#endif

#endif // _hvml_printf_h_

