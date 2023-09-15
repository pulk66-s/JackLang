#include "parse.hpp"
#include <CppTester/Assert.hpp>
#include <CppTester/Tests.hpp>
#include "CPT.hpp"

static void assert_value(struct CPT::result *res, enum CPT::cpt_type type, std::string value) {
    expect(res->exprs.size()).to.be.equal(1);
    expect(res->exprs[0]->type()).to.be.equal(CPT::CPT_PROGRAM);

    CPT::Grammar::Program *prgm = (CPT::Grammar::Program *)res->exprs[0];
    expect(prgm->get().size()).to.be.equal(1);
    expect(prgm->get()[0]->type()).to.be.equal(type);

    switch (type) {
        case CPT::CPT_IDENTIFIER: {
            CPT::Grammar::Identifier *id = (CPT::Grammar::Identifier *)prgm->get()[0];
            expect(id->get()).to.be.equal(value);
            break;
        }
        case CPT::CPT_NUMBER: {
            CPT::Grammar::Number *nb = (CPT::Grammar::Number *)prgm->get()[0];
            expect(nb->get()).to.be.equal(std::stoi(value));
            break;
        }
        case CPT::CPT_UNKNOWN:
            break;
        default:
            throw std::runtime_error("Error, unknown type in maybe_value assert_value function");
    }
}

Test(MaybeValue, empty) {
    struct CPT::result *res = parse_file("tests/files/maybevalue/empty.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::MaybeValue().parse(p);
    });

    assert_value(res, CPT::CPT_UNKNOWN, "");
}

Test(MaybeValue, identifier_value) {
    struct CPT::result *res = parse_file("tests/files/maybevalue/identifier_value.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::MaybeValue().parse(p);
    });

    assert_value(res, CPT::CPT_IDENTIFIER, "a");
}

Test(MaybeValue, int_value) {
    struct CPT::result *res = parse_file("tests/files/maybevalue/int_value.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::MaybeValue().parse(p);
    });

    assert_value(res, CPT::CPT_NUMBER, "42");
}

Test(MaybeValue, wrong_value) {
    struct CPT::result *res = parse_file("tests/files/maybevalue/wrong_value.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::MaybeValue().parse(p);
    });

    assert_value(res, CPT::CPT_UNKNOWN, "");
}
