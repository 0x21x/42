#include "PMergeMe.hpp"

std::string printArray(char **arr) {
    std::string s;
    for (int i = 0; arr[i]; i++){
        s += ' ';
        s += arr[i];
    }
    return s;
}

template<typename C>
std::string printContainers(C & container) {
    if (container.empty())
        return "Error";

    std::string s;
    typename C::iterator it = container.begin();
    for (; it < container.end(); it++)
        s += ' ' + std::to_string(*it);
    return s;
}

template<typename C> // only std::vector<std::pair> and std::deque<std::pair> compatible
C parse(char **arr){
    C container;
    for(int i = 0; arr[i]; i++){
        if (arr[i] && arr[i+1]) {
            container.push_back(std::make_pair(std::stoi(arr[i]), std::stoi(arr[i+1])));
            i++;
        }
        else
            container.push_back(std::make_pair(std::stoi(arr[i]), 0));
    }
    return container;
}

void swap(std::pair<unsigned int, unsigned int> & pair) {
    if (pair.first > pair.second)
        std::swap(pair.first, pair.second);
}

template<typename C, typename O>
O extractFirst(C& c) {
    O container;
    for (typename C::iterator it = c.begin(); it < c.end(); it++)
        container.push_back((*it).first);
    return container;
}

template<typename C, typename O>
O extractSecond(C& c, bool odd) {
    O container;
    for (typename C::iterator it = c.begin(); it < c.end(); it++) {
        if (it == c.end() - 1 && odd)
            return container;
        container.push_back((*it).second);
    }
    return container;
}

template<typename C>
void insertionSort(C& c, unsigned int remain) {
    if (remain <= 1)
        return ;

    typename C::iterator current = c.begin() + remain - 1;
    typename C::iterator biggest = std::max_element(c.begin(), current);
    if (*biggest > *current){
        unsigned int value = *biggest;
        c.erase(biggest);
        c.insert(current, value);
    }
    insertionSort(c, remain - 1);
}

template<typename C>
void insertion(C& destination, C& origin) {
    if (origin.empty())
        return ;

    for (typename C::iterator it = origin.begin(); it < origin.end(); it++) {
        typename C::iterator pos = std::upper_bound(destination.begin(), destination.end(), *it);
        
        destination.insert(pos, *it);
    }
}

template<typename C, typename O>
O algo(C& c, bool odd, std::chrono::nanoseconds &elapsedTime){

    std::chrono::steady_clock::time_point   start, end;
    start = std::chrono::steady_clock::now();

    // sort all pairs
    for (typename C::iterator it = c.begin(); it < c.end() - 1 || (it == c.end() - 1 && !odd); it++)
        swap(*it);

    // separate all pairs by largest elements in two stack
    O c1 = extractFirst<C, O>(c);
    O c2 = extractSecond<C, O>(c, odd);
    // sort the biggest stack with a Recursive Insertion Sort Algorythm
    insertionSort(c2, c2.size());
    // insert smallest stack in biggest stack
    insertion(c2, c1);

    end = std::chrono::steady_clock::now();
    elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    return c2;
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: Wrong numbers of arguments.";
        return 1;
    }

    try {
         std::chrono::nanoseconds vectorTime, dequeTime;
        PMergeMe pMergeMe;
        pMergeMe.checkArg(&av[1]);
        if ((ac - 1) % 2)
            pMergeMe.odd = true;
        std::cout << "Before:" << printArray(&av[1]) << std::endl;
        std::vector<std::pair<unsigned int, unsigned int> > vec = parse<std::vector<std::pair<unsigned int, unsigned int> > >(&av[1]);
        std::vector<unsigned int> vecSorted = algo<std::vector<std::pair<unsigned int, unsigned int> >, std::vector<unsigned int> >(vec, pMergeMe.odd, vectorTime);
        std::cout << "After :"<< printContainers(vecSorted) << std::endl;
        std::deque<std::pair<unsigned int, unsigned int> > deque = parse<std::deque<std::pair<unsigned int, unsigned int> > >(&av[1]);
        std::deque<unsigned int> dequeSorted = algo<std::deque<std::pair<unsigned int, unsigned int> >, std::deque<unsigned int> >(deque, pMergeMe.odd, dequeTime);
        std::cout << "Time to process a range of " << std::to_string(ac - 1) << " elements with std::vector : ";
        std::cout << static_cast<double>(vectorTime.count()) / 100 << " µs" << std::endl;
        std::cout << "Time to process a range of " << std::to_string(ac - 1) << " elements with std::deque : ";
        std::cout << static_cast<double>(dequeTime.count()) / 100 << " µs" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
