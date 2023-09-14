#ifndef __CL_UNIT_PARSE_HPP__
#define __CL_UNIT_PARSE_HPP__

#include <string>
#include "CPT.hpp"
#include <functional>

struct CPT::result *parse_file(
    std::string filePath,
    std::function<struct CPT::result *(CPT::Packrat::Parser &)> f
);

#endif
