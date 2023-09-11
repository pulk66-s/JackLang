#ifndef __CL_CPT_GRAMMAR_TYPES_HPP__
#define __CL_CPT_GRAMMAR_TYPES_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT
{
    namespace Grammar
    {
        class Type : public Packrat::IExpr
        {
        public:
            Type(): name("") {};
            Type(std::string name): name(name) {};
            struct result *parse(Packrat::Parser &p) ;
            enum cpt_type type()  { return CPT_TYPE; };
            std::string get() { return name; };

        private:
            std::string name;
        };
    } // namespace Grammar
    
} // namespace CPT

#endif
