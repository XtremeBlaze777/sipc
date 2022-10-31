#pragma once

#include "ASTExpr.h"

/*! \brief Class for a unary operator.
 */
class ASTUnaryExpr : public ASTExpr {
  std::string OP;
  std::shared_ptr<ASTExpr> RIGHT;
public:
  ASTUnaryExpr(const std::string &OP, std::unique_ptr<ASTExpr> RIGHT)
      : OP(OP), RIGHT(std::move(RIGHT)) {}
  std::string getOp() const { return OP; }
  ASTExpr* getRight() const { return RIGHT.get(); }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
