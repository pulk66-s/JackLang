#include "parse.hpp"
#include "CPT.hpp"
#include <CppTester/Assert.hpp>
#include <CppTester/Tests.hpp>

static void assertVarDecl(
    struct CPT::result *res,
    std::string type,
    std::string name,
    std::string value,
    enum CPT::cpt_type valueType
) {
    if (type == "" && name == "" && value == "") {
        expect(res).to.be.null();
    } else {
        expect(res->exprs.size()).to.be.equal(1);
        expect(res->exprs[0]->type()).to.be.equal(CPT::CPT_PROGRAM);

        CPT::Grammar::Program *prog = (CPT::Grammar::Program *)res->exprs[0];
        expect(prog->get().size()).to.be.equal(1);
        expect(prog->get()[0]->type()).to.be.equal(CPT::CPT_VARDECL);

        CPT::Grammar::VariableDecl *varDecl = (CPT::Grammar::VariableDecl *)prog->get()[0];
        expect(varDecl->getType()->get()).to.be.equal(type);
        expect(varDecl->get()).to.be.equal(name);
        expect(varDecl->getValue()->type()).to.be.equal(valueType);

        switch (valueType) {
            case CPT::CPT_NUMBER: {
                CPT::Grammar::Number *num = (CPT::Grammar::Number *)varDecl->getValue();
                expect(num->get()).to.be.equal(std::stoi(value));
                break;
            }
            case CPT::CPT_IDENTIFIER: {
                CPT::Grammar::Identifier *identifier = (CPT::Grammar::Identifier *)varDecl->getValue();
                expect(identifier->get()).to.be.equal(value);
                break;
            }
            default:
                throw std::runtime_error("Unknown value type for assertVarDecl");
        }
    }
}

Test(VariableDecl, Simple)
{
    struct CPT::result *res = parse_file("tests/files/variables/decl/basicInt.cl", [&](struct CPT::Packrat::Parser &p) {
        return CPT::Grammar::VariableDecl().parse(p);
    });

    assertVarDecl(res, "int", "a", "42", CPT::CPT_NUMBER);
}

Test(VariableDecl, empty)
{
    struct CPT::result *res = parse_file("tests/files/variables/decl/empty.cl", [&](struct CPT::Packrat::Parser &p) {
        return CPT::Grammar::VariableDecl().parse(p);
    });

    assertVarDecl(res, "", "", "", CPT::CPT_UNKNOWN);
}

Test(VariableDecl, identifier)
{
    struct CPT::result *res = parse_file("tests/files/variables/decl/identifier.cl", [&](struct CPT::Packrat::Parser &p) {
        return CPT::Grammar::VariableDecl().parse(p);
    });

    assertVarDecl(res, "int", "a", "b", CPT::CPT_IDENTIFIER);
}

Test(VariableDecl, no_name)
{
    struct CPT::result *res = parse_file("tests/files/variables/decl/no_name.cl", [&](struct CPT::Packrat::Parser &p) {
        return CPT::Grammar::VariableDecl().parse(p);
    });

    assertVarDecl(res, "", "", "", CPT::CPT_UNKNOWN);
}

Test(VariableDecl, no_special_char)
{
    struct CPT::result *res = parse_file("tests/files/variables/decl/no_special_char.cl", [&](struct CPT::Packrat::Parser &p) {
        return CPT::Grammar::VariableDecl().parse(p);
    });

    assertVarDecl(res, "", "", "", CPT::CPT_UNKNOWN);
}

Test(VariableDecl, no_type)
{
    struct CPT::result *res = parse_file("tests/files/variables/decl/no_type.cl", [&](struct CPT::Packrat::Parser &p) {
        return CPT::Grammar::VariableDecl().parse(p);
    });

    assertVarDecl(res, "", "", "", CPT::CPT_UNKNOWN);
}

Test(VariableDecl, no_value)
{
    struct CPT::result *res = parse_file("tests/files/variables/decl/no_value.cl", [&](struct CPT::Packrat::Parser &p) {
        return CPT::Grammar::VariableDecl().parse(p);
    });

    assertVarDecl(res, "", "", "", CPT::CPT_UNKNOWN);
}

Test(VariableDecl, unknown_type)
{
    struct CPT::result *res = parse_file("tests/files/variables/decl/unknown_type.cl", [&](struct CPT::Packrat::Parser &p) {
        return CPT::Grammar::VariableDecl().parse(p);
    });

    assertVarDecl(res, "fea", "a", "42", CPT::CPT_NUMBER);
}

Test(VariableDecl, wrong_name)
{
    struct CPT::result *res = parse_file("tests/files/variables/decl/wrong_name.cl", [&](struct CPT::Packrat::Parser &p) {
        return CPT::Grammar::VariableDecl().parse(p);
    });

    assertVarDecl(res, "", "", "", CPT::CPT_UNKNOWN);
}

Test(VariableDecl, wrong_special_char)
{
    struct CPT::result *res = parse_file("tests/files/variables/decl/wrong_special_char.cl", [&](struct CPT::Packrat::Parser &p) {
        return CPT::Grammar::VariableDecl().parse(p);
    });

    assertVarDecl(res, "", "", "", CPT::CPT_UNKNOWN);
}

Test(VariableDecl, wrong_type)
{
    struct CPT::result *res = parse_file("tests/files/variables/decl/wrong_type.cl", [&](struct CPT::Packrat::Parser &p) {
        return CPT::Grammar::VariableDecl().parse(p);
    });

    assertVarDecl(res, "", "", "", CPT::CPT_UNKNOWN);
}
