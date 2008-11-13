/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef _D_DOWNLOAD_HELPER_H_
#define _D_DOWNLOAD_HELPER_H_

#include "common.h"

#include <string>
#include <deque>

#include "SharedHandle.h"

namespace aria2 {

class RequestGroup;
class Option;

// Create RequestGroup object using torrent file specified by torrent-file 
// option. In this function, force-sequential is ignored.
void createRequestGroupForBitTorrent
(std::deque<SharedHandle<RequestGroup> >& result, Option* op,
 const std::deque<std::string>& uris);

// Create RequestGroup objects using Metalink file specified by metalink-file
// option.
void createRequestGroupForMetalink
(std::deque<SharedHandle<RequestGroup> >& result, Option* op);

// Create RequestGroup objects from reading file specified by input-file option.
// If the value of input-file option is "-", stdin is used as a input source.
// Each line is treated as if it is provided in command-line argument.
// The additional out and dir options can be specified after each line of URIs.
// This optional line must start with white space(s).
void createRequestGroupForUriList
(std::deque<SharedHandle<RequestGroup> >& result, Option* op);

// Create RequestGroup object using provided uris.
void createRequestGroupForUri
(std::deque<SharedHandle<RequestGroup> >& result, Option* op,
 const std::deque<std::string>& uris);

} // namespace aria2

#endif // _D_DOWNLOAD_HELPER_H_