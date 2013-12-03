/*
 * QRMessagePort.cpp
 *
 *  Created on: Sep 13, 2013
 *      Author: User
 */
#include <FWebJson.h>
#include "QRMessagePort.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base::Utility;
using namespace Tizen::Io;
using namespace Tizen::Web::Json;

QRMessagePort::QRMessagePort()
{
}

QRMessagePort::~QRMessagePort()
{
}

result
QRMessagePort::Construct(const String& localPortName)
{
	result r = E_SUCCESS;
	return r;
}

result
QRMessagePort::SendMessage(const IMap* pMessage)
{
	result r = E_SUCCESS;
	AppLog("SendMessage is called.");

	if (__pRemoteMessagePort != null)
	{
		r = __pRemoteMessagePort->SendMessage(pMessage);
	}
	else
	{
		r = E_FAILURE;
	}

	return r;
}
