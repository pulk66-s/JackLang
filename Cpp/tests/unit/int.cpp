#include <CppTester/Tests.hpp>
#include <CppTester/Assert.hpp>
#include <string>
#include "CPT.hpp"
#include "IO.hpp"
#include "parse.hpp"

Test(int_parsing, basic) {
    struct CPT::result *r = parse_file("tests/files/numbers/basicInt.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::Number().parse(p);
    });

    expect(r->exprs.size()).to.be.equal(1);
    expect(r->exprs[0]->type()).to.be.equal(CPT::CPT_PROGRAM);

    CPT::Grammar::Program *prog = (CPT::Grammar::Program *)(r->exprs[0]);
    expect(prog->get().size()).to.be.equal(1);
    expect(prog->get()[0]->type()).to.be.equal(CPT::CPT_NUMBER);

    CPT::Grammar::Number *num = (CPT::Grammar::Number *)(prog->get()[0]);
    expect(num->get()).to.be.equal(42);
}
