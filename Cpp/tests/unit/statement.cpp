#include <CppTester/Tests.hpp>
#include <CppTester/Assert.hpp>
#include "CPT.hpp"
#include "parse.hpp"

Test(Statement, empty) {
    struct CPT::result *res = parse_file("tests/files/statement/empty.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::Statement().parse(p);
    });

    expect(res).to.be.null();
}

Test(Statement, variable_decl) {
    struct CPT::result *res = parse_file("tests/files/statement/variable_decl.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::Statement().parse(p);
    });

    expect(res->exprs.size()).to.be.equal(1);
    expect(res->exprs[0]->type()).to.be.equal(CPT::CPT_PROGRAM);
    
    CPT::Grammar::Program *prgm = (CPT::Grammar::Program *)res->exprs[0];
    expect(prgm->get().size()).to.be.equal(1);
    expect(prgm->get()[0]->type()).to.be.equal(CPT::CPT_VARDECL);

    CPT::Grammar::VariableDecl *vardecl = (CPT::Grammar::VariableDecl *)prgm->get()[0];
    expect(vardecl->getType()->get()).to.be.equal("int");
    expect(vardecl->get()).to.be.equal("a");
    expect(vardecl->getValue()->type()).to.be.equal(CPT::CPT_NUMBER);

    CPT::Grammar::Number *nb = (CPT::Grammar::Number *)vardecl->getValue();
    expect(nb->get()).to.be.equal(42);
}
