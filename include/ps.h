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

#ifndef __POSIX_CLI_PS_H__
#define __POSIX_CLI_PS_H__

#include "conf.h"

POSIX_BEGIN_DECLS

/**
 * @brief (process status) displays the currently running process(es)
 * For this instance, it will display PosixCLI's running process id (PID)
 *
 * @return pid - The process id
 */
pid_t pcli_ps ( void );

POSIX_END_DECLS

#endif /* __POSIX_CLI_PS_H__ */