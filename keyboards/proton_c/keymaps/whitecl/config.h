/* Copyright 2018 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#undef MATRIX_ROWS
#undef MATRIX_COLS

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { B8, B13, B14, B15, B9 }
#define MATRIX_COL_PINS { A8, A7, A6, A5, A4, B0, B1, B2, B3, B4, B5, B6 }
