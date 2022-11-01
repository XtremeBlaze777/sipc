#pragma once

#include "ASTExpr.h"
#include <ostream>

/*! \brief Class for a unary operator.
 */
class ASTArrIndex : public ASTExpr {
  std::shared_ptr<ASTExpr> IDX;
  std::string ARR;
public:
  ASTArrIndex(std::unique_ptr<ASTExpr> IDX, std::string &ARR)
      : IDX(std::move(IDX)), ARR(ARR) {}
  ASTExpr* getIdx() const { return IDX.get(); }
  std::string getArr() const { return ARR; }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
