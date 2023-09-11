#include "AST/Condition.hpp"
#include "IO.hpp"
#include "Compiler/LLVM/Constant.hpp"

namespace AST
{
    Condition::Condition(CPT::Grammar::Condition *cond)
    {
        IO::Logger::ast_debug("\"Condition\": {\n");
        if (!cond->getCond()) {
            this->condition = nullptr;
        } else {
            this->condition = createValue(cond->getCond());
        }
        if (cond->getIfTrue().size() == 0) {
            this->trueBlock = nullptr;
        } else {
            this->trueBlock = new Block(cond->getIfTrue());
        }
        if (cond->getIfFalse().size() == 0) {
            this->falseBlock = nullptr;
        } else {
            this->falseBlock = new Block(cond->getIfFalse());
        }
        IO::Logger::ast_debug("\"end\": \"success\"},\n");
    }
} // namespace AST
