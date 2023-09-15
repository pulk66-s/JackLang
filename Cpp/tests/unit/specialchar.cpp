#include "parse.hpp"
#include <CppTester/Assert.hpp>
#include <CppTester/Tests.hpp>
#include "CPT.hpp"

static void assert_char(struct CPT::result *res, char c, bool success) {
    if (success) {
        expect(res->exprs.size()).to.be.equal(1);
        expect(res->exprs[0]->type()).to.be.equal(CPT::CPT_PROGRAM);

        CPT::Grammar::Program *prgm = (CPT::Grammar::Program *)res->exprs[0];
        expect(prgm->get().size()).to.be.equal(1);
        expect(prgm->get()[0]->type()).to.be.equal(CPT::CPT_CHAR);

        CPT::Grammar::SpecialChar *spe = (CPT::Grammar::SpecialChar *)prgm->get()[0];
        expect(spe->get()).to.be.equal(c);
    } else {
        expect(res).to.be.null();
    }
}

Test(specialChar, empty) {
    struct CPT::result *res = parse_file("tests/files/specialchar/empty.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::SpecialChar('a').parse(p);
    });

    assert_char(res, ' ', false);
}

Test(specialChar, matching) {
    struct CPT::result *res = parse_file("tests/files/specialchar/matching.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::SpecialChar('a').parse(p);
    });

    assert_char(res, 'a', true);
}

Test(specialChar, no_matching) {
    struct CPT::result *res = parse_file("tests/files/specialchar/no_matching.cl", [&](CPT::Packrat::Parser &p) {
        return CPT::Grammar::SpecialChar('a').parse(p);
    });

    assert_char(res, ' ', false);
}
