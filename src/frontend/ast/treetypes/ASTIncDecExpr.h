#pragma once

#include "ASTExpr.h"

/*! \brief Class for binary operators: inc & dec.
 */
class ASTIncDecExpr : public ASTExpr {
  std::string OP;
  std::shared_ptr<ASTExpr> EXPR;
public:
  ASTBinaryExpr(const std::string &OP, std::unique_ptr<ASTExpr> EXPR
      : OP(OP), EXPR(std::move(EXPR)) {}
  std::string getOp() const { return OP; }
  ASTExpr* getExpr() const { return EXPR.get(); }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
