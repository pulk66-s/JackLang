#include "Compiler/LLVM/Condition.hpp"
#include "Compiler/LLVM/Block.hpp"
#include "Compiler/LLVM/Value.hpp"
#include <iostream>

namespace Comp::LLVM
{
    Condition::Condition(
        AST::Condition *cond,
        Lib::Context *context,
        Lib::Block *block,
        Lib::Function *function,
        Lib::Builder *builder
    ) {
        AST::Block *true_ = cond->getTrueBlock();
        AST::Block *false_ = cond->getFalseBlock();
        AST::IExpr *condition = cond->getCondition();

        if (!true_) {
            std::cout << "No true block" << std::endl;
            exit(1);
        }
        if (!false_) {
            std::cout << "No false block" << std::endl;
            exit(1);
        }
        if (!condition) {
            std::cout << "No condition" << std::endl;
            exit(1);
        }

        Block *trueBlock = new Block(true_, context, function, builder);
        Block *falseBlock = new Block(false_, context, function, builder);
        Value *conditionValue = new Value(condition, context);

        this->condition = new Lib::Condition(
            trueBlock->get(),
            falseBlock->get(),
            conditionValue->get(),
            block,
            builder
        );
    }
} // namespace Comp::LLVM
