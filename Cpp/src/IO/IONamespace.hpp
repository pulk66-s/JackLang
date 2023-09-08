#ifndef __CL_IO_IONAMESPACE_HPP__
#define __CL_IO_IONAMESPACE_HPP__

#include "CPT.hpp"

namespace IO {
    class File;
    class Logger;
    namespace CPT_log {
        void printExpr(CPT::Packrat::IExpr *expr);
        void printExprs(std::vector<CPT::Packrat::IExpr *> exprs);
        void printPrgm(CPT::Grammar::Program *prgm);
        void printNb(CPT::Grammar::Number *nb);
        void printIdentifier(CPT::Grammar::Identifier *id);
        void printChar(CPT::Grammar::SpecialChar *c);
        void printType(CPT::Grammar::Type *type);
        void printVar(CPT::Grammar::Variable *var);
    };
};

#endif
