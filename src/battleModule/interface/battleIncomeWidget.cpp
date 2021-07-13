#include "battleIncomeWidget.h"
#include "rapidjson/document.h"
#include "common/debugModule/logManager.h"
#include "common/utilityModule/stringUtility.h"

using namespace mb::battleModule;

battleIncomeWidget::battleIncomeWidget() {
    this->setName("battleIncomeWidget");
    loadProperty("battle/" + this->getName(), this);
}

battleIncomeWidget::~battleIncomeWidget() {}

void battleIncomeWidget::setIcon(battleIncomeWidget::eIconLabelTypes type) {
    if (hasPropertyObject("settings")) {
        auto settings = getPropertyObject("settings");
        std::string icon;
        switch (type) {
        case eIconLabelTypes::GOLD: icon = "gold"; break;
        case eIconLabelTypes::TROPHIES: icon = "trophies"; break;
        }
        auto it = settings.FindMember(icon.c_str());
        if (it != settings.MemberEnd() && it->value.IsString()) {
            if (auto sprite = dynamic_cast<cocos2d::Sprite*>(findNode("icon"))) {
                sprite->initWithFile(it->value.GetString());
                loadComponent(sprite);
            }
        }
    } else {
        LOG_ERROR("battleIncomeWidget::setIcon Can't load data from settings.");
    }
}
void battleIncomeWidget::setData(int income) {
    if (auto label = dynamic_cast<cocos2d::Label*>(findNode("label"))) {
        if (income < 0) {
            label->setString("0");
        } else if (income >= 10000) {
            label->setString("9999+");
        } else {
            label->setString(std::to_string(income));
        }
    }
}
