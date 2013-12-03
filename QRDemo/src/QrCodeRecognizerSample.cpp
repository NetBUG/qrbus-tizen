//
// Tizen C++ SDK
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "QrCodeRecognizerSample.h"
#include "CameraTools.h"
#include "GLtools.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::System;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

const char* pTagApp = "QrCodeRecognizer";

QrCodeRecognizer::QrCodeRecognizer()
    : __pTracker(0)
    , __pForm(0)
{
}

QrCodeRecognizer::~QrCodeRecognizer()
{
	DeviceManager::RemoveDeviceEventListener(Charger,*this);
}


UiApp*
QrCodeRecognizer::CreateInstance(void)
{
    // Create the instance through the constructor.
    return new QrCodeRecognizer();
}

bool
QrCodeRecognizer::OnAppInitializing(AppRegistry& appRegistry)
{
    PowerManager::KeepScreenOnState(true, false);
    return true;
}

bool
QrCodeRecognizer::OnAppInitialized(void)
{
	Frame* pAppFrame = new Frame();
    pAppFrame->Construct();
    AddFrame(*pAppFrame);

    __pForm = new TouchForm();
    __pForm->Initialize(this, this);
    pAppFrame->AddControl(__pForm);

    // dealing with low battery
    DeviceManager::AddDeviceEventListener(Charger,*this);
    bool isCharging = true;
	Tizen::System::RuntimeInfo::GetValue(String(L"IsCharging"),isCharging);
	if (isCharging == false)
	{
		BatteryLevel level = BATTERY_FULL;
		Tizen::System::Battery::GetCurrentLevel(level);
		if ((level == BATTERY_EMPTY) || (level == BATTERY_CRITICAL) || (level == BATTERY_LOW))
		{
			MessageBox msgBox;
			int result = 0;

			msgBox.Construct("Warning", "Low battery. Terminating App.", MSGBOX_STYLE_NONE, 3000);
			msgBox.ShowAndWait(result);
			Tizen::App::Application::GetInstance()->Terminate();
			return false;
		}
	}

    if (!GLtools::initGL(__pForm))
    {
    	MessageBox msgBox;
		int result = 0;

		msgBox.Construct("Warning", "Cannot init OpenGL. Terminating App.", MSGBOX_STYLE_NONE, 3000);
		msgBox.ShowAndWait(result);
		Tizen::App::Application::GetInstance()->Terminate();
		return false;
    }

    __pTracker = new Tracker();

    if (!CameraTools::InitCamera(*__pTracker, Tracker::DESIRED_CAMERA_WIDTH, Tracker::DESIRED_CAMERA_HEIGHT))
    {
    	MessageBox msgBox;
		int result = 0;

		msgBox.Construct("Warning","Cannot init camera. Terminating App.", MSGBOX_STYLE_NONE, 3000);
		msgBox.ShowAndWait(result);
		Tizen::App::Application::GetInstance()->Terminate();
		return false;
    }

    __pForm->SendUserEvent(TouchForm::REQUEST_ACTIVATE, null);

   	__pTracker->Init(__pForm);

    return true;
}

bool
QrCodeRecognizer::OnAppWillTerminate(void)
{
    return true;
}

bool
QrCodeRecognizer::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
    if (__pTracker)
    {
        __pTracker->DoRendering(false);
        delete __pTracker;
        __pTracker = null;
    }

    GLtools::destroyGL();
    CameraTools::StopCamera();

    return true;
}

void
QrCodeRecognizer::OnForeground(void)
{
	AppSecureLogTag(pTagApp, "OnForeground");
    PowerManager::KeepScreenOnState(true, false);
    if (!CameraTools::StartCamera())
    {
    	MessageBox msgBox;
		int result = 0;

		msgBox.Construct("Warning", "Cannot restart camera. Terminating App.", MSGBOX_STYLE_NONE, 3000);
		msgBox.ShowAndWait(result);
		Tizen::App::Application::GetInstance()->Terminate();
    }
}

// Called when application is moved to background
void
QrCodeRecognizer::OnBackground(void)
{
    CameraTools::StopCamera();
}

void
QrCodeRecognizer::OnLowMemory(void)
{
}

void
QrCodeRecognizer::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	bool isCharging = true;
	Tizen::System::RuntimeInfo::GetValue(String(L"IsCharging"),isCharging);
	if (isCharging == false)
	{
		if ((batteryLevel == BATTERY_EMPTY) || (batteryLevel == BATTERY_CRITICAL) || (batteryLevel == BATTERY_LOW))
		{
			MessageBox msgBox;
			int result = 0;

			msgBox.Construct("Warning","Low Battery.\nTerminating App.",MSGBOX_STYLE_NONE,8000);
			msgBox.ShowAndWait(result);
			Application::GetInstance()->Terminate();
		}
	}
}

bool
QrCodeRecognizer::OnKeyPressed (Control &source, const KeyEventInfo &keyEventInfo)
{
	return false;
}

bool
QrCodeRecognizer::OnKeyReleased (Control &source, const KeyEventInfo &keyEventInfo)
{
	return false;
}

bool
QrCodeRecognizer::OnPreviewKeyPressed (Control &source, const KeyEventInfo &keyEventInfo)
{
	return false;
}

bool
QrCodeRecognizer::OnPreviewKeyReleased (Control &source, const KeyEventInfo &keyEventInfo)
{
	return false;
}

bool
QrCodeRecognizer::TranslateKeyEventInfo (Control &source, KeyEventInfo &keyEventInfo)
{
	return false;
}

void
QrCodeRecognizer::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{

}

void
QrCodeRecognizer::OnFormBackRequested(Tizen::Ui::Controls::Form &source)
{
	if (__pTracker && (CameraTools::GetCamera()->GetState() == Tizen::Media::CAMERA_STATE_PREVIEW || CameraTools::GetCamera()->GetState() == Tizen::Media::CAMERA_STATE_AUTO_FOCUSING))
	        {
	            __pTracker->Terminate();
	        }
	        else
	        {
	            Tizen::App::Application::GetInstance()->Terminate();
	        }
}

void
QrCodeRecognizer::OnDeviceStateChanged(Tizen::System::DeviceType deviceType, const Tizen::Base::String &state)
{
    if (deviceType == Charger)
    {
    	BatteryLevel level = BATTERY_FULL;
    	Tizen::System::Battery::GetCurrentLevel(level);
    	OnBatteryLevelChanged(level);
    }
}
