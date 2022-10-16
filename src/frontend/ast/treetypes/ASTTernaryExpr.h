#pragma once

#include "ASTExpr.h"

/*! \brief Class for a binary operator.
 */
class ASTTernaryExpr : public ASTExpr {
  std::shared_ptr<ASTExpr> COND, IF, ELSE;
public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTBinaryExpr(const std::unique_ptr<ASTExpr> COND, std::unique_ptr<ASTExpr> IF, std::unique_ptr<ASTExpr> ELSE)
      : COND(std::move(COND)), IF(std::move(IF)), ELSE(std::move(ELSE)) {}
  ASTExpr* getCond() const { return COND.get(); }
  ASTExpr* getIf() const { return IF.get(); }
  ASTExpr* getElse() const { return ELSE.get(); }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
