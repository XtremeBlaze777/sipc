#include "TipArr.h"
#include "TipTypeVisitor.h"

#include <sstream>
TipArr::TipArr() { }

TipArr::TipArr(std::vector<std::shared_ptr<TipType>> params): TipCons(std::move(params)) { }

TipArr::TipArr(std::shared_ptr<TipInt> num, std::shared_ptr<TipType> expr) { 
    std::vector<std::shared_ptr<TipType>> elems;
    for (int i = 0; i < n; i++) {
        elems.push_back(expr);
    }
    

} 

std::vector<std::shared_ptr<TipType>> TipArr::getElems() const {
    std::vector<std::shared_ptr<TipType>> elems(arguments.begin(), arguments.end());
    return elems;
}

std::ostream &TipArr::print(std::ostream &out) const {
    out << "[";
    int end_of_args = arguments.size() - 1;
    for(int i = 0; i < end_of_args; i++) {
        out << *arguments.at(i) << ", ";
    }
    out << *arguments.back();
    return out;
}

bool TipArr::operator==(const TipType &other) const {
    auto otherTipArr = dynamic_cast<const TipArr *>(&other);
    if(!otherTipArr) {
        return false;
    }

    if(arguments.size() != otherTipArr->arguments.size()) {
        return false;
    }

    for(int i = 0; i < arguments.size(); i++) {
        if(*(arguments.at(i)) != *(otherTipArr->arguments.at(i))) {
            return false;
        }
    }
    
    return true;
}

bool TipArr::operator!=(const TipType &other) const {
    return !(*this == other);
}

void TipArr::accept(TipTypeVisitor * visitor) {
  if (visitor->visit(this)) {
    for (auto a : arguments) {
       a->accept(visitor);
    }
  }
  visitor->endVisit(this);
}
