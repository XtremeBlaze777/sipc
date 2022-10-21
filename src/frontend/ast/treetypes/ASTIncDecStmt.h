#pragma once

#include "ASTExpr.h"
#include "ASTStmt.h"

/*! \brief Class for unary operators: inc & dec.
 */
class ASTIncDecStmt : public ASTStmt {
  std::shared_ptr<ASTExpr> EXPR;
  std::string OP;
public:
  ASTIncDecStmt(std::unique_ptr<ASTExpr> EXPR, const std::string OP)
      : EXPR(std::move(EXPR)), OP(OP) {}
  ASTExpr* getExpr() const { return EXPR.get(); }
  std::string getOp() const { return OP; }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
