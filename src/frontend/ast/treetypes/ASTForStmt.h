#pragma once

#include "ASTStmt.h"
#include "ASTExpr.h"

/*! \brief Class for if-then-else.
 */
class ASTForStmt : public ASTStmt {
  std::shared_ptr<ASTExpr> START, END, BEGIN, STEP;
  std::shared_ptr<ASTStmt> DO;
public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTIfStmt(std::unique_ptr<ASTExpr> START, std::unique_ptr<ASTExpr> END,
          std::unique_ptr<ASTExpr> BEGIN, std::unique_ptr<ASTExpr> STEP,
          std::unique_ptr<ASTStmt> DO)
      : START(std::move(START)), END(std::move(END)), BEGIN(std::move(BEGIN), STEP(std::move(STEP), DO(std::move(DO)) {}
  ASTExpr* getStart() const { return START.get(); }
  ASTExpr* getEnd() const { return END.get(); }
  ASTExpr* getBegin() const { return BEGIN.get(); }
  
  /* getStep
   * return Step value if it exists and nullptr otherwise.
   */
  ASTExpr* getStep() const { return STEP.get(); }
  ASTStmt* getDo() const { return DO.get(); }
  
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
