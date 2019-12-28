/*
*  Copyright 2018 Ivan Ryabov
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*/
#pragma once
#ifndef STYXE_DIALSTRING_HPP
#define STYXE_DIALSTRING_HPP

#include <solace/stringView.hpp>
#include <solace/result.hpp>
#include <solace/error.hpp>


namespace styxe {


extern const Solace::AtomValue kProtocolNone;
extern const Solace::AtomValue kProtocolUnix;
extern const Solace::AtomValue kProtocolUDP;
extern const Solace::AtomValue kProtocolTCP;
extern const Solace::AtomValue kProtocolSCTP;
extern const Solace::AtomValue kProtocolTIPC;


/**
 * Dial string is Plan9 equivalent of URI, but simpler.
 * In general dial string is a string in format: "[protocol:]address[:service]"
 * For example:
 *  - "tcp:google.com:http"
 *  - "udp:10.1.2.3:32"
 *  - "tipc:0.2.117:81"
 *  - "tcp:example.com:ssh"
 *  - "unix:/var/run/socket"
 *  - "some_id"
 *
 */
struct DialString {
	Solace::AtomValue	protocol;	 //!< Network protocol used to connect to a resource (tcp, unix, udp, scpt etc.)
	Solace::StringView  address;	 //!< Network address of remote resource. Usually IP, FQDN or file name.
	Solace::StringView  service{};	 //!< Name of the service to connect to. Can be port number for TCP/UDP
};

/**
 * @brief Parse DailString from a string input.
 * @param data A string possibly representing a dial string.
 * @return Result of parsing: either a DialString or an error.
 */
Solace::Result<DialString, Solace::Error>
tryParseDailString(Solace::StringView data) noexcept;


}  // end of namespace styxe
#endif  // STYXE_DIALSTRING_HPP
