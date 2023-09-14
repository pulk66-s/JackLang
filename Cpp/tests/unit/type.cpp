#include "CPT.hpp"
#include "IO.hpp"
#include "parse.hpp"
#include <CppTester/Tests.hpp>
#include <CppTester/Assert.hpp>

static void assert_type(struct CPT::result *res, std::string type) {
    expect(res->exprs.size()).to.be.equal(1);
    expect(res->exprs[0]->type()).to.be.equal(CPT::CPT_PROGRAM);

    CPT::Grammar::Program *prog = (CPT::Grammar::Program *)(res->exprs[0]);
    expect(prog->get().size()).to.be.equal(1);
    expect(prog->get()[0]->type()).to.be.equal(CPT::CPT_TYPE);

    CPT::Grammar::Type *t = (CPT::Grammar::Type *)(prog->get()[0]);
    expect(t->get()).to.be.equal(type);
}

Test(type, int) {
    struct CPT::result *res = parse_file("tests/files/type/int.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::Type().parse(p);
    });

    assert_type(res, "int");
}

Test(type, null) {
    struct CPT::result *res = parse_file("tests/files/type/null.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::Type().parse(p);
    });

    expect(res).to.be.null();
}

Test(type, unknown) {
    struct CPT::result *res = parse_file("tests/files/type/unknown.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::Type().parse(p);
    });

    assert_type(res, "fea");
}

Test(type, wrong_value) {
    struct CPT::result *res = parse_file("tests/files/type/wrong_value.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::Type().parse(p);
    });

    expect(res).to.be.null();
}