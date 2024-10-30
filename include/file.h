/*
 * This file is part of the PosixCLI distribution (https://github.com/shabman)
 * Copyright (c) 2024 Mustafa Malik (mm2440@kent.ac.uk).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __POSIX_CLI_FILE_H__
#define __POSIX_CLI_FILE_H__

#include "conf.h"

POSIX_BEGIN_DECLS

/**
 * @brief Checks if the given directory path exists
 *
 * @param path - the path to check
 * @return true if present, otherwise false
 */
int pcli_dir_exists ( const char* );

/**
 * @brief Checks if the given file path exists
 *
 * @param path - the path to check
 * @return true if present, otherwise false
 */
int pcli_file_exists ( const char* );

/**
 * @brief Gets the parent working directory of the current directory
 *
 * @param array - The array buffer to store the path in
 * @param size - The size of the array buffer
 * @param path - The current working directory path
 * @return The new path, the parent working directory
 */
char* pcli_get_pwd ( char*, size_t, const char* );

POSIX_END_DECLS

#endif /* __POSIX_CLI_FILE_H__ */