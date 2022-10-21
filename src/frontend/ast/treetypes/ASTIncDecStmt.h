#pragma once

#include "ASTStmt.h"

/*! \brief Class for unary operators: inc & dec.
 */
class ASTIncDecStmt : public ASTStmt {
  std::shared_ptr<ASTStmt> STMT;
  std::string OP;
public:
  ASTIncDecStmt(std::unique_ptr<ASTStmt> STMT, const std::string &OP)
      : STMT(std::move(STMT)), OP(OP) {}
  ASTStmt* getStmt() const { return STMT.get(); }
  std::string getOp() const { return OP; }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
