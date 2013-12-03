/*
 * QRMessagePort.h
 *
 *  Created on: Nov 29, 2013
 *      Author: NetBUG
 */

#ifndef QRMESSAGEPORT_H_
#define QRMESSAGEPORT_H_

#include <FApp.h>
#include <FBase.h>
#include <FIo.h>

class QRMessagePort: public Tizen::Io::IMessagePortListener {
public:
	QRMessagePort();
	virtual ~QRMessagePort();

	result Construct(const Tizen::Base::String& localPortName);

	//virtual void OnMessageReceivedN(Tizen::Io::RemoteMessagePort* pRemoteMessagePort, Tizen::Base::Collection::IMap* pMessage);

	result SendMessage(const Tizen::Base::Collection::IMap* pMessage);

private :
	Tizen::Io::LocalMessagePort* __pLocalMessagePort;
	Tizen::Io::RemoteMessagePort* __pRemoteMessagePort;
};

#endif /* QRMESSAGEPORT_H_ */
