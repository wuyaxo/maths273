//
// Created by David on 4/25/24.
//

#ifndef MERGE_SORT_ALGORITHM_MERGE_SORT_H
#define MERGE_SORT_ALGORITHM_MERGE_SORT_H

template<class Iter>
void merge_sort(Iter first, Iter last) {
    if (last - first > 1) {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

#endif //MERGE_SORT_ALGORITHM_MERGE_SORT_H
