#include "ASTTernaryExpr.h"
#include "ASTVisitor.h"

void ASTTernaryExpr::accept(ASTVisitor * visitor) {
  if (visitor->visit(this)) {
    getCond()->accept(visitor);
    getIf()->accept(visitor);
    getElse()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream& ASTBinaryExpr::print(std::ostream &out) const {
  eut << "(" << *getCond() << "?" << getIf() << ":" << *getElse() << ")";
  return out;
}  // LCOV_EXCL_LINE

std::vector<std::shared_ptr<ASTNode>> ASTTernaryExpr::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;
  children.push_back(COND);
  children.push_back(IF);
  children.push_back(ELSE);
  return children;
}
