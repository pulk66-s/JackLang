#include "Compiler/LLVM/Lib/Module.hpp"
#include "IO.hpp"

namespace Comp::LLVM::Lib
{
    Module::Module(Context *context)
    {
        module = new llvm::Module("main", *context->get());
    }

    void Module::dumpToFile(std::string filename)
    {
        IO::File f(filename);
        std::string s = "";
        llvm::raw_string_ostream stream(s);
        module->print(stream, nullptr);
        f.write(stream.str());
    }

    void Module::dump()
    {
        this->module->print(llvm::outs(), nullptr);
    }
} // namespace Comp::LLVM::Lib
