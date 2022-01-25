#include <iostream>
#include <vector>
#include <algorithm>

struct Interval{
    int index;
    float start;
    float end;
    bool operator < (const Interval& i) const { return (end < i.end); }
};

std::vector<int> cover(Interval intervalTC, std::vector<Interval> *intervals){
    for (auto a : *intervals){
        std::cout << "Start: " << a.start << "end "<< a.end << std::endl;
    }
    std::sort(intervals->begin(), intervals->end());
    for (auto a : *intervals){
        std::cout << "Start: " << a.start << "end "<< a.end << std::endl;
    }

    std::vector<int> cover;
    float covered = intervalTC.start;

    while (covered < intervalTC.end || intervalTC.end == intervalTC.start){
        int indexTF = -1;
        for (int i = intervals->size()-1; i >= 0; i--) {
            if (covered > intervals->at(i).end) {
                // Since sorted we know no more possible coverings
                return std::vector<int>();
            }
            if (covered < intervals->at(i).start) {
                continue; //Interval not covering beginning
            }
            indexTF = i;
            covered = intervals->at(i).end;
            break;
        }
        if (indexTF != -1) {
            cover.push_back(intervals->at(indexTF).index);
            intervals->erase(intervals->begin()+indexTF);
        }else{
            return std::vector<int>();
        }
        if (intervalTC.end == intervalTC.start) {
            break;
        }
    }
    if (covered < intervalTC.end){
        return std::vector<int>();
    }

    return cover;
}

int main(void) {
    float start,end;
    while(std::cin >> start >> end){
        struct Interval intervalTC = {0, start, end};

        std::vector<Interval> intervals;
        int n;
        std::cin >> n;
        for (int j = 0; j < n; j++){
            float start,end;
            std::cin >> start >> end;
            struct Interval interval = {j, start, end};
            intervals.push_back(interval);
        }

        std::vector<int> output;
        output = cover(intervalTC, &intervals);

        if (output.empty()) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << output.size() << std::endl;
            for (auto a : output){
                std::cout << a << " ";
            }
            std::cout << std::endl;

        }
    }
}

