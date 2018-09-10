#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>
#include <iterator>


template<class BiIterator>
void demoIteratorTags(BiIterator beg, BiIterator end, std::bidirectional_iterator_tag)
{
	std::cout << "demoIteratorTags(BiIterator beg, BiIterator end, std::bidirectional_iterator_tag)" << std::endl;
}

template<class RaIterator>
void demoIteratorTags(RaIterator beg, RaIterator end, std::random_access_iterator_tag)
{
	std::cout << "demoIteratorTags(RaIterator beg, RaIterator end, std::random_access_iterator_tag)" << std::endl;
}
template<class ForwardIterator>
void demoIteratorTags(ForwardIterator beg, ForwardIterator end, std::forward_iterator_tag)
{
	std::cout << "demoIteratorTags(ForwardIterator beg, ForwardIterator end, std::forward_iterator_tag)" << std::endl;
}
template <class Iterator>
inline void demoIteratorTags(Iterator beg, Iterator end)
{
	demoIteratorTags(beg, end, typename std::iterator_traits<Iterator>::iterator_category());
}



template <class Iter>
inline
typename std::iterator_traits<Iter>::difference_type
myDistance(Iter beg, Iter end, std::random_access_iterator_tag ){
    return end - beg;
}

template <class Iter>
inline
typename std::iterator_traits<Iter>::difference_type
myDistance(Iter beg, Iter end, std::forward_iterator_tag ){
    
    typedef typename std::iterator_traits<Iter>::difference_type DiffType;
    
    DiffType retVal = DiffType();
    for(;beg != end; ++beg)
        ++retVal;     
    return retVal;
}
template <class Iter>
inline
typename std::iterator_traits<Iter>::difference_type
myDistance(Iter beg, Iter end){
    return myDistance(
                beg,
                end,
                typename std::iterator_traits<Iter>::iterator_category());
}

#endif //TEMPLATES_H
