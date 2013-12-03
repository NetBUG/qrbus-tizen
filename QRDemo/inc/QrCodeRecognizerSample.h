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

#ifndef _QR_CODE_RECOGNIZER_SAMPLE_H_
#define _QR_CODE_RECOGNIZER_SAMPLE_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FMedia.h>

#include "TouchForm.h"
#include "Tracker.h"
#include "QRMessagePort.h"

class QrCodeRecognizer
    : public Tizen::App::UiApp
    , public Tizen::Ui::IPropagatedKeyEventListener
    , public Tizen::Ui::IActionEventListener
    , public Tizen::Ui::Controls::IFormBackEventListener
    , public Tizen::System::IDeviceEventListener
{
public:
    static Tizen::App::Application* CreateInstance(void);

public:
    QrCodeRecognizer();
    virtual ~QrCodeRecognizer();

public:
    // Called when the UiApp is initializing.
    bool OnAppInitializing(Tizen::App::AppRegistry& appRegistry);

    // Called when the UiApp initializing is finished.
    bool OnAppInitialized(void);

    // Called when the UiApp is requested to terminate.
    bool OnAppWillTerminate(void);

    // Called when the UiApp is terminating.
    bool OnAppTerminating(Tizen::App::AppRegistry& appRegistry, bool forcedTermination = false);

    // Called when the UiApp's frame moves to the top of the screen.
    void OnForeground(void);

    // Called when this UiApp's frame is moved from top of the screen to the background.
    void OnBackground(void);

    // Called when the system memory is not sufficient to run the UiApp any further.
    void OnLowMemory(void);

    // Called when the battery level changes.
    void OnBatteryLevelChanged(Tizen::System::BatteryLevel batteryLevel);

    virtual bool OnKeyPressed (Tizen::Ui::Control &source, const Tizen::Ui::KeyEventInfo &keyEventInfo);

    virtual bool OnKeyReleased (Tizen::Ui::Control &source, const Tizen::Ui::KeyEventInfo &keyEventInfo);

    virtual bool OnPreviewKeyPressed (Tizen::Ui::Control &source, const Tizen::Ui::KeyEventInfo &keyEventInfo);

    virtual bool OnPreviewKeyReleased (Tizen::Ui::Control &source, const Tizen::Ui::KeyEventInfo &keyEventInfo);

    virtual bool TranslateKeyEventInfo (Tizen::Ui::Control &source, Tizen::Ui::KeyEventInfo &keyEventInfo);

    virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

    void OnFormBackRequested(Tizen::Ui::Controls::Form &source);

	// Called when device is connected or removed
	virtual void OnDeviceStateChanged(Tizen::System::DeviceType deviceType, const Tizen::Base::String &state);

private:
    Tracker*                    __pTracker;
    TouchForm*                  __pForm;
};

#endif // _QR_CODE_RECOGNIZER_SAMPLE_H_
