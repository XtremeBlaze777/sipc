#include "ASTIncDecExpr.h"
#include "ASTVisitor.h"

void ASTIncDecExpr::accept(ASTVisitor * visitor) {
  if (visitor->visit(this)) {
    getExpr()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream& ASTBinaryExpr::print(std::ostream &out) const {
  out << "(" << *getExpr() << getOp() << ")";
  return out;
}  // LCOV_EXCL_LINE
