#include "AST/Type.hpp"
#include "AST/Type/Int.hpp"
#include "IO.hpp"
#include <unordered_map>

namespace AST
{
    IType *IType::createType(CPT::Grammar::Type *type)
    {
        IO::Logger::ast_debug("\"Type\": {\n");
        std::string typeName = type->get();
        std::unordered_map<std::string, IType *> typeMap = {
            {"int", new Type::Int(32)},
        };

        if (typeMap.find(typeName) == typeMap.end()) {
            IO::Logger::ast_debug("\"message\": \"Type not found '%d'\",\n", typeName.c_str());
            IO::Logger::ast_debug("\"end\": \"failure\"},\n");
            return nullptr;
        }
        IO::Logger::ast_debug("\"end\": \"success\"},\n");
        return typeMap[typeName];
    }
} // namespace AST
