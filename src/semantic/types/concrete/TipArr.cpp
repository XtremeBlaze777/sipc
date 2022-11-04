#include "TipArr.h"
#include "TipTypeVisitor.h"

#include <sstream>

TipArr::TipArr(std::vector<std::shared_ptr<TipType>> elems): TipCons(std::move(elems)) { }

std::vector<std::shared_ptr<TipType>> TipArr::getElems() const {
    std::vector<std::shared_ptr<TipType>> elems(arguments.begin(), arguments.end());
    return elems;
}

std::ostream &TipArr::print(std::ostream &out) const {   
    out << "(arr::" << *(arguments.front()) << ")";
    return out;
}

bool TipArr::operator==(const TipType &other) const {
    auto otherTipArr = dynamic_cast<const TipArr *>(&other);
    if(!otherTipArr) {
        return false;
    }

    // Empty array case
    if (*(arguments.size()) == 0 || *(otherTipArr->size()) == 0) {
        if (*(arguments.size()) != *(otherTipArr->size())) {
            return false;
        } else {
            return true;
        }
    }

    if(*(arguments.at(0)) != *(otherTipArr->arguments.at(0))) {
        return false;
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
