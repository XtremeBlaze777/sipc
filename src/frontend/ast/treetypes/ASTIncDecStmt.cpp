#include "ASTIncDecStmt.h"
#include "ASTVisitor.h"

void ASTIncDecStmt::accept(ASTVisitor * visitor) {
  if (visitor->visit(this)) {
    getStmt()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream& ASTIncDecStmt::print(std::ostream &out) const {
  out << "(" << *getStmt() << getOp() << ")";
  return out;
}  // LCOV_EXCL_LINE
