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
#include <dialstring/ostream.hpp>

#include <solace/output_utils.hpp>


std::ostream&
styxe::operator<< (std::ostream& ostr, styxe::DialString const& ds) {
	char buff[16];
	atomToString(ds.protocol, buff);

	ostr << buff << ':' << ds.address;
	if (!ds.service.empty()) {
		ostr << ':' << ds.service;
	}

	return ostr;
}
