#include "parse.hpp"
#include <CppTester/Assert.hpp>
#include <CppTester/Tests.hpp>
#include "CPT.hpp"

static void assert_value(struct CPT::result *res, enum CPT::cpt_type type, std::string value) {
    if (type == CPT::CPT_UNKNOWN) {
        expect(res).to.be.null();
    } else if (type == CPT::CPT_NUMBER || type == CPT::CPT_IDENTIFIER) {
        expect(res->exprs.size()).to.be.equal(1);
        expect(res->exprs[0]->type()).to.be.equal(CPT::CPT_PROGRAM);

        CPT::Grammar::Program *prgm = (CPT::Grammar::Program *)res->exprs[0];
        expect(prgm->get().size()).to.be.equal(1);
        if (type == CPT::CPT_NUMBER) {
            expect(prgm->get()[0]->type()).to.be.equal(CPT::CPT_NUMBER);
            CPT::Grammar::Number *nb = (CPT::Grammar::Number *)prgm->get()[0];
            expect(nb->get()).to.be.equal(std::stoi(value));
        } else {
            expect(prgm->get()[0]->type()).to.be.equal(CPT::CPT_IDENTIFIER);
            CPT::Grammar::Identifier *id = (CPT::Grammar::Identifier *)prgm->get()[0];
            expect(id->get()).to.be.equal(value);
        }
    } else {
        throw std::runtime_error("Error, unknown type in values.cpp: assert_value");
    }
}

Test(Value, int) {
    struct CPT::result *res = parse_file("tests/files/values/int.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::Value().parse(p);
    });

    assert_value(res, CPT::CPT_NUMBER, "42");
}

Test(Value, identifier) {
    struct CPT::result *res = parse_file("tests/files/values/identifier.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::Value().parse(p);
    });

    assert_value(res, CPT::CPT_IDENTIFIER, "a");
}

Test(Value, negative) {
    struct CPT::result *res = parse_file("tests/files/values/negative.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::Value().parse(p);
    });

    assert_value(res, CPT::CPT_NUMBER, "-42");
}

Test(Value, empty) {
    struct CPT::result *res = parse_file("tests/files/values/empty.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::Value().parse(p);
    });

    assert_value(res, CPT::CPT_UNKNOWN, "");
}
