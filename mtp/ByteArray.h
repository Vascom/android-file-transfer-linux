/*
 * Android File Transfer for Linux: MTP client for android devices
 * Copyright (C) 2015  Vladimir Menshakov

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef BYTEARRAY_H
#define	BYTEARRAY_H

#include <mtp/types.h>
#include <vector>
#include <stdio.h>

namespace mtp
{
	typedef std::vector<u8> ByteArray;

	inline void HexDump(const std::string &prefix, const ByteArray &data)
	{
		printf("%s:\n", prefix.c_str());
		for(size_t i = 0; i < data.size(); ++i)
		{
			bool first = ((i & 0xf) == 0);
			bool last = ((i & 0xf) == 0x0f);
			if (first)
				printf("%08lx: ", (unsigned long)i);
			u8 byte = data[i];
			printf("%02x ", byte);
			if (last)
				printf("\n");
		}
		printf("\n");
	}
}

#endif	/* BYTEARRAY_H */
