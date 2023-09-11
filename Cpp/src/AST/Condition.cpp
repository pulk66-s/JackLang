#include "AST/Condition.hpp"
#include "IO.hpp"

namespace AST
{
    Condition::Condition(CPT::Grammar::Condition *cond)
    {
        IO::Logger::ast_debug("\"Condition\": {\n");
        this->condition = createExpr(cond->getCond());
        this->trueBlock = new Block(cond->getIfTrue());
        this->falseBlock = new Block(cond->getIfFalse());
        IO::Logger::ast_debug("\"end\": \"success\"},\n");
    }
} // namespace AST
