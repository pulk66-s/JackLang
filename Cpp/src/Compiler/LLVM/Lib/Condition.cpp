#include "Compiler/LLVM/Lib/Condition.hpp"

namespace Comp::LLVM::Lib
{
    Condition::Condition(
        Block *true_,
        Block *false_,
        Value *condition,
        Block *source,
        Builder *builder
    ) {
        builder->setInsertPoint(source);
        this->condition = condition->get();
        this->true_ = true_;
        this->false_ = false_;
        builder->createCond(this);
    }
} // namespace Comp::LLVM::Lib
