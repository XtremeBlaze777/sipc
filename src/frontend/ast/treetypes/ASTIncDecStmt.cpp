#include "ASTIncDecStmt.h"
#include "ASTVisitor.h"

void ASTIncDecStmt::accept(ASTVisitor * visitor) {
  if (visitor->visit(this)) {
    getExpr()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream& ASTIncDecStmt::print(std::ostream &out) const {
  out << *getExpr() << getOp();
  return out;
}  // LCOV_EXCL_LINE
