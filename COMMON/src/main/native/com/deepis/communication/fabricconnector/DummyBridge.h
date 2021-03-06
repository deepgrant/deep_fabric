/**
 *    Copyright (C) 2010 Deep Software Foundation
 *
 *    This program is free software: you can redistribute it and/or  modify
 *    it under the terms of the GNU Affero General Public License, version 3,
 *    as published by the Free Software Foundation.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Affero General Public License for more details.
 *
 *    You should have received a copy of the GNU Affero General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the GNU Affero General Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */
#ifndef COM_DEEPIS_COMMUNICATION_FACBRICCONNECTOR_DUMMYBRIDGE_H_
#define COM_DEEPIS_COMMUNICATION_FACBRICCONNECTOR_DUMMYBRIDGE_H_

#include "com/deepis/db/store/relative/distributed/IMessageService.h"

namespace com { namespace deepis { namespace communication { namespace fabricconnector {
class DummyBridge : public FabricCassiBridgeCb {
public:
	struct MSG_1 {
		static const uinttype MSG_ID          = MSG_ID(0xffff, 0x8080);
	};

	DummyBridge(FabricCassiMessageQueue* pcCommon) :
		FabricCassiBridgeCb(pcCommon) {
	}

	virtual const uinttype* allMessageIds(void) {
		static uinttype iMsgIds[] = {
			MSG_1::MSG_ID,
			0 // Terminate with NIL
		};

		return iMsgIds;
	}

	virtual void remoteOverloaded(cxx::io::encodeProtocol::reader* pcMsg);
	virtual void shutdown();
	virtual void peerStateChanged(cxx::io::encodeProtocol::reader* pcMsg);
	virtual inttype dispatch(cxx::io::encodeProtocol::reader* pcMsg);


}; // DummyBridge

} // fabricconnector
} // communication
} // deepis
} // com

com::deepis::communication::fabricconnector::FabricCassiBridgeCb*
getDummyBridgeInstance(com::deepis::communication::fabricconnector::FabricCassiMessageQueue* pcCommon,
		       voidptr pCtx);

#endif // COM_DEEPIS_COMMUNICATION_FACBRICCONNECTOR_DUMMYBRIDGE_H_
