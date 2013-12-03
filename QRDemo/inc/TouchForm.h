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

#ifndef _TOUCHFORM_H_
#define _TOUCHFORM_H_

#include <FBase.h>
#include <FUi.h>

class TouchForm
    : public Tizen::Ui::Controls::Form
{
public:
    TouchForm(void);
    virtual ~TouchForm(void);
    bool Initialize(Tizen::Ui::Controls::IFormBackEventListener* back, Tizen::Ui::IActionEventListener* load);

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);

    virtual void OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs);

    static const RequestId REQUEST_ACTIVATE = 100;
    static const RequestId REQUEST_DEACTIVATE = 101;

private:
    void Activate(void);
    void Deactivate(void);

    Tizen::Ui::Controls::IFormBackEventListener* __pBackListener;
    Tizen::Ui::IActionEventListener*             __pLoadListener;

};

#endif // _TOUCHFORM_H_
