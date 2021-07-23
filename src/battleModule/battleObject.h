#ifndef MERCENARY_BATTLES_BATTLEOBJECT_H
#define MERCENARY_BATTLES_BATTLEOBJECT_H

#include "cocos2d.h"
#include "generic/coreModule/nodes/nodeProperties.h"
#include "generic/coreModule/nodes/widgets/node3d.h"

namespace mb::battleModule {

    class battleObject
        : public generic::coreModule::nodeProperties
        , public generic::coreModule::node3d {
      public:
        enum class eBattleObjectSize { SMALL = 0, MEDIUM, LARGE };
        battleObject();
        ~battleObject();
        void setObjectSize(eBattleObjectSize);
        cocos2d::Node* getHolder();

      private:
        cocos2d::Node* holder = nullptr;
    };
}// namespace mb::battleModule


#endif// MERCENARY_BATTLES_BATTLEOBJECT_H
