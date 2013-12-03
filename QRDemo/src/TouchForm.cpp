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

#include <FApp.h>
#include "AppResourceId.h"
#include "TouchForm.h"

TouchForm::TouchForm(void)
{
}

TouchForm::~TouchForm(void)
{
}

bool
TouchForm::Initialize(Tizen::Ui::Controls::IFormBackEventListener* back, Tizen::Ui::IActionEventListener* load)
{
    Construct(IDF_FORM);

    __pBackListener = back;
    __pLoadListener = load;

    return true;
}

result
TouchForm::OnInitializing(void)
{
    result r = E_SUCCESS;

    SetFormBackEventListener(__pBackListener);
    return r;
}

result
TouchForm::OnTerminating(void)
{
    result r = E_SUCCESS;
    return r;
}

void
TouchForm::Activate(void)
{
    this->SetShowState(true);
    this->SetEnabled(true);
    Tizen::Ui::Controls::Frame *pFrame = Tizen::App::Application::GetInstance()->GetAppFrame()->GetFrame();
    pFrame->SetCurrentForm(this);
    this->RequestRedraw(true);
}

void
TouchForm::Deactivate(void)
{
    this->SetEnabled(false);
    this->SetShowState(false);
}

void
TouchForm::OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs)
{
    switch(requestId)
    {
    case TouchForm::REQUEST_ACTIVATE:
    {
        Activate();
        break;
    }
    case TouchForm::REQUEST_DEACTIVATE:
    {
        Deactivate();
        break;
    }
    default:
        break;
    }
}

